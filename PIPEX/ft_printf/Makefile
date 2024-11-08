# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    MAKEFILE                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/22 17:04:32 by qdenizar          #+#    #+#              #
#    Updated: 2022/11/23 13:00:21 by qdenizar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



SRC = ft_printf.c ft_changelabase.c ft_putcharandco.c

NAME = libftprintf.a

OBJS = ${SRC:.c=.o}
	
AR = ar -rc

CC = gcc

CFLAGS = -Wall -Werror -Wextra -g3

RM=rm -f

all: ${NAME}

$(NAME):	${OBJS}
	${AR} ${NAME} ${OBJS}

clean:
	${RM} ${OBJS}

fclean:	clean
	${RM} ${NAME}

re:		fclean all

.PHONY: all clean fclean re