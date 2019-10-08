/**
 * @file hardware.h Project hardware configuration.
 * @author Thomas Reidemeister <treideme@gmail.com>
 */
#ifndef _hardware_h_
#define _hardware_h_

#include <mcs51/8051.h>
#include "stc89xx.h"

/******************************************************************************\
 * Public type definitions
\******************************************************************************/

/******************************************************************************\
 * Public macros
\******************************************************************************/

#define FREQ_SYS   12000000 // FSys for MCS-51 system

/*******************************************************************************
**  Binary constant macros
*/
#define B8(d)                   ((uint8_t)  0b##d)                    ///<  8-bit shorthand. @note Mask needs exactly 8 digits
#define B16(dmsb,dlsb)          ((uint16_t) 0b##dmsb##dlsb)           ///< 16-bit shorthand. @note Mask needs exactly 8,8 digits
#define B32(dmsb,db2,db3,dlsb)  ((uint32_t) 0b##dmsb##db2##db3##dlsb) ///< 32-bit shorthand. @note Mask needs exactly 8,8,8,8 digits

#include "pin.h"

#define INIT_PCON \
  B8(10000000) /**< PCON  Power Control Register. @verbatim
     00010000 = reset
     || |||||
     || ||||+-- (RW)  IDL  : Idle Mode flag, set to 1 for idle
     || |||+--- (RW)  PD   : Set to 1 to sleep, cleared on wake-up (reset)
     || ||+---- (RW)  GF0  : General flag 0
     || |+----- (RW)  GF1  : General flag 1
     || +------ (W0C) POF  : Power on flag (clear after boot)
     ||
     |+-------- (RW)  SMOD0: SM0/FE bit select for SCON.7
     +--------- (RW)  SMOD : UART0 slow (0) or fast mode (1) when T1 is used

  @endverbatim
*/

#define INIT_WDT_CONTR \
  B8(00000000) /**< WDT_CONTR  Watchdog control register. @verbatim
     00000000 = reset
       ||||||
       |||+++-- (RW)  PS   : Prescaler (see below)
       |||
       |||
       ||+----- (RW)  IDLE : When set, WDT enabled in idle mode.
       |+------ (W1S) CLEAR: Clear watchdog timer (reset)
       +------- (RW)  EN   : Enable watchdog timer.

  | PS 0 | PS 1 | PS 2 | Prescale | WDT Overflow time @ 12Mhz
  |------|------|------|----------|--------------------------
  |  0   |  0   |  0   |    2     |   65.5  ms
  |  0   |  0   |  1   |    4     |  131.0  ms
  |  0   |  1   |  0   |    8     |  262.1  ms
  |  0   |  1   |  1   |   16     |  524.2  ms
  |  1   |  0   |  0   |   32     | 1048.5  ms
  |  1   |  0   |  1   |   64     | 2097    ms
  |  1   |  1   |  0   |  128     | 4194.3  ms
  |  1   |  1   |  1   |  256     | 8388.6  ms

  @endverbatim
*/

/*******************************************************************************
** Interrupts FIXME
*/

#define INIT_IE \
  B8(10010000) /**< IE  Interrupt Enable Register.
     00000000 = reset
     ||||||||
     |||||||+-- (RW)  EX0  : External Interrupt 0
     ||||||+--- (RW)  ET0  : Timer Interrupt 0
     |||||+---- (RW)  EX1  : External Interrupt 1
     ||||+----- (RW)  ET1  : Timer 1 Interrupt
     |||+------ (RO)  ES   : UART 0 Interrupt
     ||+------- (RO)  ET2  : Timer 2 Interrupt
     |+-------- (RW)  E_DIS: Global Interrupt Disable
     +--------- (RW)  EA   : Global Interrupt Enable

  | RSTF1 | RSTF0 | Description
  |-------|-------|---------------------------------------------------------------------
  |   0   |   0   | Software reset, source: bSW_RESET=1 and (bBOOT_LOAD=0 or bWDOG_EN=1)
  |   0   |   1   | Power-on reset, source: VDD33 pin voltage is lower than detection level
  |   1   |   0   | Watchdog reset, source: bWDOG_EN=1 and watchdog timeout
  |   1   |   1   | External pin is manually reset, source: En_P5.7_RESET=1 and P5.7 input high

  @endverbatim
*/

/******************************************************************************\
 * Public memory declarations
\******************************************************************************/

/******************************************************************************\
 * Public functions
\******************************************************************************/

void hardware_init();


#endif /* _hardware_h_ */
