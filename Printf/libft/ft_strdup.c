/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 07:36:53 by nduvelle          #+#    #+#             */
/*   Updated: 2021/03/26 14:23:16 by nduvelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	size;
	size_t	i;
	char	*dup;

	size = ft_strlen(s);
	i = 0;
	dup = ft_calloc(sizeof(*dup), size + 1);
	if (!dup)
		return (NULL);
	while ((char)s[i])
	{
		dup[i] = (char )s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
