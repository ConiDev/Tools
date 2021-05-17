/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_hexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvelle <nduvelle@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 10:13:09 by nduvelle          #+#    #+#             */
/*   Updated: 2021/05/06 05:53:50 by nduvelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_conv_hexa(va_list *ap, t_flags *ret)
{
	unsigned long long	num;
	int					count;
	char				*tab;

	if (*ret->key == 'x')
		tab = "0123456789abcdef";
	else
		tab = "0123456789ABCDEF";
	num = va_arg(*ap, unsigned int);
	count = ft_stock_unsign(num, tab);
	if (ret->width < 0)
		ret->minus++;
	if (ret->width < 0)
		ret->width *= -1;
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
