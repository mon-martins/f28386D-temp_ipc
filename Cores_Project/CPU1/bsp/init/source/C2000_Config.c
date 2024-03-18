/*
 * C2000_Config.c
 *
 *  Created on: 29 de fev de 2024
 *      Author: ramon.martins
 */

#include "C2000_Config.h"

void C2000_Init(void){

    //
    // Initialize device clock and peripherals
    //
    Device_init();

    //
    // Boot CPU2 core
    //

    Device_bootCPU2(BOOT_MODE_CPU2);

    //
    // Boot CM
    //
    #ifdef _FLASH
        Device_bootCM(BOOTMODE_BOOT_TO_FLASH_SECTOR0);
    #else
        Device_bootCM(BOOTMODE_BOOT_TO_S0RAM);
    #endif

    //
    // Initialize GPIO and configure the GPIO pin as a push-pull output
    //
    Device_initGPIO();
    //
    // Initialize PIE and clear PIE registers. Disables CPU interrupts.
    //
    Interrupt_initModule();

    //
    // Initialize the PIE vector table with pointers to the shell Interrupt
    // Service Routines (ISR).
    //
    Interrupt_initVectorTable();

#if USER_BOARD_INIT
    user_board_init();
#else
    Board_init();
#endif

    C2000Ware_libraries_init();

    IPC_clearFlagLtoR(IPC_CPU1_L_CPU2_R, IPC_FLAG_ALL);
    IPC_sync(IPC_CPU1_L_CPU2_R, IPC_SYNC);

    IPC_clearFlagLtoR(IPC_CPU1_L_CM_R, IPC_FLAG_ALL);
    IPC_sync(IPC_CPU1_L_CM_R, IPC_SYNC);
}
