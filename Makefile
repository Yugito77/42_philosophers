# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hcherpre <hcherpre@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/11 15:51:01 by hcherpre          #+#    #+#              #
#    Updated: 2022/04/11 11:17:34 by hcherpre         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME     = philo

CC     = gcc

RM     = rm -rf

SRCS     =  philo.c ft_atoi.c init.c thread.c routine.c utils.c\
			print.c is_dead.c ft_free.c

OBJS        = ${SRCS:.c=.o}

CFLAGS     = -Wall -Wextra -Werror -pthread #-fsanitize=thread

$(NAME): ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}

all:    ${NAME}

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re:    fclean all