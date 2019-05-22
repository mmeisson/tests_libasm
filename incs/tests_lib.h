
#ifndef TESTS_LIB_H
# define TESTS_LIB_H

typedef enum
{
	WORKS,
#define WORKS_STR		"\033[032m[WORKS]\033[0m"

	ERROR,
#define ERROR_STR		"\033[033m[ERROR]\033[0m"

	REGISTER,
#define REGISTER_STR	"\033[031m[REGV]\033[0m"
}		e_state;

static const char *STATE_STR[3] = {
	[WORKS] = WORKS_STR,
	[ERROR] = ERROR_STR,
	[REGISTER] = REGISTER_STR,
};

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


# define SAVE_REGISTERS() \
	uint64_t _A; \
	uint64_t _B; \
	uint64_t _C; \
	uint64_t _D; \
	uint64_t _E; \
	asm("mov %%r12,%0" : "=r"(_A)); \
	asm("mov %%r13,%0" : "=r"(_B)); \
	asm("mov %%r14,%0" : "=r"(_C)); \
	asm("mov %%r15,%0" : "=r"(_D)); \
	asm("mov %%rbx,%0" : "=r"(_E));

# define CHECK_REGISTERS() ({ \
	uint64_t _AA; \
	uint64_t _BB; \
	uint64_t _CC; \
	uint64_t _DD; \
	uint64_t _EE; \
	uint64_t _RES = 0; \
	asm("mov %%r12,%0" : "=r"(_AA)); \
	asm("mov %%r13,%0" : "=r"(_BB)); \
	asm("mov %%r14,%0" : "=r"(_CC)); \
	asm("mov %%r15,%0" : "=r"(_DD)); \
	asm("mov %%rbx,%0" : "=r"(_EE)); \
	if (_A != _AA) \
		_RES |= (1 << 0); \
	if (_B != _BB) \
		_RES |= (1 << 1); \
	if (_C != _CC) \
		_RES |= (1 << 2); \
	if (_D != _DD) \
		_RES |= (1 << 3); \
	if (_E != _EE) \
		_RES |= (1 << 4); \
	_RES; \
})



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
int		test_hard_loop(void);

#endif
