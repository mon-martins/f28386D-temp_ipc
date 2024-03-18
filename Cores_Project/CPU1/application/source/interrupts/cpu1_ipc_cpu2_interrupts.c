/*
 * c28x_ipc_cpu2_interrupts.c
 *
 *  Created on: 15 de mar de 2024
 *      Author: ramon.martins
 */

#include "cpu1_interrupts.h"
#include "temp_ipc.h"

extern temp_IPC_MessageQueue_t MQ_CPU1_CPU2;

__interrupt void IPC_CPU2_ISR0(){
    IPC_ackFlagRtoL(IPC_CPU1_L_CPU2_R, IPC_FLAG0);
    Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP1);

    ESTOP0;

}

__interrupt void IPC_CPU2_ISR1(){
    IPC_ackFlagRtoL(IPC_CPU1_L_CPU2_R, IPC_FLAG1);
    Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP1);

    temp_IPC_Message_t Message_received;

    bool status;
    do{
        status = temp_IPC_readMessageFromQueue(IPC_CPU1_L_CPU2_R, &MQ_CPU1_CPU2, IPC_ADDR_CORRECTION_DISABLE, &Message_received , IPC_NONBLOCKING_CALL);

        if(status){

        }else{
            // Treat the error here
        }
    }while(status);
}

__interrupt void IPC_CPU2_ISR2(){
    IPC_ackFlagRtoL(IPC_CPU1_L_CPU2_R, IPC_FLAG2);
    Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP1);

    ESTOP0;
}

__interrupt void IPC_CPU2_ISR3(){
    IPC_ackFlagRtoL(IPC_CPU1_L_CPU2_R, IPC_FLAG3);
    Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP1);

    ESTOP0;
}
