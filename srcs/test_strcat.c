
#include "tests_lib.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char		*ft_strcat(char *dst, const char *src);

extern int		g_verbose;

static int		unit_test_strcat(char *dst, char *src)
{
	char const	fmt[] = "\033[0%dm%s\033[0m test ft_strcat on strings '%s' '%s'";
	char const	*status_str;
	int			status, status_color;
	char		*str_ft = NULL, *str_off = NULL;
	char		*res;
	int			diff;
	int			fd;

	str_ft = malloc(strlen(dst) + strlen(src) + 1);
	str_off = malloc(strlen(dst) + strlen(src) + 1);
	strcpy(str_ft, dst);
	strcpy(str_off, dst);
	res = ft_strcat(str_ft, src);
	strcat(str_off, src);
	diff = strcmp(str_off, str_ft);
	if (res != str_ft) {
		fd = 2;
		status_str = FAILURE " res does not match";
		status_color = RED_OCTAL;
		status = ERROR;
	}
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
		dprintf(fd, fmt, status_color, status_str, dst, src);
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

	for (unsigned long i = 0; i < TAB_LEN(strs); i++) {
		if (unit_test_strcat(strs[i].dst, strs[i].src) == ERROR) {
			status = ERROR;
		}
	}
	return status;
}
