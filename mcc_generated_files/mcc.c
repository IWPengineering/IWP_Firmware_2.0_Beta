/**
  @Generated MPLAB� Code Configurator Source File

  @Company:
    Microchip Technology Inc.

  @File Name:
    mcc.c

  @Summary:
    This is the mcc.c file generated using MPLAB� Code Configurator

  @Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  MPLAB� Code Configurator - v2.25.2
        Device            :  PIC24F32KA302
        Driver Version    :  1.02
    The generated drivers are tested against the following:
        Compiler          :  XC16 v1.24
        MPLAB             :  MPLAB X v2.35 or v3.00
 */

/*
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

// Configuration bits: selected in the GUI

// FBS
#pragma config BSS = OFF    // Boot segment Protect->No boot program flash segment
#pragma config BWRP = OFF    // Boot Segment Write Protect->Disabled

// FGS
#pragma config GSS0 = OFF    // General Segment Code Protect->No Protection
#pragma config GWRP = OFF    // General Segment Write Protect->General segment may be written

// FOSCSEL
#pragma config LPRCSEL = LP    // LPRC Oscillator Power and Accuracy->Low Power, Low Accuracy Mode
#pragma config IESO = OFF    // Internal External Switch Over bit->Internal External Switchover mode enabled (Two-speed Start-up disabled)
#pragma config FNOSC = FRC    // Oscillator Select->8MHz FRC oscillator With Postscaler (FRCDIV)
#pragma config SOSCSRC = ANA    // SOSC Source Type->Analog Mode for use with crystal

// FOSC
#pragma config POSCFREQ = HS    // Primary Oscillator Frequency Range Configuration bits->Primary oscillator/external clock input frequency greater than 8MHz
#pragma config POSCMOD = NONE    // Primary Oscillator Configuration bits->Primary oscillator disabled
#pragma config SOSCSEL = SOSCHP    // SOSC Power Selection Configuration bits->Secondary Oscillator configured for high-power operation
#pragma config OSCIOFNC = OFF    // CLKO Enable Configuration bit->CLKO output disabled
#pragma config FCKSM = CSECMD    // Clock Switching and Monitor Selection->Clock Switching is enabled, Fail-safe Clock Monitor is disabled

// FWDT
#pragma config WDTPS = PS32768    // Watchdog Timer Postscale Select bits->1:32768
#pragma config FWPSA = PR128    // WDT Prescaler bit->WDT prescaler ratio of 1:128
#pragma config WINDIS = OFF    // Windowed Watchdog Timer Disable bit->Standard WDT selected(windowed WDT disabled)
#pragma config FWDTEN = ON    // Watchdog Timer Enable bits->WDT enabled in hardware

// FPOR
#pragma config I2C1SEL = PRI    // Alternate I2C1 Pin Mapping bit->Use Default SCL1/SDA1 Pins For I2C1
#pragma config BOREN = BOR3    // Brown-out Reset Enable bits->Brown-out Reset enabled in hardware, SBOREN bit disabled
#pragma config LVRCFG = OFF    // ->Low Voltage regulator is not available
#pragma config MCLRE = ON    // MCLR Pin Enable bit->RA5 input pin disabled,MCLR pin enabled
#pragma config BORV = 0b11    // Brown-out Reset Voltage bits->Brown-out Reset set to lowest voltage (1.8V)
#pragma config PWRTEN = ON    // Power-up Timer Enable bit->PWRT enabled

// FICD
#pragma config ICS = PGx1    // ICD Pin Placement Select bits->EMUC/EMUD share PGC2/PGD2

// FDS
#pragma config DSWDTPS = DSWDTPSF    // Deep Sleep Watchdog Timer Postscale Select bits->1:2,147,483,648 (25.7 Days)
#pragma config DSWDTOSC = LPRC    // DSWDT Reference Clock Select bit->DSWDT uses Low Power RC Oscillator (LPRC)
#pragma config DSBOREN = ON    // Deep Sleep Zero-Power BOR Enable bit->Deep Sleep BOR enabled in Deep Sleep
#pragma config DSWDTEN = ON    // Deep Sleep Watchdog Timer Enable bit->DSWDT enabled

#include "mcc.h"

void SYSTEM_Initialize(void) {
    OSCILLATOR_Initialize();
    PIN_MANAGER_Initialize();
    INTERRUPT_Initialize();
    ADC1_Initialize();
    //I2C1_Initialize(); // Will be called by my custom function
    //RTCC_Initialize();
    TMR1_Initialize();
    TMR2_Initialize();
    TMR3_Initialize();
    TMR5_Initialize();
    TMR4_Initialize();
    
    
}

void OSCILLATOR_Initialize(void) {
    // DOZEN disabled; DOZE 1:8; RCDIV FRC/2; ROI disabled; 
    CLKDIV = 0x3100;
    // Set the secondary oscillator
    OSCCONbits.SOSCEN = 1;
}

/**
 End of File
 */