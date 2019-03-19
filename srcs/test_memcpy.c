
#include "tests_lib.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void		*ft_memcpy(void *dst, const char *src, unsigned long len);

static int		unit_test_memcpy(void *test, unsigned long len)
{
	char const	fmt[] = "\033[0%dm%s\033[0m test ft_memcpy on mem '%s'(size == %lu) ";
	char const	*status_str;
	int			status, status_color;
	char		*mem_ft = NULL, *mem_off = NULL;
	char		*res;
	int			diff;
	int			fd;

	mem_ft = malloc(len);
	mem_off = malloc(len);
	memcpy(mem_off, test, len);
	res = ft_memcpy(mem_ft, test, len);
	diff = memcmp(mem_off, mem_ft, len);
	if (res != mem_ft) {
		fd = 2;
		status_str = FAILURE " ret does not match";
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

#if VERBOSE == NORMAL || VERBOSE == FULL
	dprintf(fd, fmt, status_color, status_str, test, len);
# if VERBOSE == FULL
	dprintf(fd, "(off: '%*s', mine: '%*s')", (int)len, mem_off, (int)len, mem_ft);
# endif
	dprintf(fd, "\n");
#endif
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
		if (unit_test_memcpy(strs[i], strlen(strs[i]) + 1) == ERROR) {
			status = ERROR;
		}
	}
	return status;
}
