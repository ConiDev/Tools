/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 11:14:55 by nduvelle          #+#    #+#             */
/*   Updated: 2021/03/29 10:10:27 by nduvelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = ft_strlen(needle);
	j = 0;
	if (i == 0)
		return ((char *)haystack);
	while ((char)haystack[j] && j <= len)
	{
		k = 0;
		while ((char)haystack[j + k] == (char)needle[k] && j + k < len)
		{
			if (i == k)
				return ((char *)haystack + j);
			k++;
		}
		if (i == k)
			return ((char *)haystack + j);
		j++;
	}
	return (NULL);
}
