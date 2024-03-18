/*
 * application.c
 *
 *  Created on: 11 de mar de 2024
 *      Author: ramon.martins
 */

#include "application.h"

void user_board_init(){
    Board_init();

    IPC_registerInterrupt(IPC_CPU2_L_CM_R, IPC_INT0, IPC_CM_ISR0);
    IPC_registerInterrupt(IPC_CPU2_L_CM_R, IPC_INT1, IPC_CM_ISR1);
    IPC_registerInterrupt(IPC_CPU2_L_CM_R, IPC_INT2, IPC_CM_ISR2);
    IPC_registerInterrupt(IPC_CPU2_L_CM_R, IPC_INT3, IPC_CM_ISR3);
    IPC_registerInterrupt(IPC_CPU2_L_CM_R, IPC_INT4, IPC_CM_ISR4);
    IPC_registerInterrupt(IPC_CPU2_L_CM_R, IPC_INT5, IPC_CM_ISR5);
    IPC_registerInterrupt(IPC_CPU2_L_CM_R, IPC_INT6, IPC_CM_ISR6);
    IPC_registerInterrupt(IPC_CPU2_L_CM_R, IPC_INT7, IPC_CM_ISR7);

}
