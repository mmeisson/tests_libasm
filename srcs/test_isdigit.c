
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "tests_lib.h"

int		ft_isdigit(int c);

extern int		g_verbose;

static int		unit_test_isdigit(int test)
{
	char const	fmt[] = "%s test ft_isdigit on char %c (%#x)";
	int			status;
	int			ft_res, off_res;
	int			fd = 0;

	off_res = isdigit(test);

	SAVE_REGISTERS();
	ft_res = ft_isdigit(test);

	if (CHECK_REGISTERS() != 0)
	{
		fd = 2;
		status = REGISTER;
	}
	else if ((ft_res != 0 && off_res != 0) || (ft_res == 0 && off_res == 0)) {
		fd = 1;
		status = WORKS;
	}
	else {
		fd = 2;
		status = ERROR;
	}

	if (g_verbose == NORMAL || g_verbose == FULL)
	{
		dprintf(fd, fmt, STATE_STR[status], test, test);
		if (g_verbose == NORMAL || g_verbose == FULL)
		{
			dprintf(fd, "(off: %d, mine: %d)", off_res, ft_res);
		}
		dprintf(fd, "\n");
	}
	return status;
}

int			test_isdigit(void)
{
	char const		str[] = "azAZ`{@[0123456789/:";
	const size_t	len = strlen(str);
	int const		tests[] = {
		0, 0xff, 0x100, 0x1ff, 0x100 | 'a',
		0x10000 | 'z', 0x10000 | 'A', 0x100 | 'Z'
	};
	int				status = WORKS;
	int				test_status;

	for (size_t i = 0; i < len; i++) {
		if ((test_status = unit_test_isdigit(str[i])) > status) {
			status = test_status;
		}
	}
	for (size_t i = 0; i < TAB_LEN(tests); i++) {
		if ((test_status = unit_test_isdigit(str[i])) > status) {
			status = test_status;
		}
	}
	return status;
}

