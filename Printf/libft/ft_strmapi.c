/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 09:59:13 by nduvelle          #+#    #+#             */
/*   Updated: 2021/03/31 08:10:03 by nduvelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*ptrstr;
	size_t	i;
	size_t	j;

	j = 0;
	if (!s || !f)
		return (NULL);
	i = ft_strlen(s);
	ptrstr = ft_calloc(sizeof(*s), i + 1);
	if (!ptrstr)
		return (NULL);
	while (i > 0)
	{
		ptrstr[j] = (*f)(j, (char)s[j]);
		j++;
		i--;
	}
	ptrstr[j] = '\0';
	return (ptrstr);
}
