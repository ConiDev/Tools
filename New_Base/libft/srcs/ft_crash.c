/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_crash.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvelle <nduvelle@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 04:38:15 by nduvelle          #+#    #+#             */
/*   Updated: 2021/10/13 15:00:29 by nduvelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

void	ft_crash(void)
{
	int		i;
	char	*tab;

	tab = NULL;
	i = 0;
	while (i < 100)
		printf("%c", tab[i++]);
}
