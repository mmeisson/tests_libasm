
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tests_lib.h"

typedef int	(*fct_test)(void);

struct test {
	fct_test	fct;
	char const	name[48];
};

int				g_verbose = VERBOSE;

static int		test(fct_test fct_test, char const * fct_name)
{
	int		res = fct_test();
	dprintf(2, "%s: %s\n\n",
			STATE_STR[res], fct_name);
	return res;
}

int		main(int argc, char **argv)
{
	struct test const		test_conf[] = {
		{test_bzero, "test_bzero"},
		{test_isalpha, "test_isalpha"},
		{test_isdigit, "test_isdigit"},
		{test_isalnum, "test_isalnum"},
		{test_isascii, "test_isascii"},
		{test_isprint, "test_isprint"},
		{test_tolower, "test_tolower"},
		{test_toupper, "test_toupper"},
		{test_strlen, "test_strlen"},
		{test_puts, "test_puts"},
		{test_strcat, "test_strcat"},
		{test_memcpy, "test_memcpy"},
		{test_memset, "test_memset"},
		{test_strdup, "test_strdup"},
		{test_hard_loop, "test_hard_loop"},
	};
	int		j = 1;
	int		res = 0;

	for (j = 1; j < argc; j++) {

		/*
		 * Arg parse
		 */

		if (strcmp("--help", argv[j]) == 0) {
			dprintf(2, "Usage :: %s [--help] [--verbose MINIMAL|NORMAL|FULL] [ tests_name ]\n", argv[0]);
			return 0;
		}

		else if (strcmp("--verbose", argv[j]) == 0) {
			j++;
			if (j >= argc) {
				dprintf(2, "Usage :: %s [--help] [--verbose MINIMAL|NORMAL|FULL] [ tests_name ]\n", argv[0]);
				return 1;
			}
			if (strcmp("0", argv[j]) == 0 || strcmp("MINIMAL", argv[j]) == 0) {
				g_verbose = MINIMAL;
			}
			else if (strcmp("1", argv[j]) == 0 || strcmp("NORMAL", argv[j]) == 0) {
				g_verbose = NORMAL;
			}
			else if (strcmp("2", argv[j]) == 0 || strcmp("FULL", argv[j]) == 0) {
				g_verbose = FULL;
			}
			else {
				dprintf(2, "Usage :: %s [--verbose MINIMAL|NORMAL|FULL] [ tests_name ]\n", argv[0]);
				return -1;
			}
		}
		else {
			break ;
		}
	}

	if (j >= argc) {
		for (unsigned long i = 0; i < TAB_LEN(test_conf); i++) {
			res += test(test_conf[i].fct, test_conf[i].name);
		}
	}
	else {
		for (; j < argc; j++) {
			unsigned long i;
			for (i = 0; i < TAB_LEN(test_conf); i++) {
				if (strcmp(test_conf[i].name, argv[j]) == 0) {
					res += test(test_conf[i].fct, test_conf[i].name);
					break ;
				}
			}
			if (i == TAB_LEN(test_conf)) {
				dprintf(2, "\033[0%dm%s\033[0m: %s :: test not found\n\n",
					YELLOW_OCTAL, ERR, argv[j]);
			}
		}
	}
	return res;
}
