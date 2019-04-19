
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "tests_lib.h"

unsigned long	ft_strlen(const char *str);

extern int	g_verbose;

static int	test_unit_strlen(int test)
{
	unsigned long	ft_res;
	unsigned long	off_res;
	char			str[test + 1];
	char const		fmt[] = "%s test ft_strlen with str %d long";
	int				fd;
	int				status;

	off_res = strlen(str);

	SAVE_REGISTERS();
	ft_res = ft_strlen(str);

	if (CHECK_REGISTERS() != 0)
	{
		fd = 2;
		status = REGISTER;
	}
	else if (ft_res == off_res) {
		fd = 1;
		status = WORKS;
	}
	else {
		fd = 2;
		status = ERROR;
	}

	if (g_verbose == NORMAL || g_verbose == FULL)
	{
		dprintf(fd, fmt, STATE_STR[status], test);
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
		if (test_unit_strlen(i) != WORKS) {
			status = ERROR;
		}
	}
	return status;
}
