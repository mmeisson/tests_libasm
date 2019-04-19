
#include "tests_lib.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char		*ft_strcat(char *dst, const char *src);

extern int		g_verbose;

static int		unit_test_strcat(char *dst, char *src)
{
	char const	fmt[] = "%s test ft_strcat on strings '%s' '%s'";
	int			status;
	char		*str_ft = NULL, *str_off = NULL;
	char		*res;
	int			diff;
	int			fd;

	str_ft = malloc(strlen(dst) + strlen(src) + 1);
	str_off = malloc(strlen(dst) + strlen(src) + 1);
	strcpy(str_ft, dst);
	strcpy(str_off, dst);

	strcat(str_off, src);

	SAVE_REGISTERS();
	res = ft_strcat(str_ft, src);

	if (CHECK_REGISTERS() != 0)
	{
		fd = 2;
		status = REGISTER;
	}
	else
	{
		diff = strcmp(str_off, str_ft);

		if (res != str_ft) {
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
		dprintf(fd, fmt, STATE_STR[status], dst, src);
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

struct tests
{
	char	*dst;
	char	*src;
};

int			test_strcat(void)
{
	struct tests	strs[] = {
		{"", ""},
		{"a", ""},
		{"", "a"},
		{"abc", ""},
		{"", "abc"},
		{"abc", "abc"},
		{"a", "abc"},
		{"abc", "a"},
		{"Une longue ", "chaine de char"},
		{"Une longue chaine", "de char"},
		{"Une longue chaine de char", ""},
		{"", "Une longue chaine de char"},
	};
	int status = WORKS;
	int	test_status;

	for (unsigned long i = 0; i < TAB_LEN(strs); i++) {
		if ((test_status = unit_test_strcat(strs[i].dst, strs[i].src)) > status) {
			status = test_status;
		}
	}
	return status;
}
