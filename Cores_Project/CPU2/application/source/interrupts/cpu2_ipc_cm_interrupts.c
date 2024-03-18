/*
 * c28x_ipc_interrupts.c
 *
 *  Created on: 15 de mar de 2024
 *      Author: ramon.martins
 */


#include "cpu2_interrupts.h"
#include "temp_ipc.h"

extern temp_IPC_MessageQueue_t MQ_CPU2_CM;

__interrupt void IPC_CM_ISR0(){
    IPC_ackFlagRtoL(IPC_CPU2_L_CM_R, IPC_FLAG0);
    Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP11);

    ESTOP0;
}

__interrupt void IPC_CM_ISR1(){
    IPC_ackFlagRtoL(IPC_CPU2_L_CM_R, IPC_FLAG1);
    Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP11);

    temp_IPC_Message_t Message_received;
    bool status;
    do{
        status = temp_IPC_readMessageFromQueue(IPC_CPU2_L_CM_R, &MQ_CPU2_CM, IPC_ADDR_CORRECTION_DISABLE, &Message_received , IPC_NONBLOCKING_CALL);

        if(status){

        }else{
            // Treat the error here
        }
    }while(status);
}

__interrupt void IPC_CM_ISR2(){
    IPC_ackFlagRtoL(IPC_CPU2_L_CM_R, IPC_FLAG2);
    Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP11);

    ESTOP0;
}

__interrupt void IPC_CM_ISR3(){
    IPC_ackFlagRtoL(IPC_CPU2_L_CM_R, IPC_FLAG3);
    Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP11);

    ESTOP0;
}

__interrupt void IPC_CM_ISR4(){
    IPC_ackFlagRtoL(IPC_CPU2_L_CM_R, IPC_FLAG4);
    Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP11);

    ESTOP0;
}

__interrupt void IPC_CM_ISR5(){
    IPC_ackFlagRtoL(IPC_CPU2_L_CM_R, IPC_FLAG5);
    Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP11);

    ESTOP0;
}

__interrupt void IPC_CM_ISR6(){
    IPC_ackFlagRtoL(IPC_CPU2_L_CM_R, IPC_FLAG6);
    Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP11);

    ESTOP0;
}

__interrupt void IPC_CM_ISR7(){
    IPC_ackFlagRtoL(IPC_CPU2_L_CM_R, IPC_FLAG7);
    Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP11);

    ESTOP0;
}
