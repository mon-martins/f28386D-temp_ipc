/*
 * cla1_shared_memory.h
 *
 *  Created on: 11 de mar de 2024
 *      Author: ramon.martins
 */

#ifndef APPLICATION_INCLUDE_CLA_CLA1_SHARED_MEMORY_H_
#define APPLICATION_INCLUDE_CLA_CLA1_SHARED_MEMORY_H_


//
// Defines
//

//
// Globals
//

// Caution use only variables with n*16bits size
// CLA to CPU Message RAM area
typedef struct{

    uint16_t a;

//Task 1 (C) Variables

//Task 2 (C) Variables

//Task 3 (C) Variables

//Task 4 (C) Variables

//Task 5 (C) Variables

//Task 6 (C) Variables

//Task 7 (C) Variables

//Task 8 (C) Variables

//Common (C) Variables


}CLA_CPU_Message;


// Caution use only variables with n*16bits size
// CPU to CLA Message RAM area
typedef struct{

//Task 1 (C) Variables

//Task 2 (C) Variables

//Task 3 (C) Variables

//Task 4 (C) Variables

//Task 5 (C) Variables

//Task 6 (C) Variables

//Task 7 (C) Variables

//Task 8 (C) Variables

//Common (C) Variables

}CPU_CLA_Message;

typedef struct{ //Cla_CPU Memory, Be careful this memory can be initialized by CPU, but in real time it is only for CLA
// Put your Cla_Data which is initialized by CPU here, go to "cla1_shared_memory.c" file and initiate this data globally.

}CLA_Memory_CPU_Init;

#endif /* APPLICATION_INCLUDE_CLA_CLA1_SHARED_MEMORY_H_ */
