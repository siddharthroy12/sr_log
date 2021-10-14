#ifndef SR_LOG
#define SR_LOG

#include <stdio.h>

enum
{
	LOG_ALL = 1 << 0,
	LOG_DISABLED = 1 << 1,
	LOG_INFO = 1 << 2,
	LOG_WARNING = 1 << 3,
	LOG_ERROR = 1 << 4
};

static char sr_log_levels = LOG_ALL;

static void sr_set_log_level(char flags)
{
	sr_log_levels = flags;
}

static void sr_trace_log(char level, char* message)
{
	if (((sr_log_levels & level) && !(sr_log_levels & LOG_DISABLED)) || (sr_log_levels & LOG_ALL))
	{
		if (level == LOG_INFO)
		{
			printf("INFO: ");
		}
		else if (level == LOG_WARNING)
		{
			printf("WARNING: ");
		}
		else if (level == LOG_ERROR)
		{
			printf("ERROR: ");
		}

		printf("%s\n", message);
	}
}

#endif
