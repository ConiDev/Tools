# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/24 19:05:27 by nduvelle          #+#    #+#              #
#    Updated: 2021/07/19 22:20:23 by bledda           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= testleaks

CC				= gcc
CFLAGS			= -Wall -Wextra -Werror
LDFLAGS			= -fsanitize=address
RM				= rm -rf

FOLDER_HEADER	= header/
FOLDER_SRCS		= srcs/
FOLDER_BNS		= srcs_bonus/

MAKE_EXT		= @make -s --no-print-directory -C

HEADER_SRC		= test.h
HEADER_BNS		= test_bonus.h
SRCS			= testleaks.c
SRCS_BNS		= testleaks_bonus.c

HDR				= $(addprefix ${FOLDER_HEADER}, ${HEADER_SRC})
HDR_BNS			= $(addprefix ${FOLDER_HEADER}, ${HEADER_BNS})
SRC				= $(addprefix ${FOLDER_SRCS}, ${SRCS})
SRC_BNS			= $(addprefix ${FOLDER_BNS}, ${SRCS_BNS})

OBJS			= ${SRC:.c=.o}
OBJS_BNS		= ${SRC_BNS:.c=.o}

LIB				= ./libft/libft.a

ifdef BONUS_LEAKS
OBJ				= ${OBJS_BNS}
HEADER			= ${HDR_BNS}
else
OBJ				= ${OBJS}
HEADER			= ${HDR}
endif

%.o: %.c
			@${CC} ${LDFLAGS} ${CFLAGS} -c -o $@ $^

${NAME}:	${OBJ} ${HEADER}
			@${MAKE_EXT} ./libft
			@printf $(green)
			@printf "Compiling executable\n"
			@${CC} ${CFLAGS} ${LDFLAGS} ${OBJ} ${LIB} -o ${NAME}
			@printf $(reset)

all:		${NAME}

clean:
			@printf $(magenta)
			@printf "Cleaning up object files\n"
			@${RM} ${OBJS} ${OBJS_BNS}
			@${MAKE_EXT} ./libft clean
			@printf $(reset)

fclean:		clean
			@printf $(magenta)
			@printf "Cleaning up binaries\n"
			@${RM} ${NAME}
			@${MAKE_EXT} ./libft fclean
			@printf $(reset)

re:			fclean all

bonus:
			@printf $(blue)
			@printf "Making Bonus\n"
			@${MAKE} BONUS_LEAKS=1
			@printf $(reset)

norm:
			@printf $(red)
			norminette libft/ header/ srcs/ srcs_bonus/
			@printf $(reset)

.PHONY:			all clean fclean re bonus norm

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
