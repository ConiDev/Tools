/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvelle <nduvelle@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 10:13:37 by nduvelle          #+#    #+#             */
/*   Updated: 2021/05/06 04:20:54 by nduvelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_display_int_minus(int num, t_flags *ret, int count)
{
	if (ret->plus == -1)
		ft_putchar_printf('-', ret);
	if (ret->precision >= count && ret->dot > 0)
	{
		if (ret->plus == -1)
			count--;
		ft_display_flags(ret, '0', count, ret->precision);
	}
	ft_putnbr_printf(num, ret);
	if (ret->width > count)
	{
		if (ret->precision > count)
			count = ret->precision;
		if (ret->plus == -1 && ret->precision >= count)
			count++;
		ft_display_flags(ret, ' ', count, ret->width);
	}
}

void	ft_display_range(int num, t_flags *ret, int count)
{
	if (num < 0 && ret->precision > 0)
		ret->precision++;
	if (ret->zero > 0 && (ret->dot < 1 || ret->precision < 0))
		ret->precision = ret->width;
	if (ret->precision >= ret->width && ret->precision > count && ret->zero < 1)
	{
		if (ret->plus == -1)
			ft_putchar_printf('-', ret);
		ft_display_flags(ret, '0', count, ret->precision);
	}
	else if (ret->width > count && ret->precision <= count)
	{
		ft_display_flags(ret, ' ', count, ret->width);
		if (ret->plus == -1)
			ft_putchar_printf('-', ret);
	}
	else
	{
		if (num < 0 && ret->precision == 1)
			ret->precision++;
		ft_display_flags(ret, ' ', ret->precision, ret->width);
		if (ret->plus == -1)
			ft_putchar_printf('-', ret);
		ft_display_flags(ret, '0', count, ret->precision);
	}
}

void	ft_conv_integer(va_list *ap, t_flags *ret)
{
	int	count;
	int	num;

	num = va_arg(*ap, int);
	count = ft_stock_putnbr(num, ret);
	if (ret->width < 0)
	{
		ret->minus++;
		ret->width *= -1;
	}
	if (num == 0 && ret->dot > 0 && ret->precision == 0)
		ft_display_flags(ret, ' ', 0, ret->width);
	else if (ret->minus > 0)
		ft_display_int_minus(num, ret, count);
	else if (ret->width > count || ret->precision >= count)
	{
		ft_display_range(num, ret, count);
		ft_putnbr_printf(num, ret);
	}
	else
	{
		if (ret->plus == -1)
			ft_putchar_printf('-', ret);
		ft_putnbr_printf(num, ret);
	}
}
