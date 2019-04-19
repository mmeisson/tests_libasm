
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "tests_lib.h"

int		ft_puts(const char *str);

extern int g_verbose;

char	*get_puts(char *test, unsigned long test_size, int (*p_puts)(const char *str))
{
	int		pi[2];
	char	buffer[test_size + 10];
	char	*str = NULL;

	pipe(pi);
	if (fork() == 0) {
		/* child */
		close(pi[0]);
		dup2(pi[1], 1);
		p_puts(test);
		close(pi[1]);
		exit(0);
	}
	else {
		/* father */
		bzero(buffer, test_size + 10);
		close(pi[1]);
		read(pi[0], buffer, test_size + 9);
		close(pi[0]);
		str = strdup(buffer);
	}
	return str;
}

int		unit_test_puts(char *test, unsigned long test_size)
{
	int			diff;
	int			fd;
	char const	fmt[] = "%s test ft_puts on string '%s'";
	int			status;
	char		*str_off, *str_mine;

	str_off = get_puts(test, test_size, puts);
	str_mine = get_puts(test, test_size, ft_puts);
	diff = strcmp(str_off, str_mine);
	if (diff == 0) {
		fd = 1;
		status = WORKS;
	}
	else {
		fd = 2;
		status = ERROR;
	}

	if (g_verbose == NORMAL || g_verbose == FULL)
	{
		dprintf(fd, fmt, STATE_STR[status], test);
		if (g_verbose == FULL)
			dprintf(fd, "(off: '%s', mine: '%s')", str_off, str_mine);
		dprintf(fd, "\n");
	}
	if (str_off) {
		free(str_off);
	}
	if (str_mine) {
		free(str_mine);
	}
	return status;
}

struct tests {
	char			*str;
	unsigned long	len;
};

int		test_puts(void)
{
	int				status = WORKS;
	struct tests	units[] = {
		{"", 0},
		{"a", 1},
		{"ab", 2},
		{"abc", 3},
		{"Une chaine de caractere nettement plus longue", 46},
#ifdef __APPLE__
		{NULL, 0},
#endif
	};
	int			test_status;

	for (unsigned long i = 0; i < TAB_LEN(units); i++) {
		if ((test_status = unit_test_puts(units[i].str, units[i].len)) > status) {
			status = test_status;
		}
	}
	return status;
}
