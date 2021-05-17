/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 09:26:37 by nduvelle          #+#    #+#             */
/*   Updated: 2021/03/31 08:04:16 by nduvelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*ptrjoin;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	ptrjoin = ft_calloc(sizeof(*ptrjoin), (ft_strlen(s1) + ft_strlen(s2)));
	if (!ptrjoin)
		return (NULL);
	while ((char)s1[i])
	{
		ptrjoin[i] = (char)s1[i];
		i++;
	}
	while ((char)s2[j])
	{
		ptrjoin[i] = (char)s2[j];
		i++;
		j++;
	}
	ptrjoin[i] = (char)s2[j];
	return (ptrjoin);
}
