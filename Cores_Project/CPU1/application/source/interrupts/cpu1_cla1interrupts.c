/*
 * c28x_cla1interrupts.c
 *
 *  Created on: 11 de mar de 2024
 *      Author: ramon.martins
 */

#include "cpu1_interrupts.h"

//
// cla1Isr1 - CLA1 ISR 1
//
__interrupt void cla1Isr1()
{
    //BreakPoint, this function shoudn't be called
    ESTOP0;

    // Clear Interrupt Flag
    Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP11);
}

//
// cla1Isr2 - CLA1 ISR 2
//
__interrupt void cla1Isr2()
{
    //BreakPoint, this function shoudn't be called
    ESTOP0;

    // Clear Interrupt Flag
    Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP11);
}

//
// cla1Isr3 - CLA1 ISR 3
//
__interrupt void cla1Isr3()
{
    //BreakPoint, this function shoudn't be called
    ESTOP0;

    // Clear Interrupt Flag
    Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP11);
}

//
// cla1Isr4 - CLA1 ISR 4
//
__interrupt void cla1Isr4()
{
    //BreakPoint, this function shoudn't be called
    ESTOP0;

    // Clear Interrupt Flag
    Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP11);
}

//
// cla1Isr5 - CLA1 ISR 5
//
__interrupt void cla1Isr5()
{
    //BreakPoint, this function shoudn't be called
    ESTOP0;

    // Clear Interrupt Flag
    Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP11);
}

//
// cla1Isr6 - CLA1 ISR 6
//
__interrupt void cla1Isr6()
{
    //BreakPoint, this function shoudn't be called
    ESTOP0;

    // Clear Interrupt Flag
    Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP11);
}

//
// cla1Isr7 - CLA1 ISR 7
//
__interrupt void cla1Isr7()
{
    //BreakPoint, this function shoudn't be called
    ESTOP0;

    // Clear Interrupt Flag
    Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP11);
}

//
// cla1Isr8 - CLA1 ISR 8
//
__interrupt void cla1Isr8()
{
    //BreakPoint, this function shoudn't be called
    ESTOP0;

    // Clear Interrupt Flag
    Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP11);
}
