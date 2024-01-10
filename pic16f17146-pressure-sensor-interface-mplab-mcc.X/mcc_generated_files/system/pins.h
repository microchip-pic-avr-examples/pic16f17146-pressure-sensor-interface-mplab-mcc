/**
 * Generated Pins header File
 * 
 * @file pins.h
 * 
 * @defgroup  pinsdriver Pins Driver
 * 
 * @brief This is generated driver header for pins. 
 *        This header file provides APIs for all pins selected in the GUI.
 *
 * @version Driver Version  3.0.0
*/

/*
© [2024] Microchip Technology Inc. and its subsidiaries.

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

#ifndef PINS_H
#define PINS_H

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set IO_RA2 aliases
#define DAC1OUT_TRIS                 TRISAbits.TRISA2
#define DAC1OUT_LAT                  LATAbits.LATA2
#define DAC1OUT_PORT                 PORTAbits.RA2
#define DAC1OUT_WPU                  WPUAbits.WPUA2
#define DAC1OUT_OD                   ODCONAbits.ODCA2
#define DAC1OUT_ANS                  ANSELAbits.ANSA2
#define DAC1OUT_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define DAC1OUT_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define DAC1OUT_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define DAC1OUT_GetValue()           PORTAbits.RA2
#define DAC1OUT_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define DAC1OUT_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define DAC1OUT_SetPullup()          do { WPUAbits.WPUA2 = 1; } while(0)
#define DAC1OUT_ResetPullup()        do { WPUAbits.WPUA2 = 0; } while(0)
#define DAC1OUT_SetPushPull()        do { ODCONAbits.ODCA2 = 0; } while(0)
#define DAC1OUT_SetOpenDrain()       do { ODCONAbits.ODCA2 = 1; } while(0)
#define DAC1OUT_SetAnalogMode()      do { ANSELAbits.ANSA2 = 1; } while(0)
#define DAC1OUT_SetDigitalMode()     do { ANSELAbits.ANSA2 = 0; } while(0)
// get/set IO_RA4 aliases
#define CurrentP_TRIS                 TRISAbits.TRISA4
#define CurrentP_LAT                  LATAbits.LATA4
#define CurrentP_PORT                 PORTAbits.RA4
#define CurrentP_WPU                  WPUAbits.WPUA4
#define CurrentP_OD                   ODCONAbits.ODCA4
#define CurrentP_ANS                  ANSELAbits.ANSA4
#define CurrentP_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define CurrentP_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define CurrentP_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define CurrentP_GetValue()           PORTAbits.RA4
#define CurrentP_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define CurrentP_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define CurrentP_SetPullup()          do { WPUAbits.WPUA4 = 1; } while(0)
#define CurrentP_ResetPullup()        do { WPUAbits.WPUA4 = 0; } while(0)
#define CurrentP_SetPushPull()        do { ODCONAbits.ODCA4 = 0; } while(0)
#define CurrentP_SetOpenDrain()       do { ODCONAbits.ODCA4 = 1; } while(0)
#define CurrentP_SetAnalogMode()      do { ANSELAbits.ANSA4 = 1; } while(0)
#define CurrentP_SetDigitalMode()     do { ANSELAbits.ANSA4 = 0; } while(0)
// get/set IO_RB4 aliases
#define OPA_N_IN_TRIS                 TRISBbits.TRISB4
#define OPA_N_IN_LAT                  LATBbits.LATB4
#define OPA_N_IN_PORT                 PORTBbits.RB4
#define OPA_N_IN_WPU                  WPUBbits.WPUB4
#define OPA_N_IN_OD                   ODCONBbits.ODCB4
#define OPA_N_IN_ANS                  ANSELBbits.ANSB4
#define OPA_N_IN_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define OPA_N_IN_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define OPA_N_IN_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define OPA_N_IN_GetValue()           PORTBbits.RB4
#define OPA_N_IN_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define OPA_N_IN_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define OPA_N_IN_SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define OPA_N_IN_ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define OPA_N_IN_SetPushPull()        do { ODCONBbits.ODCB4 = 0; } while(0)
#define OPA_N_IN_SetOpenDrain()       do { ODCONBbits.ODCB4 = 1; } while(0)
#define OPA_N_IN_SetAnalogMode()      do { ANSELBbits.ANSB4 = 1; } while(0)
#define OPA_N_IN_SetDigitalMode()     do { ANSELBbits.ANSB4 = 0; } while(0)
// get/set IO_RB7 aliases
#define UART_TX1_TRIS                 TRISBbits.TRISB7
#define UART_TX1_LAT                  LATBbits.LATB7
#define UART_TX1_PORT                 PORTBbits.RB7
#define UART_TX1_WPU                  WPUBbits.WPUB7
#define UART_TX1_OD                   ODCONBbits.ODCB7
#define UART_TX1_ANS                  ANSELBbits.ANSB7
#define UART_TX1_SetHigh()            do { LATBbits.LATB7 = 1; } while(0)
#define UART_TX1_SetLow()             do { LATBbits.LATB7 = 0; } while(0)
#define UART_TX1_Toggle()             do { LATBbits.LATB7 = ~LATBbits.LATB7; } while(0)
#define UART_TX1_GetValue()           PORTBbits.RB7
#define UART_TX1_SetDigitalInput()    do { TRISBbits.TRISB7 = 1; } while(0)
#define UART_TX1_SetDigitalOutput()   do { TRISBbits.TRISB7 = 0; } while(0)
#define UART_TX1_SetPullup()          do { WPUBbits.WPUB7 = 1; } while(0)
#define UART_TX1_ResetPullup()        do { WPUBbits.WPUB7 = 0; } while(0)
#define UART_TX1_SetPushPull()        do { ODCONBbits.ODCB7 = 0; } while(0)
#define UART_TX1_SetOpenDrain()       do { ODCONBbits.ODCB7 = 1; } while(0)
#define UART_TX1_SetAnalogMode()      do { ANSELBbits.ANSB7 = 1; } while(0)
#define UART_TX1_SetDigitalMode()     do { ANSELBbits.ANSB7 = 0; } while(0)
// get/set IO_RC1 aliases
#define LED_D7_TRIS                 TRISCbits.TRISC1
#define LED_D7_LAT                  LATCbits.LATC1
#define LED_D7_PORT                 PORTCbits.RC1
#define LED_D7_WPU                  WPUCbits.WPUC1
#define LED_D7_OD                   ODCONCbits.ODCC1
#define LED_D7_ANS                  ANSELCbits.ANSC1
#define LED_D7_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define LED_D7_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define LED_D7_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define LED_D7_GetValue()           PORTCbits.RC1
#define LED_D7_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define LED_D7_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define LED_D7_SetPullup()          do { WPUCbits.WPUC1 = 1; } while(0)
#define LED_D7_ResetPullup()        do { WPUCbits.WPUC1 = 0; } while(0)
#define LED_D7_SetPushPull()        do { ODCONCbits.ODCC1 = 0; } while(0)
#define LED_D7_SetOpenDrain()       do { ODCONCbits.ODCC1 = 1; } while(0)
#define LED_D7_SetAnalogMode()      do { ANSELCbits.ANSC1 = 1; } while(0)
#define LED_D7_SetDigitalMode()     do { ANSELCbits.ANSC1 = 0; } while(0)
// get/set IO_RC2 aliases
#define OPA_OUT_TRIS                 TRISCbits.TRISC2
#define OPA_OUT_LAT                  LATCbits.LATC2
#define OPA_OUT_PORT                 PORTCbits.RC2
#define OPA_OUT_WPU                  WPUCbits.WPUC2
#define OPA_OUT_OD                   ODCONCbits.ODCC2
#define OPA_OUT_ANS                  ANSELCbits.ANSC2
#define OPA_OUT_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define OPA_OUT_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define OPA_OUT_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define OPA_OUT_GetValue()           PORTCbits.RC2
#define OPA_OUT_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define OPA_OUT_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define OPA_OUT_SetPullup()          do { WPUCbits.WPUC2 = 1; } while(0)
#define OPA_OUT_ResetPullup()        do { WPUCbits.WPUC2 = 0; } while(0)
#define OPA_OUT_SetPushPull()        do { ODCONCbits.ODCC2 = 0; } while(0)
#define OPA_OUT_SetOpenDrain()       do { ODCONCbits.ODCC2 = 1; } while(0)
#define OPA_OUT_SetAnalogMode()      do { ANSELCbits.ANSC2 = 1; } while(0)
#define OPA_OUT_SetDigitalMode()     do { ANSELCbits.ANSC2 = 0; } while(0)
// get/set IO_RC3 aliases
#define OPA_P_IN_TRIS                 TRISCbits.TRISC3
#define OPA_P_IN_LAT                  LATCbits.LATC3
#define OPA_P_IN_PORT                 PORTCbits.RC3
#define OPA_P_IN_WPU                  WPUCbits.WPUC3
#define OPA_P_IN_OD                   ODCONCbits.ODCC3
#define OPA_P_IN_ANS                  ANSELCbits.ANSC3
#define OPA_P_IN_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define OPA_P_IN_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define OPA_P_IN_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define OPA_P_IN_GetValue()           PORTCbits.RC3
#define OPA_P_IN_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define OPA_P_IN_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define OPA_P_IN_SetPullup()          do { WPUCbits.WPUC3 = 1; } while(0)
#define OPA_P_IN_ResetPullup()        do { WPUCbits.WPUC3 = 0; } while(0)
#define OPA_P_IN_SetPushPull()        do { ODCONCbits.ODCC3 = 0; } while(0)
#define OPA_P_IN_SetOpenDrain()       do { ODCONCbits.ODCC3 = 1; } while(0)
#define OPA_P_IN_SetAnalogMode()      do { ANSELCbits.ANSC3 = 1; } while(0)
#define OPA_P_IN_SetDigitalMode()     do { ANSELCbits.ANSC3 = 0; } while(0)
// get/set IO_RC6 aliases
#define PressureN_TRIS                 TRISCbits.TRISC6
#define PressureN_LAT                  LATCbits.LATC6
#define PressureN_PORT                 PORTCbits.RC6
#define PressureN_WPU                  WPUCbits.WPUC6
#define PressureN_OD                   ODCONCbits.ODCC6
#define PressureN_ANS                  ANSELCbits.ANSC6
#define PressureN_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define PressureN_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define PressureN_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define PressureN_GetValue()           PORTCbits.RC6
#define PressureN_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define PressureN_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define PressureN_SetPullup()          do { WPUCbits.WPUC6 = 1; } while(0)
#define PressureN_ResetPullup()        do { WPUCbits.WPUC6 = 0; } while(0)
#define PressureN_SetPushPull()        do { ODCONCbits.ODCC6 = 0; } while(0)
#define PressureN_SetOpenDrain()       do { ODCONCbits.ODCC6 = 1; } while(0)
#define PressureN_SetAnalogMode()      do { ANSELCbits.ANSC6 = 1; } while(0)
#define PressureN_SetDigitalMode()     do { ANSELCbits.ANSC6 = 0; } while(0)
/**
 * @ingroup  pinsdriver
 * @brief GPIO and peripheral I/O initialization
 * @param none
 * @return none
 */
void PIN_MANAGER_Initialize (void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt on Change Handling routine
 * @param none
 * @return none
 */
void PIN_MANAGER_IOC(void);


#endif // PINS_H
/**
 End of File
*/