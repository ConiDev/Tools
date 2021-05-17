/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvelle <nduvelle@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 06:25:46 by nduvelle          #+#    #+#             */
/*   Updated: 2021/05/05 12:22:30 by nduvelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_unsign(unsigned long long nbr, char *base, t_flags *ret)
{
	unsigned long long		i;
	unsigned long long		number;

	i = ft_strlen(base);
	number = nbr;
	if (number >= i)
		ft_putnbr_unsign((number / i), base, ret);
	ft_putchar_printf(base[number % i], ret);
}

int	ft_stock_unsign(unsigned long long nbr, char *base)
{
	int					count;
	unsigned long long	number;
	unsigned long long	i;

	count = 1;
	number = nbr;
	i = ft_strlen(base);
	while (number >= i)
	{
		count++;
		number = number / i;
	}
	return (count);
}
