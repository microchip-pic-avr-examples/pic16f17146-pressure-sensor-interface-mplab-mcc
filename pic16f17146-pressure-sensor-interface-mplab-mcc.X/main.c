 /*
 * MAIN Generated Driver File
 * 
 * @file main.c
 * 
 * @defgroup main MAIN
 * 
 * @brief This is the generated driver implementation file for the MAIN driver.
 *
 * @version MAIN Driver Version 1.0.0
*/

/*
© [2022] Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip 
    software and any derivatives exclusively with Microchip products. 
    You are responsible for complying with 3rd party license terms  
    applicable to your use of 3rd party software (including open source  
    software) that may accompany Microchip software. SOFTWARE IS ?AS IS.? 
    NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS 
    SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,  
    MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT 
    WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY 
    KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF 
    MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE 
    FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP?S 
    TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE WILL NOT 
    EXCEED AMOUNT OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR 
    THIS SOFTWARE.
*/
#include "mcc_generated_files/system/system.h"

/*----------------------------------------------------------------------------
 *  Macro definitions
 *----------------------------------------------------------------------------
 */

/*
 Pressure Sensor Related Equations
 * pressureSensoeOutput in mV = 0.84*pressureInKpa-2.25 // Equation described from Sensor datasheet graph
 * pressureInKpa =( 2.25+ pressureSensoeOutput)/0.84
 * pressureInKpa = 2.97+pressureSensoeOutput*1.19
 * pressureInKpa = (2.97+(mVReadByADCC/OPAGain)*1.19)  ---- OPAGain is ~55 (820K/15K)
 * pressureInKpa=3+0.0216*ADCCmV                       ---- 2.97 ~3
 */

#define ADCC_TO_mVOLT_MULTIPLIER        (1.0F)    //ADC Gain for Current measurement 2048 (mV)/2048(Resolution Count for 11 bit)
#define ADCC_PRESSURE_CONVERSION_SLOPE  (0.0216F) //Gain for Pressure measurement (includes OPA gain and ADC conversion gain); see equation
#define ADCC_PRESSURE_CONVERSION_OFFSET (3.0F)    // see euation  (~2.97 becomes 3))
#define SHUNT_RES                       (2.0F)    // Shunt resistor value in KOhm
#define SHUNT_VOLT                      (SHUNT_RES*100)  // voltage (mV) accross SHUNT_RES res when a 100 uA current is flowing
#define PRESSURE_PERCENTAGE_MULTIPLIER  (2.7F)    // 100/37(Pressure in Kpa)
#define MAX_PRESSURE_KPA                (37)      // MAximum Rated pressure measurement by sensor
#define MIN_PRESSURE_KPA                (0)       // Minimum rated pressure measurement by Sensor
#define PRESSURE_SENSOR_OUTPUT_OFFSET   (85)      // 1.5 mV max; hence after OPA gain OPA_Gain * 1.5 mV*ADCC_TO_mVOLT_MULTIPLIER; ie 55*1.5*1 = ~85
#define DAC_VALUE_LOWER_LIMIT           (150U)    // The DAC value which results circuit current below ~90 uA for 3.3 V Vref and 22K circuit impedence
#define DAC_VALUE_UPPER_LIMIT           (190U)    // The DAC value which results circuit current above ~110 uA for 3.3 V Vref and 22K circuit impedence

#define DAC_VREF                        (3300.0F) //3300 mV
#define DAC_1_COUNT_RESOLUTION          (DAC_VREF/256)//8bit DAC = 256; value is 12.89 mV
#define ERROR_LIMIT_FOR_CURRENT_SET     (1.0F)    // 1 count of DAC is changing less than 1 uA current in the circuit; DAC_1_COUNT_RESOLUTION/22K = ~0.58 uA;22 K is total res of circuit

#define DV_GRAPH                                // Uncomment this line to draw graph over Data Visualizer and set uint8_t val in DV

