
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "tests_lib.h"

int		ft_toupper(int c);

extern int		g_verbose;

static int		unit_test_toupper(int test)
{
	char const	fmt[] = "\033[0%dm%s\033[0m test ft_toupper on char %c (%#x)";
	char const	*status_str;
	int			status, status_color;
	int			ft_res, off_res;
	int			fd = 0;

	off_res = toupper(test);

	SAVE_REGISTERS();
	ft_res = ft_toupper(test);

	if (CHECK_REGISTERS() != 0)
	{
		fd = 2;
		status_str = FAILURE "REGISTER";
		status_color = RED_OCTAL;
		status = ERROR;
	}
	else if (ft_res == off_res) {
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
			dprintf(fd, "(off: %d, mine: %d)", off_res, ft_res);
		dprintf(fd, "\n");
	}
	return status;
}

int			test_toupper(void)
{
	int				status = WORKS;

	for (int i = -10; i < 127; i++) {
		if (unit_test_toupper(i) == ERROR) {
			status = ERROR;
		}
	}
	for (int i = 0x010000; i < 0x010100; i++) {
		if (unit_test_toupper(i) == ERROR) {
			status = ERROR;
		}
	}
	return status;
}

