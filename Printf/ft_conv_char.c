/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvelle <nduvelle@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 00:28:55 by nduvelle          #+#    #+#             */
/*   Updated: 2021/05/03 04:33:54 by nduvelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_conv_char(va_list *ap, t_flags *ret)
{
	char	arg;

	arg = va_arg(*ap, int);
	if (ret->width < 0)
	{
		ret->minus++;
		ret->width *= -1;
	}
	if (ret->width > 1 && ret->minus < 1)
	{
		ft_display_flags(ret, ' ', 1, ret->width);
		ft_putchar_printf(arg, ret);
	}
	else if (ret->width > 1)
	{
		ft_putchar_printf(arg, ret);
		ft_display_flags(ret, ' ', 1, ret->width);
	}
	else
		ft_putchar_printf(arg, ret);
}

void	ft_conv_str_range(char *str, t_flags *ret, int count)
{
	ret->width -= count;
	if (ret->minus > 0)
	{
		while (count > 0)
		{
			ft_putchar_printf(*str, ret);
			str++;
			count--;
		}
		ft_display_flags(ret, ' ', 0, ret->width);
	}
	else
	{
		ft_display_flags(ret, ' ', 0, ret->width);
		while (count > 0)
		{
			ft_putchar_printf(*str, ret);
			str++;
			count--;
		}
	}
}

void	ft_conv_str(va_list *ap, t_flags *ret)
{
	int		count;
	char	*str;

	str = va_arg(*ap, char *);
	if (!str)
		str = "(null)";
	count = ft_strlen(str);
	if (ret->width < 0)
	{
		ret->minus++;
		ret->width *= -1;
	}
	if (ret->precision <= count && ret->precision > 0)
		count = ret->precision;
	if (ret->precision == 0 && ret->dot > 0)
		ft_display_flags(ret, ' ', 0, ret->width);
	else
		ft_conv_str_range(str, ret, count);
}
