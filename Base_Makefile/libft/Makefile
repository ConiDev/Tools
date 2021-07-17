# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nduvelle <nduvelle@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/09 17:42:35 by nduvelle          #+#    #+#              #
#    Updated: 2021/07/17 21:11:01 by nduvelle         ###   ########.fr        #
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
		@${CC} ${CFLAGS} -c -o $@ $^

${NAME}:	${OBJS} ${HEADER}
		@printf "\001\e[1;32m\002Creating libft.a\n"
		@ar -rcs ${NAME} ${OBJS}

all:		${NAME}

clean:
		@printf "\001\e[1;35m\002Cleaning up libft object\n"
		@${RM} ${OBJS}

fclean:		clean
		@printf "\001\e[1;35m\002Cleaning up libft binaries\n"
		@${RM} ${NAME}

re:		fclean all

norm:
		norminette header/ srcs/

.PHONY:		all clean fclean re norm
