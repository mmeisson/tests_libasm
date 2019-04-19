
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "tests_lib.h"

int		ft_isascii(int c);

extern int		g_verbose;

static int		unit_test_isascii(int test)
{
	char const	fmt[] = "\033[0%dm%s\033[0m test ft_isascii on char %c (%#x)";
	char const	*status_str;
	int			status, status_color;
	int			ft_res, off_res;
	int			fd = 0;

	ft_res = ft_isascii(test);
	off_res = isascii(test);
	if ((ft_res != 0 && off_res != 0) || (ft_res == 0 && off_res == 0)) {
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
		dprintf(fd, fmt, status_color, status_str, test, test);
		if (g_verbose == FULL)
		{
			dprintf(fd, "(off: %d, mine: %d)", off_res, ft_res);
		}
		dprintf(fd, "\n");
	}
	return status;
}

int			test_isascii(void)
{
	int				status = WORKS;

	for (int i = -10; i < 127; i++) {
		if (unit_test_isascii(i) == ERROR) {
			status = ERROR;
		}
	}
	for (int i = 0x010000; i < 0x010100; i++) {
		if (unit_test_isascii(i) == ERROR) {
			status = ERROR;
		}
	}
	return status;
}

