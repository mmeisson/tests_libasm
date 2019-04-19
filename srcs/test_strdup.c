
#include "tests_lib.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

char		*ft_strdup(char *str);

extern int		g_verbose;

static int		unit_test_strdup(char *test)
{
	char const	fmt[] = "%s test ft_strdup on string '%s'";
	int			status;
	char		*str_ft, *str_off;
	int			diff;
	int			fd;

	str_off = strdup(test);
	SAVE_REGISTERS();
	str_ft = ft_strdup(test);

	if (CHECK_REGISTERS() != 0)
	{
		fd = 2;
		status = REGISTER;
	}
	else
	{
		diff = strcmp(str_off, str_ft);

		if (diff == 0) {
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
		dprintf(fd, fmt, STATE_STR[status], test);
		if (g_verbose == FULL)
			dprintf(fd, "(off: '%s', mine: '%s')", str_off, str_ft);
		dprintf(fd, "\n");
	}
	if (str_off) {
		free(str_off);
	}
	if (str_ft) {
		free(str_ft);
	}
	return status;
}

int			test_strdup(void)
{
	char	*strs[] = {
		"",
		"a",
		"ab",
		"abc",
		"abaabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcbcc",
	};
	int status = WORKS;
	int	test_status;

	for (unsigned long i = 0; i < TAB_LEN(strs); i++) {
		if ((test_status = unit_test_strdup(strs[i])) > status) {
			status = test_status;
		}
	}
	return status;
}
