
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

void	ft_cat(int);

void	dump(void *mem, unsigned long len)
{
	unsigned char	*m = mem;

	for (unsigned long i = 0; i < len; i++) {
		if (i % 16 == 0) {
			printf("\n%.4ld\t", i);
		}
		printf("%.2hhx ", m[i]);
	}
	printf("\n");
}

int		main(int ac, char **av)
{
	int		fd;

	if (ac == 1) {
		dprintf(2, "Usage: %s filename [filename ...]", av[0]);
	}
	for (int i = 1; i < ac; i++) {
		fd = open(av[i], O_RDONLY);
		if (fd == -1) {
			perror(av[i]);
		}
		ft_cat(fd);
		close(fd);
	}
	ft_cat(-42);
	ft_cat(42);
	return 0;
}
