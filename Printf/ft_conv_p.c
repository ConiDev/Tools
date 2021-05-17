/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvelle <nduvelle@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 08:26:45 by nduvelle          #+#    #+#             */
/*   Updated: 2021/05/05 10:11:51 by nduvelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_display_p(t_flags *ret, int count, unsigned long long num, char *tab)
{	
	if (ret->width >= count && ret->minus < 1)
	{
		ft_display_flags(ret, ' ', count + 2, ret->width);
		ft_putstr_printf("0x", ret);
		ft_putnbr_unsign(num, tab, ret);
	}
	else if (ret->width >= count && ret->minus > 0)
	{
		ft_putstr_printf("0x", ret);
		ft_putnbr_unsign(num, tab, ret);
		ft_display_flags(ret, ' ', count + 2, ret->width);
	}
}

void	ft_conv_p(va_list *ap, t_flags *ret)
{
	unsigned long long	num;
	int					count;
	char				*tab;

	tab = "0123456789abcdef";
	num = va_arg(*ap, unsigned long long);
	count = ft_stock_unsign(num, tab);
	if (ret->width < 0)
	{
		ret->minus++;
		ret->width *= -1;
	}
	if (ret->width >= count && ret->minus < 1)
		ft_display_p(ret, count, num, tab);
	else if (ret->width >= count && ret->minus > 0)
		ft_display_p(ret, count, num, tab);
	else
	{
		ft_putstr_printf("0x", ret);
		ft_putnbr_unsign(num, tab, ret);
	}
}
