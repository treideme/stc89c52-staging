/**
 * @file stc89xx.h STC89cXX specific hardware registers.
 * @author Thomas Reidemeister <treideme@gmail.com>
 */
#ifndef _stc89xx_h_
#define _stc89xx_h_

#include <mcs51/compiler.h>
#include <mcs51/8051.h>

/******************************************************************************\
 * Public type definitions
\******************************************************************************/

/******************************************************************************\
 * Public macros
\******************************************************************************/

#define TF2_VECTOR      5   ///< 0x2B Timer 2
#define IE2_VECTOR      6   ///< 0x33 INT2
#define IE3_VECTOR      7   ///< 0x3B INT3

/******************************************************************************\
 * Public memory declarations
\******************************************************************************/

__sfr __at(0x8E) AUXR;      ///< Auxiliary Register 0.
__sfr __at(0xA2) AUXR1;     ///< Auxiliary Register 1.
__sfr __at(0xA2) SADDR;     ///< Slave Address.
__sfr __at(0xB7) IPH;       ///< Interrupt Priority High.
__sfr __at(0xB9) SADEN;     ///< Slave Address Mask.
__sfr __at(0xC0) XICON;     ///< Auxiliary Interrupt Control.
__sfr __at(0xC8) T2_CON;    ///< Timer/Counter 2 Control.
__sfr __at(0xC9) T2_MOD;    ///< Timer/Counter 2 Mode.
__sfr __at(0xCA) RCAP2L;    ///< Timer/Counter 2 Reload Capture Low.
__sfr __at(0xCB) RCAP2H;    ///< Timer/Counter 2 Reload Capture High.
__sfr __at(0xCC) TL2;       ///< Timer/Counter 2 Low.
__sfr __at(0xCD) TH2;       ///< Timer/Counter 2 High.
__sfr __at(0xE1) WDT_CONTR; ///< Watch-Dog-Timer Control Register.
__sfr __at(0xE2) ISP_DATA;  ///< ISP Data Flash Register.
__sfr __at(0xE3) ISP_ADDRH; ///< ISP Flash Address High.
__sfr __at(0xE4) ISP_ADDRL; ///< ISP Flash Address Low.
__sfr __at(0xE5) ISP_CMD;   ///< ISP Flash Command.
__sfr __at(0xE6) ISP_TRIG;  ///< ISP Flash Command Trigger.
__sfr __at(0xE7) ISP_CONTR; ///< ISP Flash Control.
__sfr __at(0xE8) P4;        ///< Port 4.

/******************************************************************************\
 * Public functions
\******************************************************************************/

#endif /* _stc89xx_h_ */
