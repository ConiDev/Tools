# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nduvelle <nduvelle@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/09 17:42:35 by nduvelle          #+#    #+#              #
#    Updated: 2021/07/17 20:38:28 by nduvelle         ###   ########.fr        #
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
		@printf "Creating libft.a\n"
		@ar -rcs ${NAME} ${OBJS}

all:		${NAME}

clean:
		@printf "Cleaning up libft object\n"
		@${RM} ${OBJS}

fclean:		clean
		@printf "Cleaning up libft binaries\n"
		@${RM} ${NAME}

re:		fclean all

norm:
		norminette header/ srcs/

.PHONY:		all clean fclean re norm
