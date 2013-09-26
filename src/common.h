/*
 * Copyright (c) Michael Tharp <gxti@partiallystapled.com>
 *
 * This file is distributed under the terms of the MIT License.
 * See the LICENSE file at the top of this tree, or if it is missing a copy can
 * be found at http://opensource.org/licenses/MIT
 */


#ifndef _COMMON_H
#define _COMMON_H

#include <stddef.h>
#include <stdint.h>

#include "board.h"
#include "app_config.h"

#include <CoOS.h>
#include <stm32f10x.h>

/* stupid trick to work around cpp macro handling */
#define _PASTE(x,y) x##y
#define _PASTE2(x,y) _PASTE(x,y)

#define HALT()				while(1) {}
#define ASSERT(x)			if (!(x)) { HALT(); }
#define MS2ST(msec)			((((msec - 1L) * CFG_SYSTICK_FREQ) / 1000L) + 1L)
#define S2ST(seconds)		(seconds * CFG_SYSTICK_FREQ)
#define SET_BITS(var, mask, value) \
	(var) = ((var) & ~(mask)) | ((value) & (mask))

#define TIMEOUT_NOBLOCK		0
#define TIMEOUT_FOREVER		-1

#define EERR_OK				0
#define EERR_TIMEOUT		-1
#define EERR_FAULT			-2
#define EERR_INVALID		-3

extern uint32_t _irq_disabled;
#define DISABLE_IRQ()		do { __disable_irq(); _irq_disabled++; } while(0)
#define ENABLE_IRQ()		do { if (--_irq_disabled == 0) { __enable_irq(); } } while(0)
#define SAVE_ENABLE_IRQ(save) do { (save) = _irq_disabled; _irq_disabled = 0; __enable_irq(); } while(0)
#define RESTORE_DISABLE_IRQ(save) do { __disable_irq(); if ((_irq_disabled = (save)) == 0) { __enable_irq(); } } while(0)

#define GPIO_ON(pfx)		_PASTE2(pfx, _PAD)->BSRR = _PASTE2(pfx, _PIN);
#define GPIO_OFF(pfx)		_PASTE2(pfx, _PAD)->BRR  = _PASTE2(pfx, _PIN);

#endif
