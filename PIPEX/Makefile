# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/24 11:12:56 by qdenizar          #+#    #+#              #
#    Updated: 2023/03/16 15:01:46 by qdenizar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.c utils.c utils2.c my_childs.c apl_to_my_child.c  print_error.c\

NAME = pipex

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
	${MAKE} -C  ft_printf clean

fclean:	clean
	${RM} ${NAME}
	${MAKE} -C ft_printf fclean


re:		fclean all

.PHONY: all clean fclean re