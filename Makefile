# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmeisson <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/08/28 14:28:00 by mmeisson          #+#    #+#              #
#    Updated: 2019/04/19 18:26:21 by mmeisson         ###   ########.fr        #
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
SRCS			+= test_strdup.c

INCS_PATHS		= ./incs/
INCS			= $(addprefix -I,$(INCS_PATHS))

OBJS_PATH		= ./.objs/
OBJS_NAME		= $(SRCS:.c=.o)
OBJS			= $(addprefix $(OBJS_PATH), $(OBJS_NAME))

DEPS			= $(OBJS:.o=.d)

LIB_PATHS		= ./../
LIBS			= $(addprefix -L,$(LIB_PATHS))

LDFLAGS			= $(LIBS) -lfts


all: $(NAME) test_cat

test_cat:
	$(CC) $^ -o test_cat $(LDFLAGS) test_cat.c

$(NAME): $(OBJS)
	$(CC) $^ -o $@ $(LDFLAGS)

$(OBJS_PATH)%.o: $(SRCS_PATHS)%.c Makefile
	@mkdir -p $(OBJS_PATH)
	$(CC) $(CFLAGS) $(INCS) -o $@ -c $<

clean:
	rm -rf $(OBJS_PATH)

fclean:
	rm -rf $(OBJS_PATH)
	rm -f $(NAME)
	rm -f test_cat

re: fclean all

-include $(DEPS)
