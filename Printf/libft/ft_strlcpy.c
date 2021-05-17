/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 09:29:11 by nduvelle          #+#    #+#             */
/*   Updated: 2021/03/30 10:59:49 by nduvelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len;

	i = 0;
	if (!dst || !src)
		return (0);
	len = ft_strlen(src);
	if (dstsize <= 0)
		return (len);
	while (i < (dstsize - 1) && (char)src[i])
	{
		dst[i] = (char)src[i];
		i++;
	}
	dst[i] = '\0';
	return (len);
}
