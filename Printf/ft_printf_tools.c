/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvelle <nduvelle@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 03:10:52 by nduvelle          #+#    #+#             */
/*   Updated: 2021/05/06 00:21:32 by nduvelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_init_flags(t_flags *ret)
{
	ret->minus = 0;
	ret->plus = 0;
	ret->zero = 0;
	ret->hash = 0;
	ret->space = 0;
	ret->width = 0;
	ret->dot = 0;
	ret->precision = 0;
	ret->key = 0;
}

int	ft_check_char(const char *str, char charset)
{
	while ((char)*str)
	{
		if ((char)*str == charset)
			return (1);
		str++;
	}
	return (0);
}

char	*ft_strspell(const char *s)
{
	while ((char)*s)
	{
		if (ft_check_spell((char)*s) > 0)
			return ((char *)s);
		s++;
	}
	return (NULL);
}

int	ft_stock_putnbr(int n, t_flags *ret)
{
	unsigned int	number;
	int				count;

	count = 1;
	if (n < 0)
	{
		number = n * -1;
		ret->plus = -1;
		count++;
	}
	else
		number = n;
	while (number > 9)
	{
		number = number / 10;
		count++;
	}
	return (count);
}
