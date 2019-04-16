
#include <stdio.h>
#include <string.h>
#include "tests_lib.h"

unsigned long	ft_strlen(const char *str);

extern int	g_verbose;

static int	test_unit_strlen(int test)
{
	unsigned long	ft_res;
	unsigned long	off_res;
	char			str[test + 1];
	char const		fmt[] = "\033[0%dm%s\033[0m test ft_strlen with str %d long";
	int				fd;
	char const		*status_str;
	int				status_color, status;

	ft_res = ft_strlen(str);
	off_res = strlen(str);
	if (ft_res == off_res) {
		fd = 1;
		status_str = SUCCESS;
		status_color = GREEN_OCTAL;
		status = WORKS;
	}
	else {
		fd = 2;
		status_str = FAILURE;
		status_color = RED_OCTAL;
		status = ERROR;
	}

	if (g_verbose == NORMAL || g_verbose == FULL)
	{
		dprintf(fd, fmt, status_color, status_str, test);
		if (g_verbose == FULL)
			dprintf(fd, "(off: %lu, mine: %lu)", off_res, ft_res);
		dprintf(fd, "\n");
	}

	return status;
}


int		test_strlen(void)
{
	int		status = WORKS;

	for (int i = 0; i < 32; i++) {
		if (test_unit_strlen(i) == ERROR) {
			status = ERROR;
		}
	}
	return status;
}
