/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 08:31:21 by nduvelle          #+#    #+#             */
/*   Updated: 2021/04/01 13:12:40 by nduvelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*ptres;

	ptres = (char *)s;
	i = 0;
	while (ptres[i])
		i++;
	while (i > 0)
	{
		if (ptres[i] == (char)c)
			return (ptres + i);
		i--;
	}
	if (*ptres != (char)c)
		return (NULL);
	return (ptres);
}