#ifdef DV_GRAPH
#define TMR0_RATE                       (1)      // update DV value in n ms
#else
#define TMR0_RATE                       (500)// print message over terminal in n ms
//#define DEBUG_PRESSURE                     // Uncomment this line to see pressure ADC count messages 
//#define DEBUG_PRESSURE_PERCENTAGE          // Uncomment this line to see pressure value messages 
//#define DEBUG_DAC_CURRENT                  // Uncomment this line to see shunt res ADC count and error messages 
#endif
/*----------------------------------------------------------------------------
 *  Prototypes
 *----------------------------------------------------------------------------*/

static void FSM_Scheduler(void);
static void SetSensorCurrent(void);
static void ReadSensorValue(void);


/*----------------------------------------------------------------------------
 *  Global Variables
 *----------------------------------------------------------------------------*/

static bool hardwareErrorFlag = false;
static volatile bool fsmFlag = false;
static uint8_t dacValue = DAC_VALUE_LOWER_LIMIT;//DAC register output value to be adjusted for 100uA current


/*
                         Main application
 */
void main(void)
{
    // initialize the device
    SYSTEM_Initialize();
    
    //Set the default interrupt handler for TMR0
    Timer0_OverflowCallbackRegister(FSM_Scheduler);
    
    // When using interrupts, you need to set the Global and Peripheral Interrupt Enable bits
    // Use the following macros to:
    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();
    
    printf("Start \r\n");
    
    //Enable DAC output with initial value
    DAC1_SetOutput(dacValue);
#ifdef DEBUG_DAC_CURRENT
    printf("dacValue: %d \n", dacValue);
    printf("DAC Vol: %.2f \n", dacValue * DAC_1_COUNT_RESOLUTION );
#endif 
    
    while (1)
    {
        if(fsmFlag)
        {
            fsmFlag = false;
            //Call a function for sensor current adjustment
            SetSensorCurrent();
            //If there is no hardware error, measure sensor data
            if(!hardwareErrorFlag)
            {
                ReadSensorValue();
            }
            else
            {
#ifdef DV_GRAPH
                while(!UART1.IsTxReady());
                UART1.Write(0x5F);//start frame for DV is 0x5F
                while(!UART1.IsTxReady());
                UART1.Write(100);//Max Value ; ie 100% in case of error during DV
                while(!UART1.IsTxReady());
                UART1.Write(0xA0);//End frame for DV is 0xA0
#else
                printf("Hardware Connection Error \r\n");
#endif
            }            
        }
        
    }
}


/*============================================================================
void SetSensorCurrent(void)
------------------------------------------------------------------------------
Purpose: This function is called to provide 100uA as sensor excitation current
Input  : none
Output : none
Notes  : This function uses ADC measurement of DAC current for closed loop 
         control system
============================================================================*/
static void SetSensorCurrent(void)
{
    adc_result_t adcResult = 0;
    float shuntVoltError = 0.0;
    float shuntCurrentError = 0.0;
    bool currentSetFlag = false;
    
    hardwareErrorFlag = false;
    
    do
    {
        //Read ADC voltage across shunt res (2K) for circuit current and calculate error
        PIR6bits.ADTIF = 0;
        ADCC_StartConversion(CurrentP,nChannel_VSS);
        while (!PIR6bits.ADTIF);
        PIR6bits.ADTIF = 0;
        adcResult = ADCC_GetFilterValue();
        
#ifdef DEBUG_DAC_CURRENT
        printf("Shunt Res ADC count: %d \n", adcResult);
#endif       
        shuntVoltError = SHUNT_VOLT - (adcResult * ADCC_TO_mVOLT_MULTIPLIER);
        shuntCurrentError = shuntVoltError/SHUNT_RES;
#ifdef DEBUG_DAC_CURRENT
        printf("Error in Current: %.2f \n", shuntCurrentError);
#endif        
        //Adjust the DAC value if error is more than 1uA; i.e.; circuit current is less than 99 or greater than 101 uA
        if((shuntCurrentError < (ERROR_LIMIT_FOR_CURRENT_SET))&&(shuntCurrentError > (-ERROR_LIMIT_FOR_CURRENT_SET)))
        {
            currentSetFlag = true;
        }
        else
        {
            currentSetFlag = false;
            dacValue += (uint8_t) (shuntCurrentError/ERROR_LIMIT_FOR_CURRENT_SET);
            
            //If DAC is hitting maximum or minimum generate hardware error
            if(dacValue < DAC_VALUE_LOWER_LIMIT) 
            {
                dacValue = DAC_VALUE_LOWER_LIMIT;
                hardwareErrorFlag = true;
                break;
            }
            else if(dacValue > DAC_VALUE_UPPER_LIMIT) 
            {
                dacValue = DAC_VALUE_UPPER_LIMIT;
                hardwareErrorFlag = true;
                break;
            }
            
            DAC1_SetOutput(dacValue);
#ifdef DEBUG_DAC_CURRENT
            printf("dacValue: %d \n", dacValue);
            printf("DAC Vol: %d \n", dacValue * 13);
#endif           
            //Add delay for current stabilization in Sensor
            // settling time for DAC is 10 uS; wait for minimum 10 us  
            __delay_ms(1);
        }
    }while(!currentSetFlag);
}


