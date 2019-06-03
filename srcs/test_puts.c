
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
	/*
	 * How this function works ? ( man 2 dup ; man 2 pipe ; man 2 fork ; man 2 read )
	 *
	 * General explanations :
	 * To retrieve puts's output in a string, we create a second process.
	 * The second process will write in a file descriptor readable by the
	 * first process. So the first process just have to read the output
	 * with the associated syscall in order to have it in a string
	 *
	 *
	 * More in-depth :
	 *  'pipe' is a syscall that creates a pair of file descriptor, you can
	 *  read things on the first fd that have been written previously on
	 *  the second file descriptor.
	 *  'fork' creates a new process.
	 *  Using both 'pipe' and 'fork' allows to have to process that can
	 *  communicate ( through file descriptors ).
	 *  'dup2' allows to "replace" a file descriptor. Given the file
	 *  descriptor 1, if you dup2 3 on 1, it means that writting on 1
	 *  will more or less the same as writting on 3. So dupplicating
	 *  the second file descriptor given by 'pipe' on 1 means that using
	 *  puts, which is supposed to write on 1, will output in the pipe.
	 *
	 *  The first process, just have to read until the second process
	 *  writes.
	 *  Repeat the operation with ft_puts and puts, compare outputs
	 */
	pid_t	pid;
	int		pi[2];
	char	buffer[test_size + 10];
	char	*str = NULL;

	pipe(pi);
	if ((pid = fork()) == 0) {
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
		waitpid(pid, NULL, 0);
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
		{"Une chaine de caractere nettement plus longue", 45},
#ifdef __APPLE__
		{NULL, 0}, // man puts says that it has to be handled on macos. Not important imo
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
