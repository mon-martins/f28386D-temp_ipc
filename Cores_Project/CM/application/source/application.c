/*
 * application.c
 *
 *  Created on: 11 de mar de 2024
 *      Author: ramon.martins
 */

#include "application.h"

void user_board_init(void){

    IPC_registerInterrupt(IPC_CM_L_CPU1_R, IPC_INT0, IPC_CPU1_ISR0);
    IPC_registerInterrupt(IPC_CM_L_CPU1_R, IPC_INT1, IPC_CPU1_ISR1);
    IPC_registerInterrupt(IPC_CM_L_CPU1_R, IPC_INT2, IPC_CPU1_ISR2);
    IPC_registerInterrupt(IPC_CM_L_CPU1_R, IPC_INT3, IPC_CPU1_ISR3);
    IPC_registerInterrupt(IPC_CM_L_CPU1_R, IPC_INT4, IPC_CPU1_ISR4);
    IPC_registerInterrupt(IPC_CM_L_CPU1_R, IPC_INT5, IPC_CPU1_ISR5);
    IPC_registerInterrupt(IPC_CM_L_CPU1_R, IPC_INT6, IPC_CPU1_ISR6);
    IPC_registerInterrupt(IPC_CM_L_CPU1_R, IPC_INT7, IPC_CPU1_ISR7);

    IPC_registerInterrupt(IPC_CM_L_CPU2_R, IPC_INT0, IPC_CPU2_ISR0);
    IPC_registerInterrupt(IPC_CM_L_CPU2_R, IPC_INT1, IPC_CPU2_ISR1);
    IPC_registerInterrupt(IPC_CM_L_CPU2_R, IPC_INT2, IPC_CPU2_ISR2);
    IPC_registerInterrupt(IPC_CM_L_CPU2_R, IPC_INT3, IPC_CPU2_ISR3);
    IPC_registerInterrupt(IPC_CM_L_CPU2_R, IPC_INT4, IPC_CPU2_ISR4);
    IPC_registerInterrupt(IPC_CM_L_CPU2_R, IPC_INT5, IPC_CPU2_ISR5);
    IPC_registerInterrupt(IPC_CM_L_CPU2_R, IPC_INT6, IPC_CPU2_ISR6);
    IPC_registerInterrupt(IPC_CM_L_CPU2_R, IPC_INT7, IPC_CPU2_ISR7);

}
