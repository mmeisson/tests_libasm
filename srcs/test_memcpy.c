
#include "tests_lib.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void		*ft_memcpy(void *dst, const char *src, unsigned long len);

extern int		g_verbose;

static int		unit_test_memcpy(void *test, unsigned long len)
{
	char const	fmt[] = "%s test ft_memcpy on mem '%s'(size == %lu) ";
	int			status;
	char		*mem_ft = NULL, *mem_off = NULL;
	char		*res;
	int			diff;
	int			fd;

	mem_ft = malloc(len);
	mem_off = malloc(len);

	memcpy(mem_off, test, len);

	SAVE_REGISTERS();
	res = ft_memcpy(mem_ft, test, len);

	if (CHECK_REGISTERS() != 0)
	{
		fd = 2;
		status = REGISTER;
	}
	else
	{
		diff = memcmp(mem_off, mem_ft, len);

		if (res != mem_ft) {
			fd = 2;
			status = ERROR;
		}
		else if (diff == 0) {
			fd = 1;
			status = WORKS;
		}
		else {
			fd = 2;
			status = ERROR;
		}
	}

	if (g_verbose == NORMAL || g_verbose == FULL)
	{
		dprintf(fd, fmt, STATE_STR[status], test, len);
		if (g_verbose == FULL)
			dprintf(fd, "(off: '%*s', mine: '%*s')", (int)len, mem_off, (int)len, mem_ft);
		dprintf(fd, "\n");
	}
	if (mem_off) {
		free(mem_off);
	}
	if (mem_ft) {
		free(mem_ft);
	}
	return status;
}

int			test_memcpy(void)
{
	char	*strs[] = {
		"",
		"a",
		"ab",
		"abc",
		"abaabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcbcc",
	};
	int status = WORKS;

	for (unsigned long i = 0; i < TAB_LEN(strs); i++) {
		if (unit_test_memcpy(strs[i], strlen(strs[i]) + 1) != WORKS) {
			status = ERROR;
		}
	}
	return status;
}
