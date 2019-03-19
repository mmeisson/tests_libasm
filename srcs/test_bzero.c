
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tests_lib.h"

void			ft_bzero(void *ptr, size_t len);

static int		unit_test_bzero(int test)
{
	char		str[25] = {0};
	int			len = 24;
	int			zeros = 0;

	memset(str, 'a', len);
	ft_bzero(str, test);
	for (int i = 0; i < len; i++) {
		if (str[i] == 0) {
			zeros++;
		}
	}

#if VERBOSE == FULL
	for (int i = 0; i < len; i++) {
		printf("'%#hhx' ", str[i]);
	}
	printf("\n");
#endif

#if VERBOSE == NORMAL || VERBOSE == FULL
	if (test == zeros) {
		dprintf(1, "\033[0%dm%s\033[0m bzero %d\n", GREEN_OCTAL, SUCCESS, test);
	}
	else {
		dprintf(2, "\033[0%dm%s\033[0m bzero %d\n", RED_OCTAL, FAILURE, test);
	}
#endif
	if (test == zeros) {
		return WORKS;
	}
	else {
		return ERROR;
	}
}

int			test_bzero(void)
{
	int		status = WORKS;

	for (int i = 0; i < 24; i++) {
		if (unit_test_bzero(i) == ERROR) {
			status = ERROR;
		}
	}
	return status;
}
