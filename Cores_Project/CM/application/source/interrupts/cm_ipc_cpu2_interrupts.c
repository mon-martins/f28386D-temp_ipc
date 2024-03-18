/*
 * cm_ipc_cpu2_interrupts.c
 *
 *  Created on: 15 de mar de 2024
 *      Author: ramon.martins
 */

#include "cm_interrupts.h"
#include "temp_ipc.h"

extern temp_IPC_MessageQueue_t MQ_CM_CPU2;

__interrupt void IPC_CPU2_ISR0(){
    IPC_ackFlagRtoL(IPC_CM_L_CPU2_R, IPC_FLAG0);

    ESTOP0;
}

__interrupt void IPC_CPU2_ISR1(){
    IPC_ackFlagRtoL(IPC_CM_L_CPU2_R, IPC_FLAG1);

    temp_IPC_Message_t Message_received;
    bool status;
    do{
        status = temp_IPC_readMessageFromQueue( IPC_CM_L_CPU2_R , &MQ_CM_CPU2 , IPC_ADDR_CORRECTION_DISABLE , &Message_received , IPC_NONBLOCKING_CALL);
        if(status==true){
            // Message_received
        }else{
            // Treat the error here
        }
    }while(status);
}
__interrupt void IPC_CPU2_ISR2(){
    IPC_ackFlagRtoL(IPC_CM_L_CPU2_R, IPC_FLAG2);

    ESTOP0;
}
__interrupt void IPC_CPU2_ISR3(){
    IPC_ackFlagRtoL(IPC_CM_L_CPU2_R, IPC_FLAG3);

    ESTOP0;
}

__interrupt void IPC_CPU2_ISR4(){
    IPC_ackFlagRtoL(IPC_CM_L_CPU2_R, IPC_FLAG4);

    ESTOP0;
}

__interrupt void IPC_CPU2_ISR5(){
    IPC_ackFlagRtoL(IPC_CM_L_CPU2_R, IPC_FLAG5);

    ESTOP0;
}

__interrupt void IPC_CPU2_ISR6(){
    IPC_ackFlagRtoL(IPC_CM_L_CPU2_R, IPC_FLAG6);

    ESTOP0;
}

__interrupt void IPC_CPU2_ISR7(){
    IPC_ackFlagRtoL(IPC_CM_L_CPU2_R, IPC_FLAG7);

    ESTOP0;
}
