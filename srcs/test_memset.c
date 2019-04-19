
#include "tests_lib.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void		*ft_memset(void *dst, int c, unsigned long len);

extern int		g_verbose;

static int		unit_test_memset(unsigned long len)
{
	char const	fmt[] = "\033[0%dm%s\033[0m test ft_memset on size == %lu ";
	char const	*status_str;
	int			status, status_color;
	char		mem_ft[len + 15], mem_off[len + 15];
	void		*res;
	int			diff;
	int			fd;

	memset(mem_ft, '0', len + 14);
	memset(mem_off, '0', len + 14);
	mem_ft[len + 14] = 0;
	mem_off[len + 14] = 0;

	memset(mem_off, 'a', len);

	SAVE_REGISTERS();
	res = ft_memset(mem_ft, 'a', len);

	if (CHECK_REGISTERS() != 0)
	{
		fd = 2;
		status_str = FAILURE "REGISTER";
		status_color = RED_OCTAL;
		status = ERROR;
	}
	else
	{
		diff = memcmp(mem_off, mem_ft, len);

		if (res != mem_ft) {
			fd = 2;
			status_str = FAILURE " res does not match";
			status_color = RED_OCTAL;
			status = ERROR;
		}
		else if (diff == 0) {
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
	}

	if (g_verbose == NORMAL || g_verbose == FULL)
	{
		dprintf(fd, fmt, status_color, status_str, len);
		if (g_verbose == FULL)
			dprintf(fd, "(off: '%s', mine: '%s')", mem_off, mem_ft);
		dprintf(fd, "\n");
	}
	return status;
}

int			test_memset(void)
{
	int status = WORKS;

	for (unsigned long i = 0; i < 32; i++) {
		if (unit_test_memset(i) == ERROR) {
			status = ERROR;
		}
	}
	return status;
}
