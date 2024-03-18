/*
 * c28x_ipc_cpu2_interrupts.c
 *
 *  Created on: 15 de mar de 2024
 *      Author: ramon.martins
 */

#include "cpu2_interrupts.h"
#include "temp_ipc.h"

extern temp_IPC_MessageQueue_t MQ_CPU2_CPU1;

__interrupt void IPC_CPU1_ISR0(){
    IPC_ackFlagRtoL(IPC_CPU2_L_CPU1_R, IPC_FLAG0);
    Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP1);
//    BaseType_t xHigherPriorityTaskWoken = pdFALSE;

    ESTOP0;

//    portEND_SWITCHING_ISR(xHigherPriorityTaskWoken);

}

__interrupt void IPC_CPU1_ISR1(){
    IPC_ackFlagRtoL(IPC_CPU2_L_CPU1_R, IPC_FLAG1);
    Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP1);

//    BaseType_t xHigherPriorityTaskWoken = pdFALSE;

//    ESTOP0;

    temp_IPC_Message_t Message_received;

    bool status;
    do{
        status = temp_IPC_readMessageFromQueue(IPC_CPU2_L_CPU1_R, &MQ_CPU2_CPU1, IPC_ADDR_CORRECTION_DISABLE, &Message_received , IPC_NONBLOCKING_CALL);

        if(status){

        }else{
            // Treat the error here
        }
    }while(status);

//    portEND_SWITCHING_ISR(xHigherPriorityTaskWoken);

}

__interrupt void IPC_CPU1_ISR2(){
    IPC_ackFlagRtoL(IPC_CPU2_L_CPU1_R, IPC_FLAG2);
    Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP1);
//    BaseType_t xHigherPriorityTaskWoken = pdFALSE;

    ESTOP0;

//    portEND_SWITCHING_ISR(xHigherPriorityTaskWoken);

}

__interrupt void IPC_CPU1_ISR3(){
    IPC_ackFlagRtoL(IPC_CPU2_L_CPU1_R, IPC_FLAG3);
    Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP1);
//    BaseType_t xHigherPriorityTaskWoken = pdFALSE;

    ESTOP0;

//    portEND_SWITCHING_ISR(xHigherPriorityTaskWoken);
}
