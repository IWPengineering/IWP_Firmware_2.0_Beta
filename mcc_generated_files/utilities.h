/* Microchip Technology Inc. and its subsidiaries.  You may use this software 
 * and any derivatives exclusively with Microchip products. 
 * 
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES, WHETHER 
 * EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED 
 * WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A 
 * PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION 
 * WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION. 
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
 * INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
 * WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS 
 * BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE 
 * FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS 
 * IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF 
 * ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE 
 * TERMS. 
 */

/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef XC_HEADER_TEMPLATE_H
#define	XC_HEADER_TEMPLATE_H

#include <xc.h> // include processor files - each processor file is guarded.  
#include "mcc.h"
#include "interrupt_handlers.h"

/*
 Definitions
 */
#define BATTERY_LOW_THRESHOLD           400 // Check this value
#define MESSAGE_LENGTH                  160
#define NETWORK_SEARCH_TIMEOUT          300000 // Time in MS that we will keep
                                               //  looking for network

/*
 Public Variables
 */
extern char TextMessageString[MESSAGE_LENGTH];
extern char phoneNumber[12];
extern bool isBatteryLow;

// Accumulates battery voltage for an end of day average
extern uint16_t batteryAccumulator;
extern uint16_t batteryAccumAmt;

// Volume accumulator array
extern float volumeArray[12];
// Longest leak rate recorded for the day
extern float longestLeakRate;
// Longest prime time recorded for the day
extern float longestPrime;

/*
 Private Variables
 */

/*
 Public Functions
 */
void DelayUS(int us);
void DelayMS(int ms);
void DelayS(int sec);
void KickWatchdog(void);

void updateMessageVolume(void);
void updateMessageBattery(void);
void updateMessagePrime(void);
void updateMessageLeakage(void);
// len of data must INCLUDE decimal point
//  Cannot handle higher than 6 decimal precision due to implementation
void floatToAscii(float value, int decimalPrecision, 
        char *dataPtr, uint8_t dataLen);
int numDigits(uint32_t num);
uint32_t tenToPower(int exponent);
bool IsSimOn(void);
bool IsSimOnNetwork(void);
bool IsThereWater(void);

uint8_t sendUART1(char *dataPtr, uint16_t dataCnt);
void turnOnSim(void);
void turnOffSim(void);

void assembleMidnightMessage(void);

void handleAccelBufferEvent(void);
void handleBatteryBufferEvent(void);

/*
 Private Functions
 */

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    // TODO If C++ is being used, regular C code needs function names to have C 
    // linkage so the functions can be used by the c code. 

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* XC_HEADER_TEMPLATE_H */

