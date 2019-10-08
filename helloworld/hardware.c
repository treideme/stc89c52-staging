#include <stdint.h>
#include <mcs51/8051.h>
#include "hardware.h"


void hardware_init() {
    EA = 0; // Disable all interrupts

    // Power control
    PCON = INIT_PCON;

    // Configure watchdog
    WDT_CONTR = INIT_WDT_CONTR;

    // Enable all desired interrupts
    IE = INIT_IE;
}
