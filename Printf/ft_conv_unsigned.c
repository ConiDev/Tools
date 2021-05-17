/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvelle <nduvelle@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 05:02:07 by nduvelle          #+#    #+#             */
/*   Updated: 2021/05/06 06:08:59 by nduvelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_display_unsign_minus(unsigned long long num, \
t_flags *ret, int count, char *base)
{
	if (ret->precision >= count && ret->dot > 0)
		ft_display_flags(ret, '0', count, ret->precision);
	ft_putnbr_unsign(num, base, ret);
	if (ret->width > count)
	{
		if (ret->precision > count)
			count = ret->precision;
		ft_display_flags(ret, ' ', count, ret->width);
	}
}

void	ft_display_unsign_range(t_flags *ret, int count)
{
	if (ret->precision > 0)
		ret->precision++;
	if (ret->zero > 0 && (ret->dot < 1 || ret->precision < 0))
		ret->precision = ret->width;
	if (ret->precision >= ret->width && ret->precision > count && ret->zero < 1)
		ft_display_flags(ret, '0', count, ret->precision);
	else if (ret->width > count && ret->precision <= count)
		ft_display_flags(ret, ' ', count, ret->width);
	else
	{
		if (ret->precision == 1)
			ret->precision++;
		ft_display_flags(ret, ' ', ret->precision, ret->width);
		ft_display_flags(ret, '0', count, ret->precision);
	}
}

void	ft_conv_u(va_list *ap, t_flags *ret)
{
	unsigned int	num;
	int				count;
	char			*tab;

	tab = "0123456789";
	num = va_arg(*ap, unsigned int);
	count = ft_stock_unsign(num, tab);
	if (ret->width < 0)
	{
		ret->minus++;
		ret->width *= -1;
	}
	if (num == 0 && ret->dot > 0 && ret->precision == 0)
		ft_display_flags(ret, ' ', 0, ret->width);
	else if (ret->minus > 0)
		ft_display_unsign_minus(num, ret, count, tab);
	else if (ret->width > count || ret->precision >= count)
	{
		ft_display_unsign_range(ret, count);
		ft_putnbr_unsign(num, tab, ret);
	}
	else
		ft_putnbr_unsign(num, tab, ret);
}
