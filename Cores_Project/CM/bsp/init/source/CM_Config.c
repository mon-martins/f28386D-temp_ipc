/*
 * CM_Config.c
 *
 *  Created on: 1 de mar de 2024
 *      Author: ramon.martins
 */

#include "CM_Config.h"

void CortexM_Init(void){

    CM_init();

#if USER_BOARD_INIT
    user_board_init();
#endif

    //sync
    IPC_clearFlagLtoR(IPC_CM_L_CPU1_R, IPC_FLAG_ALL);
    IPC_sync(IPC_CM_L_CPU1_R, IPC_SYNC);

    IPC_clearFlagLtoR(IPC_CM_L_CPU2_R, IPC_FLAG_ALL);
    IPC_sync(IPC_CM_L_CPU2_R, IPC_SYNC);

}
