
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tests_lib.h"

typedef int	(*fct_test)(void);

struct test {
	fct_test	fct;
	char const	name[48];
};

static void		test(fct_test fct_test, char const * fct_name)
{
	if (fct_test() == ERROR) {
		dprintf(2, "\033[0%dm%s\033[0m: %s\n\n",
				RED_OCTAL, FAILURE, fct_name);
	}
	else {
		dprintf(1, "\033[0%dm%s\033[0m: %s\n\n",
				GREEN_OCTAL, SUCCESS, fct_name);
	}
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
	};

	if (argc == 1) {
		for (unsigned long i = 0; i < TAB_LEN(test_conf); i++) {
			test(test_conf[i].fct, test_conf[i].name);
		}
	}
	else {
		for (int j = 1; j < argc; j++) {
			for (unsigned long i = 0; i < TAB_LEN(test_conf); i++) {
				if (strcmp(test_conf[i].name, argv[j]) == 0) {
					test(test_conf[i].fct, test_conf[i].name);
					break ;
				}
			}
		}
	}
	return EXIT_SUCCESS;
}
