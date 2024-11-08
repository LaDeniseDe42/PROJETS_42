# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/17 15:31:15 by qdenizar          #+#    #+#              #
#    Updated: 2023/02/22 10:28:31 by qdenizar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.c utils.c utils_two.c utils_3.c check_arg.c \
how_much_number.c stock_and_convert.c lets_sort.c lets_sort_utils.c   \
move_your_tab_body.c lets_sort2.c lets_sort3.c lets_sort4.c \

NAME = push_swap

OBJS = ${SRC:.c=.o}
	
CC = gcc

CFLAGS = -Wall -Werror -Wextra -g3

FT_PRINTF = ft_printf/libftprintf.a

RM = rm -f

all: ${NAME}

$(NAME):	${OBJS}
	${MAKE} -C ft_printf
	${CC} ${CFLAGS}  ${OBJS} ${FT_PRINTF} -o ${NAME}
	
debug:	${OBJS}
	${MAKE} -C ft_printf
	${CC} ${CFLAGS}  ${OBJS} ${FT_PRINTF} -fsanitize=address -o ${NAME}

clean:
	${RM} ${OBJS}
	${MAKE} -C ft_printf clean

fclean:	clean
	${RM} ${NAME}
	${MAKE} -C ft_printf fclean


re:		fclean all

.PHONY: all clean fclean re libmlx