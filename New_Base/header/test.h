/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvelle <nduvelle@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 04:31:34 by nduvelle          #+#    #+#             */
/*   Updated: 2021/10/13 15:00:52 by nduvelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H

# ifdef __APPLE__
#  define  MACRO_MAC "This is the TEST project for MAC !"
# elif __linux__
#  define  MACRO_LINUX "This is the TEST project for Linux !"
# endif

# include "../libft/header/libft.h"

void	ft_display_hello(void);

#endif
