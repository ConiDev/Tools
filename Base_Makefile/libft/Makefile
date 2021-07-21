# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nduvelle <nduvelle@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/09 17:42:35 by nduvelle          #+#    #+#              #
#    Updated: 2021/07/21 19:13:33 by nduvelle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a

CC		= gcc
RM		= rm -f

CFLAGS		= -Wall -Wextra -Werror

FOLDER_HEADER	= header/
FOLDER_SRCS	= srcs/

HEADER_SRCS	= libft.h
SRCS		= ft_crash.c

SRC		= $(addprefix ${FOLDER_SRCS}, ${SRCS})
HEADER		= $(addprefix ${FOLDER_HEADER}, ${HEADER_SRCS})

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
