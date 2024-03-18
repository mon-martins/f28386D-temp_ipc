/*
 * temp_ipc_config.h
 *
 *  Created on: 15 de mar de 2024
 *      Author: ramon.martins
 */

#ifndef APPLICATION_INCLUDE_TEMP_IPC_CONFIG_H_
#define APPLICATION_INCLUDE_TEMP_IPC_CONFIG_H_

#define temp_USE_COMMAND_IPC_MQ 0
#define temp_USE_POINTER_IPC_MQ 0
#define temp_USE_PAYLOAD_IPC_MQ 1

// consider use buffersize + 1. this MQ let a
// dead space in the buffer because the head tail use
#define temp_IPC_BUFFER_SIZE    4
#define temp_MAX_PAYLOAD_SIZE   1

#define temp_IPC_INTERRUPTS_CPU1_CPU2_USED 1
#define temp_IPC_INTERRUPTS_CPU1_CM_USED 1
#define temp_IPC_INTERRUPTS_CPU2_CM_USED 1

#define IPC_REGISTER_CMD 0xFFFFFF01

#define temp_MQ_SUPPORT 1

#endif /* APPLICATION_INCLUDE_TEMP_IPC_CONFIG_H_ */
