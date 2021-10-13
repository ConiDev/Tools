# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nduvelle <nduvelle@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/12 23:01:09 by nduvelle          #+#    #+#              #
#    Updated: 2021/10/13 14:39:33 by nduvelle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

############################################################
#				BASIC DECLARATION
############################################################
NAME			= test
CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror

############################################################
#				HEADER DECLARATION
############################################################
FOLDER_HDR		= header/

HEADER_SRC		= test.h
HEADER_BNS		= test_bonus.h

############################################################
#				SOURCES DECLARATION
############################################################
FOLDER			= srcs/
FOLDER_MAC		= srcs_mac/
FOLDER_LNX		= srcs_linux/
FOLDER_BNS		= srcs_bonus/

SRCS			= main.c
SRCS_MAC		= display_arg_mac.c
SRCS_LNX		= display_arg_linux.c
SRCS_BNS		= main_bonus.c

############################################################
#				ADDING PATH VALUES TO SOURCES FILES
############################################################
SRC				= $(addprefix ${FOLDER}, ${SRCS})
SRC_MAC			= $(addprefix ${FOLDER_MAC}, ${SRCS_MAC})
SRC_LNX			= $(addprefix ${FOLDER_LNX}, ${SRCS_LNX})
SRC_BNS			= $(addprefix ${FOLDER_BNS}, ${SRCS_BNS})

OBJS			= ${SRC:.c=.o}
OBJS_MAC		= ${SRC_MAC:.c=.o}
OBJS_LNX		= ${SRC_LNX:.c=.o}
OBJS_BNS		= ${SRC_BNS:.c=.o}

############################################################
#				CHOOSE OF FILES FOR MAC or LINUX
############################################################
OS				= $(shell uname -s)

ifeq ($(OS),Darwin)
LIB				= ./libft/libft.a
ifdef BONUS
OBJ				= ${OBJS_BNS} ${OBJS_MAC}
HEADER			= $(addprefix ${FOLDER_HDR}, ${HEADER_SRC}) \
					$(addprefix ${FOLDER_HDR}, ${HEADER_BNS})
else
OBJ				= ${OBJS} ${OBJS_MAC}
HEADER			= $(addprefix ${FOLDER_HDR}, ${HEADER_SRC})
endif
endif

ifeq ($(OS),Linux)
LIB				= ./libft/libft.a
ifdef BONUS
OBJ				= ${OBJS_BNS} ${OBJS_LNX}
HEADER			= $(addprefix ${FOLDER_HDR}, ${HEADER_SRC}) \
					$(addprefix ${FOLDER_HDR}, ${HEADER_BNS})
else
OBJ				= ${OBJS} ${OBJS_LNX}
HEADER			= $(addprefix ${FOLDER_HDR}, ${HEADER_SRC})
endif
endif

############################################################
#				DEBUG DECLARATION
############################################################
ifdef DEBUG
DFLAGS			= -fsanitize=address
endif

############################################################
#					BASIC 42 RULES
############################################################

%.o: %.c	${HEADER}
			@${CC} ${DFLAGS} ${CFLAGS} -c -o $@ $<

${NAME}:	${OBJ}
			@make -s --no-print-directory -C ./libft
			@printf "$(GREEN)Creating ${NAME} executable\n$(RES)"
			@${CC} ${DFLAGS} ${CFLAGS} ${OBJ} ${LIB} -o ${NAME}

all:		${NAME}

clean:
			@printf "$(RED)Destroying ${NAME} objs (*.o)\n$(RES)"
			@${RM} ${OBJS} ${OBJS_BNS} ${OBJS_MAC} ${OBJS_LNX}
			@make -s --no-print-directory clean -C ./libft

fclean:		clean
			@printf "$(RED)Destroying ${NAME} executable\n$(RES)"
			@${RM} ${NAME}
			@make -s --no-print-directory fclean -C ./libft

re:			fclean all

bonus:
			@${MAKE} --no-print-directory BONUS=1

############################################################
#					CUSTOM RULES
############################################################
debug:		clean
			@printf "$(BLUE)Added Debug Flags !\n$(RES)"
			@${MAKE} -s --no-print-directory DEBUG=1
			@${MAKE} -s --no-print-directory clean
			@printf "$(BLUE)Next make wil recompile without debug flags :)\n$(RES)"

norm:
			norminette libft/ header/ srcs/ srcs_mac/ srcs_linux/ srcs_bonus/

.PHONY:		all clean fclean re bonus norm

############################################################
#					COLOR SET
############################################################
RES			= \e[0m
RED			= \e[1;31m
GREEN		= \e[1;32m
BLUE		= \e[1;34m
