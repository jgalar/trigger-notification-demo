/*
 * Copyright (C) 2020 Jérémie Galarneau <jeremie.galarneau@efficios.com>
 *
 * SPDX-License-Identifier: MIT
 *
 */

#include "tp.h"

#include <lttng/tracepoint.h>
#include <unistd.h>
#include <sys/time.h>
#include <time.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	uint64_t i;

	for (i = 0; i < UINT64_MAX; i++) {
		char time_str[64];
		struct timeval tv;
		time_t the_time;

		gettimeofday(&tv, NULL);
		the_time = tv.tv_sec;

		strftime(time_str, sizeof(time_str), "[%m-%d-%Y] %T",
				localtime(&the_time));
		printf("%s.%ld - Tracing event \"trigger_exemple:my_event\"\n", time_str, tv.tv_usec);

		tracepoint(trigger_exemple, my_event, i);
		sleep(2);
	}
	return 0;
}
