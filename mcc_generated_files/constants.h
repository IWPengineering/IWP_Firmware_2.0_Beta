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
#ifndef CONSTANTS_H
#define	CONSTANTS_H

#include <xc.h> // include processor files - each processor file is guarded.  
#include "mcc.h"

/*
 Definitions
 */

#define BATTERY_LOW_THRESHOLD           400 // Check value
#define MESSAGE_LENGTH                  160
#define NETWORK_SEARCH_TIMEOUT          300000 // Time in MS to search for
                                               //  the network
#define HANDLE_MOVEMENT_THRESHOLD       5 // Degrees that handle must move
                                          //  to be considered moving
#define TEXT_SEND_TIMEOUT_SECONDS       30 // seconds to wait for a text to send

#define DEPTH_BUFFER_SIZE               8 // Depth sensor buffer
#define BATTERY_BUFFER_SIZE             8 // Battery buffer
#define Y_AXIS_BUFFER_SIZE              8 // Y axis ADC Buffer
#define X_AXIS_BUFFER_SIZE              8 // X axis ADC Buffer
#define ANGLES_TO_AVERAGE               10 // Defines number of angles in 
                                           //  the float queue
#define WATER_PERIOD_LOW_BOUND          100 // ~2.5kHz
#define WATER_PERIOD_HIGH_BOUND         385 // ~650Hz
#define NETLIGHT_PERIOD_LOW_BOUND       19500 // ~2.5 seconds
#define NETLIGHT_PERIOD_HIGH_BOUND      27350 // ~3.5 seconds
/*
 Constants
 */
extern const float c_RadToDegrees;
extern const int c_AdjustmentFactor;

extern const float c_MKIILiterPerDegree;
extern const float c_UpstrokeToMeters;
extern const float c_MaxLitersToLeak;


#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    // TODO If C++ is being used, regular C code needs function names to have C 
    // linkage so the functions can be used by the c code. 

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* XC_HEADER_TEMPLATE_H */
