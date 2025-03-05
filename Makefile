# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amedenec <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/19 00:53:32 by amedenec          #+#    #+#              #
#    Updated: 2024/11/19 00:53:32 by amedenec         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBC =	function.c ft_printf.c

SRCS = ${LIBC}

OBJS = ${SRCS:.c=.o}

NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Werror -Wextra -I ./

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
		ar -rsc ${NAME} ${OBJS}

all: 	${NAME}

clean:	
		rm -f ${OBJS}

fclean:	clean
		rm -f ${NAME}

re:	fclean all

.PHONY: all clean fclean re 
