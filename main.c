#include "mcc_generated_files/mcc.h"
#include "mcc_generated_files/interrupt_handlers.h"
#include "mcc_generated_files/rtcc_handler.h"
#include "mcc_generated_files/utilities.h"

/*
                         Main application
 */
int main(void) {
    // initialize the device
    SYSTEM_Initialize();
    InitRTCC(); // Initialize I2C RTCC
    InitQueues(); // Start ADC queues
    InitIOCInterrupt(); // Initialize IOC Interrupts

    // Added to check if we can get through ADC read here - not in ISR
    TMR1_CallBack();
    
    TMR1_Start();
    TMR2_Start();
    TMR3_Start();
    TMR4_Start();
    TMR5_Start();
    
    while (1) 
    {
        
        KickWatchdog(); // Reset the watchdog timer
        
        if(isMidnightPassed)
        {
            SendMidnightMessage();
        }
        
        if(!IsQueueEmpty(&xQueue) && !IsQueueEmpty(&yQueue))
        {
            ProcessAccelQueue();
        }
        
        if(depthBufferIsFull)
        {
            
        }
        
        if(batteryBufferIsFull)
        {
            HandleBatteryBufferEvent();
        }
        
        DelayMS(1000);
        //SendUART1("Hello! I'm on! :)", sizeof("Hello! I'm on! :)") - 1);
        SendUART1(TextMessageString, sizeof(TextMessageString));
    }

    return -1;
}
/**
 End of File
 */