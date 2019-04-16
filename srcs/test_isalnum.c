
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "tests_lib.h"

int		ft_isalnum(int c);

extern int		g_verbose;

static int		unit_test_isalnum(int test)
{
	char const	fmt[] = "\033[0%dm%s\033[0m test ft_isalnum on char %c (%#x)";
	char const	*status_str;
	int			status, status_color;
	int			ft_res, off_res;
	int			fd = 0;

	ft_res = ft_isalnum(test);
	off_res = isalnum(test);
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

int			test_isalnum(void)
{
	char const		str[] = "abcxyzABCZYX`{@[0123456789/:";
	const size_t	len = strlen(str);
	int const		tests[] = {
		0, 0xff, 0x100, 0x1ff, 0x100 | 'a',
		0x10000 | 'z', 0x10000 | 'A', 0x100 | 'Z'
	};
	int				status = WORKS;

	for (size_t i = 0; i < len; i++) {
		if (unit_test_isalnum(str[i]) == ERROR) {
			status = ERROR;
		}
	}
	for (size_t i = 0; i < TAB_LEN(tests); i++) {
		if (unit_test_isalnum(tests[i]) == ERROR) {
			status = ERROR;
		}
	}
	return status;
}

