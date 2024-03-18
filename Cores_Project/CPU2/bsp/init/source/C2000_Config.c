#include "C2000_Config.h"

void C2000_Init(void){

    //
    // Initialize device clock and peripherals
    //
    Device_init();


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

    IPC_clearFlagLtoR(IPC_CPU2_L_CPU1_R, IPC_FLAG_ALL);
    IPC_sync(IPC_CPU2_L_CPU1_R, IPC_SYNC);

    IPC_clearFlagLtoR(IPC_CPU2_L_CM_R, IPC_FLAG_ALL);
    IPC_sync(IPC_CPU2_L_CM_R, IPC_SYNC);
}
