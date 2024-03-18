/**
 * main.c
 */

#include "application.h"
#include "temp_ipc.h"

temp_IPC_MessageQueue_t MQ_CPU2_CM;
temp_IPC_MessageQueue_t MQ_CPU2_CPU1;

void main(void)
{
    C2000_Init();

    EINT;
    ERTM;

    temp_IPC_initMessageQueue(IPC_CPU2_L_CM_R, &MQ_CPU2_CM, IPC_INT1, IPC_INT1);
    temp_IPC_initMessageQueue(IPC_CPU2_L_CPU1_R, &MQ_CPU2_CPU1, IPC_INT1, IPC_INT1);

    GPIO_writePin(LED2, 0);

    temp_IPC_Message_t my_msg;
    my_msg.Payload[0] = 0;
    while(1){
        my_msg.Payload[0] = (my_msg.Payload[0]+1)%10;
        if(!temp_IPC_sendMessageToQueue(IPC_CPU2_L_CM_R  , &MQ_CPU2_CM  , IPC_ADDR_CORRECTION_DISABLE, &my_msg, IPC_NONBLOCKING_CALL)) GPIO_writePin(LED2, 1);
        if(!temp_IPC_sendMessageToQueue(IPC_CPU2_L_CPU1_R, &MQ_CPU2_CPU1, IPC_ADDR_CORRECTION_DISABLE, &my_msg, IPC_NONBLOCKING_CALL)) GPIO_writePin(LED2, 1);
        DEVICE_DELAY_US(1000);
    }
}
