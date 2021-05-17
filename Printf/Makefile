# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nduvelle <nduvelle@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/05 12:22:56 by nduvelle          #+#    #+#              #
#    Updated: 2021/05/05 12:22:59 by nduvelle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= ft_printf.c ft_printf_tools.c ft_check_flag.c ft_display_tools.c ft_conv_int.c ft_conv_char.c ft_conv_unsigned.c ft_tools_unsigned.c ft_conv_p.c ft_conv_hexa.c

OBJS		= ${SRCS:.c=.o}

LIBFT		= cd libft/ && make

NAME		= libftprintf.a

CC		= gcc

RM		= rm -f

CFLAGS		= -Wall -Wextra -Werror

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME):	libft  ${OBJS}
			ar -rcs ${NAME} ${OBJS}

all:		${NAME}

clean:
		${RM} ${OBJS}
		${LIBFT} clean

fclean:		clean
			${RM} ${NAME} libft.a
			${LIBFT} fclean

re:			fclean all

libft:
		${LIBFT} bonus
		cp libft/libft.a ${NAME}

.PHONY:		$(NAME) all clean fclean re libft
