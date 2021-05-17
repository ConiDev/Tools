/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 08:11:47 by nduvelle          #+#    #+#             */
/*   Updated: 2021/03/31 12:23:28 by nduvelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_itoa_len(int n)
{
	int				len;
	unsigned int	number;

	len = 1;
	number = n;
	if (n < 0)
	{
		number *= -1;
		len++;
	}
	while (number > 9)
	{
		number = number / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char			*ptrnum;
	int				size;
	unsigned int	number;

	number = n;
	size = ft_itoa_len(n);
	ptrnum = ft_calloc(sizeof(char), size + 1);
	if (!ptrnum)
		return (NULL);
	if (n < 0)
	{
		ptrnum[0] = '-';
		number *= -1;
	}
	ptrnum[size] = '\0';
	while (number > 9 && (size - 1) > 0)
	{
		ptrnum[size - 1] = (number % 10) + 48;
		number = number / 10;
		size--;
	}
	ptrnum[size - 1] = (number % 10) + 48;
	return (ptrnum);
}
