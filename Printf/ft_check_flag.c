/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvelle <nduvelle@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 05:23:57 by nduvelle          #+#    #+#             */
/*   Updated: 2021/05/05 12:18:49 by nduvelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_spell(char input)
{
	if (input == 'c' || input == 's' || input == 'p' || input == 'd' \
	|| input == 'i' || input == 'u' || input == 'x' || input == 'X')
		return (1);
	return (0);
}

void	ft_get_flags(char *str, va_list *ap, t_flags *ret)
{
	while (*str != *ret->key && *str)
	{
		if (*str == ' ')
			ret->space++;
		else if (*str == '-')
			ret->minus++;
		else if (*str == '.')
			ret->dot++;
		else if (*str == '0' && (*(str - 1) == ' ' || \
		*(str - 1) == '+' || *(str - 1) == '-' || *(str - 1) == '#' \
		|| *(str - 1) == '%'))
			ret->zero++;
		else if (*str == '*' && ret->dot > 0)
			ret->precision = va_arg(*ap, int);
		else if (*str == '*')
			ret->width = va_arg(*ap, int);
		else if (ft_isdigit(*str) > 0 && ret->dot > 0 && ret->precision == 0)
			ret->precision = ft_atoi_printf(str);
		else if (ret->width == 0)
			ret->width = ft_atoi_printf(str);
		str++;
	}
}

void	ft_exec_func(char *str, va_list *ap, t_flags *ret)
{
	if (*str == 'd' || *str == 'i')
		ft_conv_integer(ap, ret);
	else if (*str == 'u')
		ft_conv_u(ap, ret);
	else if (*str == 'x' || *str == 'X')
		ft_conv_hexa(ap, ret);
	else if (*str == 'c')
		ft_conv_char(ap, ret);
	else if (*str == 's')
		ft_conv_str(ap, ret);
	else if (*str == 'p')
		ft_conv_p(ap, ret);
}
