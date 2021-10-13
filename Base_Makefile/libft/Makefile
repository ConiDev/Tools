# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nduvelle <nduvelle@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/09 17:42:35 by nduvelle          #+#    #+#              #
#    Updated: 2021/10/13 14:59:31 by nduvelle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= libft.a
CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror

HEADER			= header/libft.h

FOLDER			= srcs/
SRCS			= ft_crash.c
SRC				= $(addprefix ${FOLDER}, ${SRCS})

OBJS			= ${SRC:.c=.o} ${SRC_CUSTOM:.c=.o}

%.o: %.c	${HEADER}
			@${CC} ${CFLAGS} -c -o $@ $<

${NAME}:	${OBJS}
			@printf "$(GREEN)Creating ${NAME} Librarie\n$(RES)"
			@ar -rcs ${NAME} ${OBJS}

all:		${NAME}

clean:
			@printf "$(RED)Destroying ${NAME} objects (*.o)\n$(RES)"
			@${RM} ${OBJS}

fclean:		clean
			@printf "$(RED)Destroying ${NAME} Librarie (*.a)\n$(RES)"
			@${RM} ${NAME}

re:			fclean all

norm:
			norminette srcs/ header/

.PHONY:		all clean fclean re norm

############################################################
#					COLOR SET
############################################################
RES			= \e[0m
RED			= \e[1;31m
GREEN		= \e[1;32m
