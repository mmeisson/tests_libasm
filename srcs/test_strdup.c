
#include "tests_lib.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char		*ft_strdup(char *str);

extern int		g_verbose;

static int		unit_test_strdup(char *test)
{
	char const	fmt[] = "\033[0%dm%s\033[0m test ft_strdup on string '%s'";
	char const	*status_str;
	int			status, status_color;
	char		*str_ft, *str_off;
	int			diff;
	int			fd;

	str_ft = ft_strdup(test);
	str_off = strdup(test);
	diff = strcmp(str_off, str_ft);
	if (diff == 0) {
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

	for (unsigned long i = 0; i < TAB_LEN(strs); i++) {
		if (unit_test_strdup(strs[i]) == ERROR) {
			status = ERROR;
		}
	}
	return status;
}
