/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_tools.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 07:31:33 by nduvelle          #+#    #+#             */
/*   Updated: 2021/05/05 02:51:15 by nduvelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_printf(char c, t_flags *ret)
{
	write(1, &c, 1);
	ret->count++;
}

void	ft_putstr_printf(char *str, t_flags *ret)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
		ret->count++;
	}
}

void	ft_display_flags(t_flags *ret, char charset, int count, int size)
{
	while (size > count)
	{
		ft_putchar_printf(charset, ret);
		size--;
	}
}

void	ft_putnbr_printf(int n, t_flags *ret)
{
	unsigned int	number;

	if (n < 0)
		number = n * -1;
	else
		number = n;
	if (number > 9)
	{
		ft_putnbr_printf(number / 10, ret);
		ft_putnbr_printf(number % 10, ret);
	}
	else
		ft_putchar_printf(number + 48, ret);
}

int	ft_atoi_printf(char *str)
{
	unsigned long int	res;

	res = 0;
	while (*str >= '0' && *str <= '9')
	{
		res = (res * 10) + (*str - 48);
		str++;
	}
	return (res);
}
