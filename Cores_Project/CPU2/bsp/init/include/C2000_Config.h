/*
 * C2000_Config.h
 *
 *  Created on: 29 de fev de 2024
 *      Author: ramon.martins
 */

#ifndef APPLICATION_INC_C2000_CONFIG_H_
#define APPLICATION_INC_C2000_CONFIG_H_

#include "board.h"
#include "c2000ware_libraries.h"
#include "resources_config.h"

// Fixing DEVICE_DELAY_US missing parentheses on C2000WARE 05.00.00.00
#undef DEVICE_DELAY_US
#define DEVICE_DELAY_US(x) SysCtl_delay(((((long double)(x)) / (1000000.0L /  \
                              ((long double)DEVICE_SYSCLK_FREQ))) - 9.0L) / 5.0L)

void C2000_Init(void);

#endif /* APPLICATION_INC_C2000_CONFIG_H_ */
