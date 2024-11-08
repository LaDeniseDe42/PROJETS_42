# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/20 13:52:42 by qdenizar          #+#    #+#              #
#    Updated: 2023/04/20 14:26:21 by qdenizar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.c utils.c utils2.c check_arg.c eat_for_your_life.c \
time_death_and_sleep.c check_arg2.c routine.c  \

NAME = philo

OBJS = ${SRC:.c=.o}
	
CC = gcc

CFLAGS = -pthread -Wall -Werror -Wextra

RM = rm -f

all: ${NAME}

$(NAME):	${OBJS}
	${CC} ${CFLAGS}  ${OBJS} ${FT_PRINTF} ${LIBMLX} -o ${NAME}	
	
debug:	${OBJS}
	${CC} ${CFLAGS}  ${OBJS} -fsanitize=address -o ${NAME}
	
debugg:	${OBJS}
	${CC} ${CFLAGS}  ${OBJS} -fsanitize=thread -o ${NAME}
	
clean:
	${RM} ${OBJS}

fclean:	clean
	${RM} ${NAME}


re:		fclean all

.PHONY: all clean fclean re