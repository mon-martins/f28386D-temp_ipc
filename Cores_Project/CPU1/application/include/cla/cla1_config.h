/*
 * cla1_config.h
 *
 *  Created on: 11 de mar de 2024
 *      Author: ramon.martins
 */

#ifndef APPLICATION_INCLUDE_CLA_CLA1_CONFIG_H_
#define APPLICATION_INCLUDE_CLA_CLA1_CONFIG_H_

#include "cla1_shared_memory.h"

extern CPU_CLA_Message CPU2CLA_Message;

extern CLA_CPU_Message CLA2CPU_Message;

extern CLA_Memory_CPU_Init CLA_Memory;


//
// Function Prototypes
//
// The following are symbols defined in the CLA assembly code
// Including them in the shared header file makes them
// .global and the main CPU can make use of them.
//
__interrupt void Cla1Task1();
__interrupt void Cla1Task2();
__interrupt void Cla1Task3();
__interrupt void Cla1Task4();
__interrupt void Cla1Task5();
__interrupt void Cla1Task6();
__interrupt void Cla1Task7();
__interrupt void Cla1Task8();

#endif /* APPLICATION_INCLUDE_CLA_CLA1_CONFIG_H_ */
