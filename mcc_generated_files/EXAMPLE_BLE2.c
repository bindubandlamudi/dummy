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

#include <string.h>
#include "mcc.h"
#include "BLE2_driver.h"
#include "EXAMPLE_BLE2.h"
#include "drivers/uart.h"

//*********************************************************
//          Local Defines/Variables used for Example
//*********************************************************
#define responseBufferSize  31
static uint8_t rn4020ResponseIndex = 0;
static char rn4020ResponseBuffer [responseBufferSize] = {0};
static char exampleReadStorage [responseBufferSize] = {0};
//*********************************************************
//          Local Prototype Functions
//*********************************************************
static void EXAMPLE_blockingWait(uint16_t);
static void EXAMPLE_ReadyReceiveBuffer(void);
static char* EXAMPLE_GetResponse(void);
static char* EXAMPLE_sendAndWait(const char* sendString);
//*********************************************************
//          Accessible Example Functions
//*********************************************************
void EXAMPLE_sendMessageOverBLE2(uint8_t *message){
    if(BLE2_isConnected()){
        BLE2_SendString(message);
    }
}

void EXAMPLE_sendBufferOverBLE2(uint8_t *buffer, uint8_t len)
{
    if(BLE2_isConnected()){
        BLE2_SendBuffer(buffer, len);
    }
}

void EXAMPLE_setupBLE2 (const char* name)                       // Call After System Init; Above while(1) Loop in Main.c
{
    char* exampleRead;
    uart[BLE2].SetRxISR(EXAMPLE_CaptureReceivedMessage);
    BLE2_WakeModule();                              // Wake Module using GPIO       
    EXAMPLE_blockingWait(200);                      // Wait for "CMD" Response              
    exampleRead = EXAMPLE_GetResponse();            // Read "CMD\r\n" from Buffer
    strcpy(exampleReadStorage, exampleRead);        // Store for use/reference
    EXAMPLE_ReadyReceiveBuffer();                   // Prepare for next message
    BLE2_EnterCommand_Mode();                       // Enter "Command Mode" via GPIO
    EXAMPLE_sendAndWait("SF,1\r\n");                // Factory Reset
    EXAMPLE_sendAndWait("SR,30000800\r\n");         // Setup Services
    BLE2_SendString("S-,");                         // Set Serialized Name
    BLE2_SendString(name);
    EXAMPLE_sendAndWait("\r\n");
    BLE2_SendString("SN,");                         // Set Name
    BLE2_SendString(name);
    EXAMPLE_sendAndWait("\r\n");
    EXAMPLE_sendAndWait("A\r\n");                   // Advertise
    EXAMPLE_sendAndWait("R,1\r\n");                 // Reset
    EXAMPLE_blockingWait(120);
    BLE2_EnterCommand_Mode();                       // Enter "Command Mode" via GPIO
    EXAMPLE_sendAndWait("B\r\n");                   // Bond
    EXAMPLE_sendAndWait("WC\r\n");                  // Clear Scripts
}
void EXAMPLE_CaptureReceivedMessage(void)           // Call in ISR EUSART RX after EUSART_Receive_ISR() 
{
    uart[BLE2].RxDefaultISR();
    uint8_t readByte = uart[BLE2].Read();
    if ( (readByte != '\0') && (rn4020ResponseIndex < responseBufferSize) )
        rn4020ResponseBuffer[rn4020ResponseIndex++] = readByte;
}
//*********************************************************
//          Local Used Example Functions
//*********************************************************
static void EXAMPLE_ReadyReceiveBuffer (void)
{
    rn4020ResponseIndex = 0;
    for (uint8_t position = 0; position < responseBufferSize; position++)
        rn4020ResponseBuffer[position] = 0;
}
static char* EXAMPLE_GetResponse(void)
{
    return rn4020ResponseBuffer;
}
static void EXAMPLE_blockingWait (uint16_t limit)
{
    for (uint16_t counter = 0; counter < limit; counter++)
        __delay_ms(15);
}
static char* EXAMPLE_sendAndWait(const char* sendString)
{
    BLE2_SendString(sendString);
    EXAMPLE_blockingWait(4);                 // Wait for Response (~60ms)
    return EXAMPLE_GetResponse();            // Read String from Buffer
}