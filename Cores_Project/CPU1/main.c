/**
 * main.c
 */

#include "application.h"
#include "temp_ipc.h"

temp_IPC_MessageQueue_t MQ_CPU1_CM;
temp_IPC_MessageQueue_t MQ_CPU1_CPU2;

void main(void)
{
    C2000_Init();

    EINT;
    ERTM;

    temp_IPC_initMessageQueue(IPC_CPU1_L_CM_R, &MQ_CPU1_CM, IPC_INT1, IPC_INT1);
    temp_IPC_initMessageQueue(IPC_CPU1_L_CPU2_R, &MQ_CPU1_CPU2, IPC_INT1, IPC_INT1);

    GPIO_writePin(LED1, 0);

    temp_IPC_Message_t my_msg;
    my_msg.Payload[0] = 0;
    while(1){
        my_msg.Payload[0] = (my_msg.Payload[0]+1)%10;
        if(!temp_IPC_sendMessageToQueue(IPC_CPU1_L_CM_R  , &MQ_CPU1_CM  , IPC_ADDR_CORRECTION_DISABLE, &my_msg, IPC_NONBLOCKING_CALL)) GPIO_writePin(LED1, 1);
        if(!temp_IPC_sendMessageToQueue(IPC_CPU1_L_CPU2_R, &MQ_CPU1_CPU2, IPC_ADDR_CORRECTION_DISABLE, &my_msg, IPC_NONBLOCKING_CALL)) GPIO_writePin(LED1, 1);
        DEVICE_DELAY_US(1000);
    }
}
