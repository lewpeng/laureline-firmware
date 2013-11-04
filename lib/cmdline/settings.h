/*
 * Copyright (c) Michael Tharp <gxti@partiallystapled.com>
 *
 * This file is distributed under the terms of the MIT License.
 * See the LICENSE file at the top of this tree, or if it is missing a copy can
 * be found at http://opensource.org/licenses/MIT
 */

#ifndef _CMDLINE_SETTINGS_H
#define _CMDLINE_SETTINGS_H

#include <stdint.h>

#define CLI_TYPE_IP4 1
#define CLI_TYPE_HEX 1


typedef enum {
	VAR_UINT32,
	VAR_BOOL,
#if CLI_TYPE_IP4
	VAR_IP4,
#endif
#if CLI_TYPE_HEX
	VAR_HEX,
#endif
	_
} vartype_e;


typedef struct {
	const char *name;
	const vartype_e type;
	void *ptr;
	uint8_t len;
} clivalue_t;


extern const clivalue_t value_table[];

void cli_cmd_set(char *cmdline);


#endif