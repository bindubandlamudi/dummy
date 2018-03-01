/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using MPLAB(c) Code Configurator

  @Description:
    This header file provides implementations for pin APIs for all pins selected in the GUI.
    Generation Information :
        Product Revision  :  MPLAB(c) Code Configurator - 4.35
        Device            :  PIC16F18875
        Version           :  1.01
    The generated drivers are tested against the following:
        Compiler          :  XC8 1.35
        MPLAB             :  MPLAB X 3.40

    Copyright (c) 2013 - 2015 released Microchip Technology Inc.  All rights reserved.

    Microchip licenses to you the right to use, modify, copy and distribute
    Software only when embedded on a Microchip microcontroller or digital signal
    controller that is integrated into your product or third party product
    (pursuant to the sublicense terms in the accompanying license agreement).

    You should refer to the license agreement accompanying this Software for
    additional information regarding your rights and obligations.

    SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
    EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
    MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
    IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
    CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
    OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
    INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
    CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
    SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
    (INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.

*/


#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set BLE2_Conn aliases
#define BLE2_Conn_TRIS               TRISAbits.TRISA1
#define BLE2_Conn_LAT                LATAbits.LATA1
#define BLE2_Conn_PORT               PORTAbits.RA1
#define BLE2_Conn_WPU                WPUAbits.WPUA1
#define BLE2_Conn_OD                ODCONAbits.ODCA1
#define BLE2_Conn_ANS                ANSELAbits.ANSA1
#define BLE2_Conn_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define BLE2_Conn_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define BLE2_Conn_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define BLE2_Conn_GetValue()           PORTAbits.RA1
#define BLE2_Conn_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define BLE2_Conn_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define BLE2_Conn_SetPullup()      do { WPUAbits.WPUA1 = 1; } while(0)
#define BLE2_Conn_ResetPullup()    do { WPUAbits.WPUA1 = 0; } while(0)
#define BLE2_Conn_SetPushPull()    do { ODCONAbits.ODCA1 = 0; } while(0)
#define BLE2_Conn_SetOpenDrain()   do { ODCONAbits.ODCA1 = 1; } while(0)
#define BLE2_Conn_SetAnalogMode()  do { ANSELAbits.ANSA1 = 1; } while(0)
#define BLE2_Conn_SetDigitalMode() do { ANSELAbits.ANSA1 = 0; } while(0)

// get/set BLE2_Cmd_Mldp aliases
#define BLE2_Cmd_Mldp_TRIS               TRISCbits.TRISC2
#define BLE2_Cmd_Mldp_LAT                LATCbits.LATC2
#define BLE2_Cmd_Mldp_PORT               PORTCbits.RC2
#define BLE2_Cmd_Mldp_WPU                WPUCbits.WPUC2
#define BLE2_Cmd_Mldp_OD                ODCONCbits.ODCC2
#define BLE2_Cmd_Mldp_ANS                ANSELCbits.ANSC2
#define BLE2_Cmd_Mldp_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define BLE2_Cmd_Mldp_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define BLE2_Cmd_Mldp_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define BLE2_Cmd_Mldp_GetValue()           PORTCbits.RC2
#define BLE2_Cmd_Mldp_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define BLE2_Cmd_Mldp_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define BLE2_Cmd_Mldp_SetPullup()      do { WPUCbits.WPUC2 = 1; } while(0)
#define BLE2_Cmd_Mldp_ResetPullup()    do { WPUCbits.WPUC2 = 0; } while(0)
#define BLE2_Cmd_Mldp_SetPushPull()    do { ODCONCbits.ODCC2 = 0; } while(0)
#define BLE2_Cmd_Mldp_SetOpenDrain()   do { ODCONCbits.ODCC2 = 1; } while(0)
#define BLE2_Cmd_Mldp_SetAnalogMode()  do { ANSELCbits.ANSC2 = 1; } while(0)
#define BLE2_Cmd_Mldp_SetDigitalMode() do { ANSELCbits.ANSC2 = 0; } while(0)

// get/set RC6 procedures
#define RC6_SetHigh()    do { LATCbits.LATC6 = 1; } while(0)
#define RC6_SetLow()   do { LATCbits.LATC6 = 0; } while(0)
#define RC6_Toggle()   do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define RC6_GetValue()         PORTCbits.RC6
#define RC6_SetDigitalInput()   do { TRISCbits.TRISC6 = 1; } while(0)
#define RC6_SetDigitalOutput()  do { TRISCbits.TRISC6 = 0; } while(0)
#define RC6_SetPullup()     do { WPUCbits.WPUC6 = 1; } while(0)
#define RC6_ResetPullup()   do { WPUCbits.WPUC6 = 0; } while(0)
#define RC6_SetAnalogMode() do { ANSELCbits.ANSC6 = 1; } while(0)
#define RC6_SetDigitalMode()do { ANSELCbits.ANSC6 = 0; } while(0)

// get/set RC7 procedures
#define RC7_SetHigh()    do { LATCbits.LATC7 = 1; } while(0)
#define RC7_SetLow()   do { LATCbits.LATC7 = 0; } while(0)
#define RC7_Toggle()   do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define RC7_GetValue()         PORTCbits.RC7
#define RC7_SetDigitalInput()   do { TRISCbits.TRISC7 = 1; } while(0)
#define RC7_SetDigitalOutput()  do { TRISCbits.TRISC7 = 0; } while(0)
#define RC7_SetPullup()     do { WPUCbits.WPUC7 = 1; } while(0)
#define RC7_ResetPullup()   do { WPUCbits.WPUC7 = 0; } while(0)
#define RC7_SetAnalogMode() do { ANSELCbits.ANSC7 = 1; } while(0)
#define RC7_SetDigitalMode()do { ANSELCbits.ANSC7 = 0; } while(0)

// get/set BLE2_Wake aliases
#define BLE2_Wake_TRIS               TRISDbits.TRISD0
#define BLE2_Wake_LAT                LATDbits.LATD0
#define BLE2_Wake_PORT               PORTDbits.RD0
#define BLE2_Wake_WPU                WPUDbits.WPUD0
#define BLE2_Wake_OD                ODCONDbits.ODCD0
#define BLE2_Wake_ANS                ANSELDbits.ANSD0
#define BLE2_Wake_SetHigh()            do { LATDbits.LATD0 = 1; } while(0)
#define BLE2_Wake_SetLow()             do { LATDbits.LATD0 = 0; } while(0)
#define BLE2_Wake_Toggle()             do { LATDbits.LATD0 = ~LATDbits.LATD0; } while(0)
#define BLE2_Wake_GetValue()           PORTDbits.RD0
#define BLE2_Wake_SetDigitalInput()    do { TRISDbits.TRISD0 = 1; } while(0)
#define BLE2_Wake_SetDigitalOutput()   do { TRISDbits.TRISD0 = 0; } while(0)
#define BLE2_Wake_SetPullup()      do { WPUDbits.WPUD0 = 1; } while(0)
#define BLE2_Wake_ResetPullup()    do { WPUDbits.WPUD0 = 0; } while(0)
#define BLE2_Wake_SetPushPull()    do { ODCONDbits.ODCD0 = 0; } while(0)
#define BLE2_Wake_SetOpenDrain()   do { ODCONDbits.ODCD0 = 1; } while(0)
#define BLE2_Wake_SetAnalogMode()  do { ANSELDbits.ANSD0 = 1; } while(0)
#define BLE2_Wake_SetDigitalMode() do { ANSELDbits.ANSD0 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/