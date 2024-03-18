/*
 * c28x_interrupts.h
 *
 *  Created on: 11 de mar de 2024
 *      Author: ramon.martins
 */

#ifndef APPLICATION_INCLUDE_CM_INTERRUPTS_H_
#define APPLICATION_INCLUDE_CM_INTERRUPTS_H_

#include "cm.h"

// IPC Interrupts

__interrupt void IPC_CPU1_ISR0();
__interrupt void IPC_CPU1_ISR1();
__interrupt void IPC_CPU1_ISR2();
__interrupt void IPC_CPU1_ISR3();
__interrupt void IPC_CPU1_ISR4();
__interrupt void IPC_CPU1_ISR5();
__interrupt void IPC_CPU1_ISR6();
__interrupt void IPC_CPU1_ISR7();

__interrupt void IPC_CPU2_ISR0();
__interrupt void IPC_CPU2_ISR1();
__interrupt void IPC_CPU2_ISR2();
__interrupt void IPC_CPU2_ISR3();
__interrupt void IPC_CPU2_ISR4();
__interrupt void IPC_CPU2_ISR5();
__interrupt void IPC_CPU2_ISR6();
__interrupt void IPC_CPU2_ISR7();

#endif /* APPLICATION_INCLUDE_CM_INTERRUPTS_H_ */
