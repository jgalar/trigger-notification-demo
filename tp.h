/*
 * Copyright (C) 2020 Jérémie Galarneau <jeremie.galarneau@efficios.com>
 *
 * SPDX-License-Identifier: MIT
 *
 */

#undef TRACEPOINT_PROVIDER
#define TRACEPOINT_PROVIDER trigger_exemple

#undef TRACEPOINT_INCLUDE
#define TRACEPOINT_INCLUDE "./tp.h"

#if !defined(_TRACEPOINT_TRIGGER_EXEMPLE_H) || defined(TRACEPOINT_HEADER_MULTI_READ)
#define _TRACEPOINT_TRIGGER_EXEMPLE_H

#include <lttng/tracepoint.h>

TRACEPOINT_EVENT(trigger_exemple, my_event,
	TP_ARGS(int, iteration),
	TP_FIELDS(
		ctf_integer(uint64_t, iteration, iteration)
	)
)

#endif /* _TRACEPOINT_TRIGGER_EXEMPLE_H */

#include <lttng/tracepoint-event.h>
