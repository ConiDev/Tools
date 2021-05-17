/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 10:22:32 by nduvelle          #+#    #+#             */
/*   Updated: 2021/03/26 10:56:21 by nduvelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len;
	size_t	i;
	size_t	j;

	len = ft_strlen(src);
	i = ft_strlen(dst);
	j = 0;
	if (dstsize < i || dstsize == 0)
		return (len + dstsize);
	while ((i + j) < (dstsize - 1) && (char)src[j])
	{
		dst[i + j] = (char)src[j];
		j++;
	}
	dst[i + j] = '\0';
	return (len + i);
}
