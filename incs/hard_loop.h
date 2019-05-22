#ifndef HARD_LOOP_H
# define HARD_LOOP_H

#include <stdio.h>

# define HARD_LOOP(callback, ...) { \
	char	toto[] = "abc"; \
	\
	for (int _a = 0; _a < 3; _a++) { \
		for (int _b = 0; _b < 3; _b++) { \
			for (int _c = 0; _c < 3; _c++) { \
				for (int _d = 0; _d < 3; _d++) { \
					for (int _e = 0; _e < 3; _e++) { \
						for (int _f = 0; _f < 3; _f++) { \
							for (int _g = 0; _g < 3; _g++) { \
								for (int _h = 0; _h < 3; _h++) { \
									for (int _i = 0; _i < 3; _i++) { \
										for (int _j = 0; _j < 3; _j++) { \
											for (int _k = 0; _k < 3; _k++) { \
												for (int _l = 0; _l < 3; _l++) { \
													callback(__VA_ARGS__); \
													dprintf( \
														1, \
														"%c%c%c%c%c%c%c%c%c%c%c%c\n", \
														toto[_a], \
														toto[_b], \
														toto[_c], \
														toto[_d], \
														toto[_e], \
														toto[_f], \
														toto[_g], \
														toto[_h], \
														toto[_i], \
														toto[_j], \
														toto[_k], \
														toto[_l] \
													); \
												} \
											} \
										} \
									} \
								} \
							} \
						} \
					} \
				} \
			} \
		} \
	} \
}

# define HARD_LOOP_CAT(buff1, buff2) { \
	char	toto[] = "abc"; \
	\
	for (int _a = 0; _a < 3; _a++) { \
		for (int _b = 0; _b < 3; _b++) { \
			for (int _c = 0; _c < 3; _c++) { \
				for (int _d = 0; _d < 3; _d++) { \
					for (int _e = 0; _e < 3; _e++) { \
						for (int _f = 0; _f < 3; _f++) { \
							for (int _g = 0; _g < 3; _g++) { \
								for (int _h = 0; _h < 3; _h++) { \
									for (int _i = 0; _i < 3; _i++) { \
										for (int _j = 0; _j < 3; _j++) { \
											for (int _k = 0; _k < 3; _k++) { \
												for (int _l = 0; _l < 3; _l++) { \
													buff1[0] = 0; \
													ft_strcat(buff1, buff2); \
													dprintf( \
														1, \
														"%c%c%c%c%c%c%c%c%c%c%c%c\n", \
														toto[_a], \
														toto[_b], \
														toto[_c], \
														toto[_d], \
														toto[_e], \
														toto[_f], \
														toto[_g], \
														toto[_h], \
														toto[_i], \
														toto[_j], \
														toto[_k], \
														toto[_l] \
													); \
												} \
											} \
										} \
									} \
								} \
							} \
						} \
					} \
				} \
			} \
		} \
	} \
}

#endif
