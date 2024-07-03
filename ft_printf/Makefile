# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lnierobi <lnierobi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/04 11:54:03 by lnierobi          #+#    #+#              #
#    Updated: 2024/04/12 14:51:34 by lnierobi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	unsigned_decimal.c ft_printf.c hex_low.c hex_up.c \
			print_char.c print_digit.c print_int.c print_pointer.c print_str.c
OBJS	= $(SRCS:.c=.o)
CC		= cc
RM		=rm -f
CFLAGS	= -Wall -Wextra -Werror

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

NAME = libftprintf.a
all: $(NAME)
$(NAME): $(OBJS)
		ar rcs $(NAME) $(OBJS)
clean:
		$(RM) $(OBJS)
fclean: clean
		$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
