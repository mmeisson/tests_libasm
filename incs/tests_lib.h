
#ifndef TESTS_LIB_H
# define TESTS_LIB_H

# define WORKS 0
# define ERROR 1

/*
 * Verbose == MINIMAL : Print only test's serie results
 * Verbose == NORMAL : Print every unit test's results
 * Verbose == FULL : Print additionnal data if available
*/
# define MINIMAL	0
# define NORMAL		1
# define FULL		2

# define VERBOSE NORMAL

# define GREEN_OCTAL 32
# define YELLOW_OCTAL 33
# define RED_OCTAL 31

# define SUCCESS	"[SUCCESS]"
# define FAILURE	"[FAILURE]"
# define ERR		"[ERROR]"

# define TAB_LEN(tab) (sizeof(tab) / sizeof(tab[0]))

int		test_bzero(void);
int		test_isupper(void);
int		test_islower(void);
int		test_isalpha(void);
int		test_isdigit(void);
int		test_isalnum(void);
int		test_isascii(void);
int		test_isprint(void);

int		test_tolower(void);
int		test_toupper(void);
int		test_strlen(void);
int		test_puts(void);
int		test_strcpy(void);
int		test_strcat(void);
int		test_memcpy(void);
int		test_memset(void);
int		test_strdup(void);

#endif
