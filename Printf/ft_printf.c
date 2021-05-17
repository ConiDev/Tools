/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvelle <nduvelle@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 00:57:10 by nduvelle          #+#    #+#             */
/*   Updated: 2021/05/05 12:19:28 by nduvelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_printf_arg(char *str, va_list *ap, t_flags *ret)
{
	while (*str)
	{	
		if (*str == '%')
		{
			ft_init_flags(ret);
			str++;
			if (*str == '%')
				ft_putchar_printf(*str, ret);
			else
			{	
				ret->key = ft_strspell(str);
				ft_get_flags(str, ap, ret);
				str = ft_strspell(str);
				ft_exec_func(str, ap, ret);
			}
		}
		else
			ft_putchar_printf(*str, ret);
		str++;
	}
}

int	ft_printf(const char *input, ...)
{
	va_list		ap;
	t_flags		ret;

	va_start(ap, input);
	ret.count = 0;
	if (!(ft_check_char((char *)input, '%')))
		ft_putstr_printf((char *)input, &ret);
	else
		ft_printf_arg((char *)input, &ap, &ret);
	va_end(ap);
	return (ret.count);
}
