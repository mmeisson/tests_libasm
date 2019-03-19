
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "tests_lib.h"

int		ft_isprint(int c);

static int		unit_test_isprint(int test)
{
	char const	fmt[] = "\033[0%dm%s\033[0m test ft_isprint on char %c (%#x)";
	char const	*status_str;
	int			status, status_color;
	int			ft_res, off_res;
	int			fd = 0;

	ft_res = ft_isprint(test);
	off_res = isprint(test);
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

#if VERBOSE == NORMAL || VERBOSE == FULL
	dprintf(fd, fmt, status_color, status_str, test, test);
# if VERBOSE == FULL
	dprintf(fd, "(off: %d, mine: %d)", off_res, ft_res);
# endif
	dprintf(fd, "\n");
#endif
	return status;
}

int			test_isprint(void)
{
	int				status = WORKS;

	for (int i = -10; i <= 127; i++) {
		if (unit_test_isprint(i) == ERROR) {
			status = ERROR;
		}
	}
	for (int i = 0x010000; i < 0x010100; i++) {
		if (unit_test_isprint(i) == ERROR) {
			status = ERROR;
		}
	}
	return status;
}

