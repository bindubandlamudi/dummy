/*
    (c) 2016 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
*/

#include <xc.h>
#include "BLE2_driver.h"
#include <string.h>
#include "drivers/uart.h"

void BLE2_EnterCommand_Mode(void)
{
    LATCbits.LATC2 = 1;
}
void BLE2_EnterMicrochipLowEnergyDataProfile_Mode(void)
{
    LATCbits.LATC2 = 0;
}
void BLE2_DeepSleepModule(void)
{
    LATDbits.LATD0 = 0;
}
void BLE2_WakeModule(void)
{
    LATDbits.LATD0 = 1;
}
bool BLE2_isConnected(void)
{
    return PORTAbits.RA1;
}
void BLE2_SendString(const char* command)
{
    BLE2_SendBuffer(command, strlen(command));
}
void BLE2_SendBuffer(uint8_t *buffer, uint8_t length)
{
    while(length--)
        BLE2_SendByte(*buffer++);
}
void BLE2_SendByte(uint8_t byte)
{
    uart[BLE2].Write(byte);
}