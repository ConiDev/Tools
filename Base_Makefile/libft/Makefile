# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nduvelle <nduvelle@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/09 17:42:35 by nduvelle          #+#    #+#              #
#    Updated: 2021/07/17 18:46:20 by nduvelle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a

CC		= gcc

RM		= rm -f

CFLAGS		= -Wall -Wextra -Werror

HEADER		= header/libft.h

FOLDER		= srcs/

SRCS		= ft_crash.c

SRC		= $(addprefix ${FOLDER}, ${SRCS})

OBJS		= ${SRC:.c=.o}

%.o: %.c
		${CC} ${CFLAGS} -c -o $@ $^

${NAME}:	${OBJS} ${HEADER}
		ar -rcs ${NAME} ${OBJS}

all:		${NAME}

clean:
		${RM} ${OBJS}

fclean:		clean
		${RM} ${NAME}

re:		fclean all

norm:
		norminette header/ srcs/

.PHONY:		all clean fclean re norm
