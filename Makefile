# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lnierobi <lnierobi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/10 10:34:37 by lnierobi          #+#    #+#              #
#    Updated: 2024/07/10 10:45:21 by lnierobi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PUSHSWAP_SRCS	=	push_swap.c

PUSH = $(PUSHSWAP_SRCS:.c=.o)
SERVER_OBJS = $(SERVER_SRCS:.c=.o)

CC		= cc
CFLAGS	= -Wall -Wextra -Werror -g

RM		= rm -f

LIBS = libft/libft.a\
		ft_printf/libftprintf.a

PUSHSWAP = push_swap


all: $(PUSHSWAP) $(SERVER)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(PUSHSWAP): $(PUSH) $(LIBS)
		$(CC) $(CFLAGS) $(PUSH) $(LIBS) -o $(PUSHSWAP)

$(LIBS):
		make -C libft
		make -C ft_printf
clean:
		$(RM) $(PUSH) $(SERVER_OBJS)
		make clean -C libft
		make clean -C ft_printf

fclean: clean
		$(RM) $(PUSHSWAP) $(SERVER)
		make -C libft fclean
		make -C ft_printf fclean

re:	fclean all