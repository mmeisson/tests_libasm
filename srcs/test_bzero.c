
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "tests_lib.h"

void			ft_bzero(void *ptr, size_t len);

extern int		g_verbose;

static int		unit_test_bzero(int test)
{
	char		str[25] = {0};
	int			len = 24;
	int			zeros = 0;

	memset(str, 'a', len);

	SAVE_REGISTERS();
	ft_bzero(str, test);

	if (CHECK_REGISTERS() != 0)
	{
		dprintf(2, "%s bzero %d\n", STATE_STR[REGISTER], test);
		return ERROR;
	}

	for (int i = 0; i < len; i++) {
		if (str[i] == 0) {
			zeros++;
		}
	}

	if (g_verbose == FULL)
	{
		for (int i = 0; i < len; i++) {
			printf("'%#hhx' ", str[i]);
		}
		printf("\n");
	}

	if (g_verbose == NORMAL || g_verbose == FULL)
	{
		if (test == zeros) {
			dprintf(1, "%s bzero %d\n", STATE_STR[WORKS], test);
		}
		else {
			dprintf(2, "%s bzero %d\n", STATE_STR[ERROR], test);
		}
	}
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
	int		test_status;

	for (int i = 0; i < 24; i++) {
		if ((test_status = unit_test_bzero(i)) > status) {
			status = test_status;
		}
	}
	return status;
}
