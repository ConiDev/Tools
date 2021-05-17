/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 09:40:11 by nduvelle          #+#    #+#             */
/*   Updated: 2021/03/31 08:05:27 by nduvelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char			*ptrtrim;
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	j = ft_strlen(s1);
	k = 0;
	while (ft_strchr(set, (char)s1[i]) && i != j)
		i++;
	while (ft_strchr(set, (char)s1[j]) && j != i)
		j--;
	if (j == i)
		ptrtrim = ft_calloc(sizeof(*ptrtrim), 1);
	else
		ptrtrim = ft_calloc(sizeof(*ptrtrim), (j - i) + 2);
	if (!ptrtrim)
		return (NULL);
	while (i <= j)
		ptrtrim[k++] = (char)s1[i++];
	ptrtrim[k] = '\0';
	return (ptrtrim);
}
