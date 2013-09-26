#
# Copyright (c) Michael Tharp <gxti@partiallystapled.com>
#
# This file is distributed under the terms of the MIT License.
# See the LICENSE file at the top of this tree, or if it is missing a copy can
# be found at http://opensource.org/licenses/MIT
#

PROJECT = laureline
BOARD = boards/v5

SRCS = $(wildcard src/*.c)
SRCS += $(wildcard src/gps/*.c)
SRCS += $(wildcard src/periph/*.c)
SRCS += $(wildcard src/util/*.c)
SRCS += src/lwip/arch/sys_arch.c
SRCS += src/fatfs/diskio.c
SRCS += $(wildcard ports/*.c)
SRCS += $(wildcard CoOS/kernel/*.c)
SRCS += CoOS/portable/arch.c
SRCS += CoOS/portable/GCC/port.c
SRCS += fatfs/ff.c
SRCS += $(wildcard lwip/src/core/*.c)
SRCS += $(wildcard lwip/src/core/ipv4/*.c)
SRCS += $(wildcard lwip/src/core/api/*.c)
SRCS += $(wildcard lwip/src/api/*.c)
SRCS += lwip/src/netif/etharp.c
LDSCRIPT = ports/STM32F107xB.ld

PATH := /opt/tnt-20130915/bin:$(PATH)
CFLAGS = \
	-Isrc \
	-Isrc/conf \
	-Isrc/lwip \
	-Isrc/fatfs \
	-Iports \
	-ICoOS/kernel \
	-ICoOS/portable \
	-Ifatfs \
	-Ilwip/src/include \
	-Ilwip/src/include/ipv4 \
	-Ilwip/src/include/ipv6 \
	\
	-Wall -Wextra -Wstrict-prototypes \
	-Wno-unused-parameter \
	-Wno-main \
	-Wno-address
LDLIBS = -lm

include emk/rules.mk
