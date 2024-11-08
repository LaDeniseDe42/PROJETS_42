# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/12 11:49:06 by qdenizar          #+#    #+#              #
#    Updated: 2023/01/25 13:43:42 by qdenizar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \
utils.c check_map.c img.c key.c key_utils.c check_map_utils.c chest.c anim.c\
anim_two.c free.c print_error.c \

NAME = so_long

OBJS = ${SRC:.c=.o}
	
CC = gcc

CFLAGS = -Wall -Werror -Wextra -g3

LIBMLX = "/Users/qdenizar/goinfre/MLX42/MLX42/libmlx42.a" -I include -lglfw -L "/Users/qdenizar/.brew/opt/glfw/lib"

FT_PRINTF = ft_printf/libftprintf.a

RM = rm -f

all: ${NAME}

$(NAME):	${OBJS}
	${MAKE} -C ft_printf
	${CC} ${CFLAGS}  ${OBJS} ${FT_PRINTF} ${LIBMLX} -o ${NAME}
	
debug:	${OBJS}
	${MAKE} -C ft_printf
	${CC} ${CFLAGS}  ${OBJS} ${FT_PRINTF} ${LIBMLX} -fsanitize=address -o ${NAME}

clean:
	${RM} ${OBJS}
	${MAKE} -C ft_printf clean

fclean:	clean
	${RM} ${NAME}
	${MAKE} -C ft_printf fclean


re:		fclean all

.PHONY: all clean fclean re libmlx