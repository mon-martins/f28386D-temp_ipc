/*
 * temp_ipc.h
 *
 *  Created on: 14 de mar de 2024
 *      Author: ramon.martins
 */

#ifndef BSP_DRIVERLIB_INCLUDE_TEMP_IPC_H_
#define BSP_DRIVERLIB_INCLUDE_TEMP_IPC_H_

#include "temp_ipc_config.h"
#include "board.h"

#if temp_MQ_SUPPORT


#if (!defined(CPU1) && !defined(CPU2))
#error "You must define CPU1 or CPU2 in your project properties"
#endif

#if ( defined(CPU1) &&  defined(CPU2))
#error "You have defined CPU1 and CPU2"
#endif

#if (!(temp_MAX_PAYLOAD_SIZE >= 1) && temp_USE_PAYLOAD_IPC_MQ)
#error "You must define the maximum size of your payload(in 16bits) on MAX_PAYLOAD_SIZE"
#endif

#if !temp_USE_COMMAND_IPC_MQ && !temp_USE_POINTER_IPC_MQ && !temp_USE_PAYLOAD_IPC_MQ
#error "You must define the type of data, that will be used in MQ "
#endif

#if !(temp_IPC_BUFFER_SIZE>1)
#error "You must define the size of the buffer and it has to be larger than 1, if possible one larger than you need"
#endif

#if !temp_IPC_INTERRUPTS_CPU1_CPU2_USED && !temp_IPC_INTERRUPTS_CPU1_CM_USED && !temp_IPC_INTERRUPTS_CPU2_CM_USED
#error "You must define how many interrupts you will use in each IPC"
#endif

typedef struct
{
#if temp_USE_COMMAND_IPC_MQ
    uint32_t command;
#endif
#if temp_USE_POINTER_IPC_MQ
    uint32_t address;
#endif
#if temp_USE_PAYLOAD_IPC_MQ
    uint16_t Payload[temp_MAX_PAYLOAD_SIZE];
#endif
}temp_IPC_Message_t;

typedef struct
{
    temp_IPC_Message_t  Buffer[temp_IPC_BUFFER_SIZE];
    uint16_t            PutWriteIndex;
    uint16_t            GetReadIndex;
}temp_IPC_PutBuffer_t;

typedef struct
{
    temp_IPC_Message_t  Buffer[temp_IPC_BUFFER_SIZE];
    uint16_t            GetWriteIndex;
    uint16_t            PutReadIndex;
}temp_IPC_GetBuffer_t;

typedef struct
{
    temp_IPC_PutBuffer_t *  PutBuffer;
    volatile temp_IPC_GetBuffer_t *  GetBuffer;
    uint32_t         PutFlag;
} temp_IPC_MessageQueue_t;

typedef struct
{
    temp_IPC_PutBuffer_t PutBuffer[temp_IPC_INTERRUPTS_CPU1_CPU2_USED];
} temp_IPC_CPU1_CPU2_Data_t;

typedef struct
{
    temp_IPC_PutBuffer_t PutBuffer[temp_IPC_INTERRUPTS_CPU1_CM_USED];
} temp_IPC_CPU1_CM_Data_t;

typedef struct
{
    temp_IPC_PutBuffer_t PutBuffer[temp_IPC_INTERRUPTS_CPU2_CM_USED];
} temp_IPC_CPU2_CM_Data_t;

void temp_IPC_initMessageQueue(
        IPC_Type_t ipcType, volatile temp_IPC_MessageQueue_t *msgQueue,
        uint32_t ipcInt_L, uint32_t ipcInt_R);

bool temp_IPC_sendMessageToQueue(
        IPC_Type_t ipcType, volatile temp_IPC_MessageQueue_t *msgQueue,
        bool addrCorrEnable, temp_IPC_Message_t *msg, bool block);

bool temp_IPC_readMessageFromQueue(
        IPC_Type_t ipcType, volatile temp_IPC_MessageQueue_t *msgQueue,
        bool addrCorrEnable, temp_IPC_Message_t *msg, bool block);


#endif

#endif /* BSP_DRIVERLIB_INCLUDE_TEMP_IPC_H_ */
