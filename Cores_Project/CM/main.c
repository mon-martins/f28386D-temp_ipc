//
// Included Files
//

#include "application.h"

#include "temp_ipc.h"

/**
 * main.c
 */

temp_IPC_MessageQueue_t MQ_CM_CPU1;
temp_IPC_MessageQueue_t MQ_CM_CPU2;

void main(void)
{

    CortexM_Init();

    temp_IPC_initMessageQueue(IPC_CM_L_CPU1_R, &MQ_CM_CPU1, IPC_INT1, IPC_INT1);
    temp_IPC_initMessageQueue(IPC_CM_L_CPU2_R, &MQ_CM_CPU2, IPC_INT1, IPC_INT1);

    GPIO_writePin(LED3, 0);

    temp_IPC_Message_t my_msg;
    my_msg.Payload[0] = 0;
    while(1){
        my_msg.Payload[0] = (my_msg.Payload[0]+1)%10;
        if(!temp_IPC_sendMessageToQueue(IPC_CM_L_CPU1_R, &MQ_CM_CPU1, IPC_ADDR_CORRECTION_DISABLE, &my_msg, IPC_NONBLOCKING_CALL)) GPIO_writePin(LED3, 1);
        if(!temp_IPC_sendMessageToQueue(IPC_CM_L_CPU2_R, &MQ_CM_CPU2, IPC_ADDR_CORRECTION_DISABLE, &my_msg, IPC_NONBLOCKING_CALL)) GPIO_writePin(LED3, 1);
        DEVICE_DELAY_US(1000);
    }
}
