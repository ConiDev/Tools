/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 07:26:40 by nduvelle          #+#    #+#             */
/*   Updated: 2021/03/31 07:58:38 by nduvelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptrstr;
	size_t	i;
	size_t	j;

	i = 0;
	j = (size_t)start;
	if (!s)
		return (NULL);
	else if (j >= ft_strlen(s))
		ptrstr = ft_calloc(sizeof(*ptrstr), 1);
	else if (ft_strlen(s) < len)
		ptrstr = ft_calloc(sizeof(*ptrstr), ft_strlen(s) + 1);
	else
		ptrstr = ft_calloc(sizeof(*ptrstr), len + 1);
	if (!ptrstr)
		return (NULL);
	if (!(j >= ft_strlen(s)))
		while ((char)s[j] && i < len)
			ptrstr[i++] = (char)s[j++];
	ptrstr[i] = '\0';
	return (ptrstr);
}
