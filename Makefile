# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/08/28 14:28:00 by mmeisson          #+#    #+#              #
#    Updated: 2019/07/06 09:45:55 by jpriou           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= libfts_test

CC				= clang

override CFLAGS	+= -MD -Wall -Werror -Wextra -Wno-unused-variable -g

VPATH			= ./srcs/:


SRCS			= main.c test_bzero.c test_isalpha.c test_isdigit.c
SRCS			+= test_isalnum.c test_isascii.c test_isprint.c
SRCS			+= test_tolower.c test_toupper.c test_strlen.c
SRCS			+= test_puts.c test_strcat.c test_memcpy.c test_memset.c
SRCS			+= test_strdup.c test_hard_loop.c

INCS_PATHS		= ./incs/
INCS			= $(addprefix -I,$(INCS_PATHS))

OBJS_PATH		= ./.objs/
OBJS_NAME		= $(SRCS:.c=.o)
OBJS			= $(addprefix $(OBJS_PATH), $(OBJS_NAME))

DEPS			= $(OBJS:.o=.d)

LIB_PATHS		= ./../
LIBS			= $(addprefix -L,$(LIB_PATHS))

LDFLAGS			= $(LIBS) -lfts

.PHONY: all
all: $(NAME) test_cat

test_cat: ../libfts.a
	$(CC) test_cat.c -o test_cat $(LDFLAGS)

$(NAME): $(OBJS) ../libfts.a
	$(CC) $^ -o $@ $(LDFLAGS)

$(OBJS_PATH)%.o: $(SRCS_PATHS)%.c Makefile
	@mkdir -p $(OBJS_PATH)
	$(CC) $(CFLAGS) $(INCS) -o $@ -c $<

.PHONY: clean
clean:
	rm -rf $(OBJS_PATH)

.PHONY: fclean
fclean:
	rm -rf $(OBJS_PATH)
	rm -f $(NAME)
	rm -f test_cat

.PHONY: re
re: fclean all

-include $(DEPS)
