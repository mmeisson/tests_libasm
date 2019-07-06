
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <fcntl.h>
#include "hard_loop.h"
#include "tests_lib.h"

void	ft_bzero(void *, size_t);
int		ft_isalnum(int);
int		ft_isalpha(int);
int		ft_isascii(int);
int		ft_isdigit(int);
int		ft_isprint(int);
void	*ft_memcpy(void *, void *, size_t);
void	*ft_memset(void *, int, size_t);
int		ft_puts(char *);
char	*ft_strcat(char *, char *);
char	*ft_strdup(char *);
size_t	ft_strlen(char *);
int		ft_tolower(int);
int		ft_toupper(int);

int			fd; // global

void	handle_signal(int sig)
{
	dup2(fd, 1);
	dprintf(2, ERROR_STR " Received signal %s (%d)\n", strsignal(sig), sig);
	exit(1);
}

int		test_hard_loop(void)
{
	char		buffer[124];

	fd = dup(1);
	dup2(open("/dev/null", O_RDONLY), 1);
	for (int i = 0; i < 20; i++) {
		signal(i, handle_signal);
	}

	dprintf(2, "Tests hard_loop bzero\n");
	HARD_LOOP(ft_bzero, buffer, 124);
	HARD_LOOP(ft_bzero, buffer, 0);
	HARD_LOOP(ft_bzero, buffer, 1);

	dprintf(2, "Tests hard_loop isalnum\n");
	HARD_LOOP(ft_isalnum, 'c');
	HARD_LOOP(ft_isalnum, '~');
	HARD_LOOP(ft_isalnum, -1);

	dprintf(2, "Tests hard_loop isalpha\n");
	HARD_LOOP(ft_isalpha, 'c');
	HARD_LOOP(ft_isalpha, '~');
	HARD_LOOP(ft_isalpha, -1);

	dprintf(2, "Tests hard_loop isascii\n");
	HARD_LOOP(ft_isascii, 'c');
	HARD_LOOP(ft_isascii, -1);

	dprintf(2, "Tests hard_loop isdigit\n");
	HARD_LOOP(ft_isdigit, '0');
	HARD_LOOP(ft_isdigit, '9');
	HARD_LOOP(ft_isdigit, '0' - 1);
	HARD_LOOP(ft_isdigit, '9' + 1);
	HARD_LOOP(ft_isdigit, -1);

	dprintf(2, "Tests hard_loop isprint\n");
	HARD_LOOP(ft_isprint, ' ');
	HARD_LOOP(ft_isprint, 'a');
	HARD_LOOP(ft_isprint, -1);

	dprintf(2, "Tests hard_loop memcpy\n");
	HARD_LOOP(ft_memcpy, buffer, "some content to put in string", 26);
	HARD_LOOP(ft_memcpy, buffer, "", 0);
	HARD_LOOP(ft_memcpy, buffer, "", 1);

	dprintf(2, "Tests hard_loop memset\n");
	HARD_LOOP(ft_memset, buffer, 'c', 1);
	HARD_LOOP(ft_memset, buffer, 'c', 0);
	HARD_LOOP(ft_memset, buffer, -1, 1);
	HARD_LOOP(ft_memset, buffer, -1, 0);
	HARD_LOOP(ft_memset, buffer, 'c', 124);
	HARD_LOOP(ft_memset, buffer, 'c', 124);
	HARD_LOOP(ft_memset, buffer, -1, 124);

	dprintf(2, "Tests hard_loop puts\n");
	buffer[0] = 0;
	HARD_LOOP(ft_puts, buffer);
	strcpy(buffer, "aaaaaaaaaaaaaa");
	HARD_LOOP(ft_puts, buffer);
	strcpy(buffer, "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa   aaaaaaaaaaaaaaaaaaaaaaa");
	HARD_LOOP(ft_puts, buffer);

	dprintf(2, "Tests hard_loop strcat\n");
	buffer[0] = 0;
	HARD_LOOP_STRCAT(buffer, "");
	HARD_LOOP_STRCAT(buffer, "s");
	HARD_LOOP_STRCAT(buffer, "sgfdsgsfd dsaf af dsafadsfadsf adf dsaf dasf dasf dasf da fdsa fdas ds");

	dprintf(2, "Tests hard_loop strdup\n");
	HARD_LOOP_STRDUP("");
	HARD_LOOP_STRDUP("some string");
	HARD_LOOP_STRDUP(" WEshshshshhshhh               fdfd df fdf dsf ");

	dprintf(2, "Tests hard_loop strlen\n");
	HARD_LOOP(ft_strlen, "");
	HARD_LOOP(ft_strlen, "some string");
	HARD_LOOP(ft_strlen, "some string                                   gsdfhg fsdg fsgdfs hgfdskgh fslkgh sdf");

	dprintf(2, "Tests hard_loop tolower\n");
	HARD_LOOP(ft_tolower, 'a');
	HARD_LOOP(ft_tolower, 'A');
	HARD_LOOP(ft_tolower, -1);

	dprintf(2, "Tests hard_loop toupper\n");
	HARD_LOOP(ft_toupper, 'a');
	HARD_LOOP(ft_toupper, 'A');
	HARD_LOOP(ft_toupper, -1);

	for (int i = 0; i < 20; i++) {
		signal(i, SIG_DFL);
	}
	close(1);
	dup2(fd, 1);
	close(fd);

	return 0;
}
