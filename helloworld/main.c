/**
 * @file main.c Main entry point for SDCC.
 * @author Thomas Reidemeister <treideme@gmail.com>
 *
 * This file contains the main entry point for SDCC it has to contain any
 * interrupt service routines and the main function.
 */
#include <mcs51/8051.h>
#include "hardware.h"

/******************************************************************************\
* Private type definitions
\******************************************************************************/

/******************************************************************************\
* Private macros
\******************************************************************************/

/******************************************************************************\
 * Private prototypes
\******************************************************************************/

/**
 * Delay routine.
 */
static void delay(unsigned int t);

/******************************************************************************\
 * External declarations
\******************************************************************************/

/******************************************************************************\
 * Private memory declarations
\******************************************************************************/

/******************************************************************************\
 * Public memory declarations
\******************************************************************************/

/******************************************************************************\
 * All Interrupt handlers.
\******************************************************************************/

/**
 * INT0 Interrupt handler.
 */
void INT0_interrupt() __interrupt(IE0_VECTOR) { }

/**
 * Timer0 Interrupt handler.
 */
void Timer0_interrupt() __interrupt(TF0_VECTOR) { }

/**
 * INT1 Interrupt handler.
 */
void INT1_interrupt() __interrupt(IE1_VECTOR) { }

/**
 * Timer1 Interrupt handler.
 */
void Timer1_interrupt() __interrupt(TF1_VECTOR) { }

/**
 * UART0 Interrupt handler.
 */
void UART0_interrupt() __interrupt(SI0_VECTOR) { }

/**
 * Timer2 Interrupt handler.
 */
void Timer2_interrupt() __interrupt(TF2_VECTOR) { }

/**
 * INT2 Interrupt handler.
 */
void INT2_interrupt() __interrupt(IE2_VECTOR) { }

/**
 * INT3 Interrupt handler.
 */
void INT3_interrupt() __interrupt(IE3_VECTOR) { }

/******************************************************************************\
 * Public functions
\******************************************************************************/

/**
 * Main program entry point.
 */
void main() {
    hardware_init();
    while (1) {
        P2_0 = !P2_0;
        delay(30000);
    }
}

/******************************************************************************\
* Private functions
\******************************************************************************/

static void delay(unsigned int t) {
    while (t--)
        ;
}

