/*
 * CM_IPC_Interrupts.c
 *
 *  Created on: 6 de set de 2023
 *      Author: ramon.martins
 */


#include "cm_interrupts.h"
#include "temp_ipc.h"

extern temp_IPC_MessageQueue_t MQ_CM_CPU1;

__interrupt void IPC_CPU1_ISR0(){ //On Reset This is Called for some reason
    IPC_ackFlagRtoL(IPC_CM_L_CPU1_R, IPC_FLAG0);

    //ESTOP0;
}

__interrupt void IPC_CPU1_ISR1(){
    IPC_ackFlagRtoL(IPC_CM_L_CPU1_R, IPC_FLAG1);

    temp_IPC_Message_t Message_received;
    bool status;
    do{
        status = temp_IPC_readMessageFromQueue( IPC_CM_L_CPU1_R , &MQ_CM_CPU1 , IPC_ADDR_CORRECTION_DISABLE , &Message_received , IPC_NONBLOCKING_CALL);
        if(status==true){
            // Message_received
        }else{

        }
    }while(status);
}
__interrupt void IPC_CPU1_ISR2(){
    IPC_ackFlagRtoL(IPC_CM_L_CPU1_R, IPC_FLAG2);

    ESTOP0;
}
__interrupt void IPC_CPU1_ISR3(){
    IPC_ackFlagRtoL(IPC_CM_L_CPU1_R, IPC_FLAG3);

    ESTOP0;
}

__interrupt void IPC_CPU1_ISR4(){
    IPC_ackFlagRtoL(IPC_CM_L_CPU1_R, IPC_FLAG4);

    ESTOP0;
}

__interrupt void IPC_CPU1_ISR5(){
    IPC_ackFlagRtoL(IPC_CM_L_CPU1_R, IPC_FLAG5);

    ESTOP0;
}

__interrupt void IPC_CPU1_ISR6(){
    IPC_ackFlagRtoL(IPC_CM_L_CPU1_R, IPC_FLAG6);

    ESTOP0;
}

__interrupt void IPC_CPU1_ISR7(){
    IPC_ackFlagRtoL(IPC_CM_L_CPU1_R, IPC_FLAG7);

    ESTOP0;
}
