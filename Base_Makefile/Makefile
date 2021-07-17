# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nduvelle <nduvelle@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/24 19:05:27 by nduvelle          #+#    #+#              #
#    Updated: 2021/07/17 20:40:50 by nduvelle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= testleaks

CC			= gcc

RM			= rm -f

CFLAGS			= -Wall -Wextra -Werror
LDFLAGS			= -fsanitize=address

FOLDER_HEADER		= header/
FOLDER_SRCS		= srcs/
FOLDER_BNS		= srcs_bonus/


HEADER_SRC		= test.h
HEADER_BNS		= test_bonus.h
SRCS			= testleaks.c
SRCS_BNS		= testleaks_bonus.c

HDR			= $(addprefix ${FOLDER_HEADER}, ${HEADER_SRC})
HDR_BNS			= $(addprefix ${FOLDER_HEADER}, ${HEADER_BNS})
SRC			= $(addprefix ${FOLDER_SRCS}, ${SRCS})
SRC_BNS			= $(addprefix ${FOLDER_BNS}, ${SRCS_BNS})

OBJS			= ${SRC:.c=.o}
OBJS_BNS		= ${SRC_BNS:.c=.o}

LIB			= ./libft/libft.a

ifdef BONUS
OBJ			= ${OBJS_BNS}
HEADER			= ${HDR_BNS}
else
OBJ			= ${OBJS}
HEADER			= ${HDR}
endif

%.o: %.c
			@${CC} ${LDFLAGS} ${CFLAGS} -c -o $@ $^

${NAME}:		${OBJ} ${HEADER}
			@make -C ./libft
			@printf "Compiling executable...\n"
			@${CC} ${LDFLAGS} ${CFLAGS} ${OBJ} ${LIB} -o ${NAME}

all:			${NAME}

clean:
			@printf "Cleaning up object files...\n"
			@${RM} ${OBJS} ${OBJS_BNS}
			@make clean -C ./libft

fclean:			clean
			@printf "Cleaning up binaries...\n"
			@${RM} ${NAME}
			@make fclean -C ./libft

re:			fclean all

bonus:
			@printf "Making Bonus...\n"
			@${MAKE} BONUS=1

norm:
			norminette libft/ header/ srcs/ srcs_bonus/

.PHONY:			all clean fclean re bonus norm