/*============================================================================
void ReadSensorValue(void)
------------------------------------------------------------------------------
Purpose: This function is called to read the pressure sensor output via ADC
Input  : none
Output : none
Notes  : The ADC output is processed to show the pressure in % of full range
============================================================================*/
static void ReadSensorValue(void)
{
    int16_t adcResult = 0;
    float percentage = 0.0F;
    float pressureInKpa = 0.0F;
    
    PIR6bits.ADTIF = 0;
    ADCC_StartConversion(PressureP,PressureN);
    while (!PIR6bits.ADTIF);
    PIR6bits.ADTIF = 0;
    adcResult = ADCC_GetFilterValue();
    
#ifdef DEBUG_PRESSURE
        printf("adcResult: %d \n", adcResult);
#endif     
    adcResult = adcResult - PRESSURE_SENSOR_OUTPUT_OFFSET; 
    adcResult =(adc_result_t) (adcResult * ADCC_TO_mVOLT_MULTIPLIER); 
    pressureInKpa = adcResult * ADCC_PRESSURE_CONVERSION_SLOPE + ADCC_PRESSURE_CONVERSION_OFFSET;// see equation
#ifdef DEBUG_PRESSURE_PERCENTAGE
        printf("pressureInKpa: %.2f \n", pressureInKpa);
#endif   
    if(pressureInKpa < MIN_PRESSURE_KPA)
    {
        pressureInKpa = (float)MIN_PRESSURE_KPA;
    }
    if(pressureInKpa > MAX_PRESSURE_KPA)
    {
        pressureInKpa= (float)MAX_PRESSURE_KPA;
    }
    //Calculate pressure percentage by assuming 37KPa as 100%; a multiplier of (100 /37)~ 2.7
    percentage = pressureInKpa * PRESSURE_PERCENTAGE_MULTIPLIER;
    
    //print pressure percentage
    
#ifdef DV_GRAPH
    while(!UART1.IsTxReady());
    UART1.Write(0x5F);//start frame for DV is 0x5F
    while(!UART1.IsTxReady());
    UART1.Write((uint8_t)percentage);
    while(!UART1.IsTxReady());
    UART1.Write(0xA0);//End frame for DV is 0xA0
#else
    printf("Pressure %d %%\n\n", (int16_t)percentage);
#endif
}


/*============================================================================
void FSMScheduler(void)
------------------------------------------------------------------------------
Purpose: This is the user interrupt handler for TMR0 overflow interrupt 
Input  : none
Output : none
Notes  : 
============================================================================*/
static void FSM_Scheduler(void)
{ 
    static uint16_t timeCounter;
    
    timeCounter++;
    if(timeCounter >= TMR0_RATE)
    {
        LED_D7_Toggle();
        fsmFlag = true;
        timeCounter = 0;
    }
}

/**
 End of File
*/