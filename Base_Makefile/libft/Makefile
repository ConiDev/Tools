# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/09 17:42:35 by nduvelle          #+#    #+#              #
#    Updated: 2021/07/19 22:19:51 by bledda           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -rf

HEADER		= header/libft.h

FOLDER		= srcs/

SRCS		= ft_crash.c

SRC			= $(addprefix ${FOLDER}, ${SRCS})

OBJS		= ${SRC:.c=.o}

${NAME}:	${OBJS} ${HEADER}
			@printf $(green)
			@printf "Creating libft.a\n"
			@ar -rcs ${NAME} ${OBJS}
			@printf $(reset)

%.o: %.c
			@${CC} ${CFLAGS} -c -o $@ $^

all:		${NAME}

clean:
			@printf $(magenta)
			@printf "Cleaning up libft object\n"
			@${RM} ${OBJS}
			@printf $(reset)

fclean:		clean
			@printf $(magenta)
			@printf "Cleaning up libft binaries\n"
			@${RM} ${NAME}
			@printf $(reset)

re:			fclean all

norm:
			norminette header/ srcs/

.PHONY:		all clean fclean re norm

#	COLOR SETTING	############
black 				= "\e[1;30m"
red 				= "\e[1;31m"
green 				= "\e[1;32m"
yellow 				= "\e[1;33m"
blue 				= "\e[1;34m"
magenta 			= "\e[1;35m"
cyan 				= "\e[1;36m"
white 				= "\e[1;37m"

bg_black 			= "\e[40m"
bg_red 				= "\e[41m"
bg_green 			= "\e[42m"
bg_yellow 			= "\e[43m"
bg_blue 			= "\e[44m"
bg_magenta 			= "\e[45m"
bg_cyan 			= "\e[46m"
bg_white 			= "\e[47m"

reset 				= "\e[0m"
################################
