/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvelle <nduvelle@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 00:57:20 by nduvelle          #+#    #+#             */
/*   Updated: 2021/05/06 00:21:44 by nduvelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

typedef struct s_flags
{
	char	*key;
	int		minus;
	int		plus;
	int		zero;
	int		hash;
	int		space;
	int		count;
	int		width;
	int		dot;
	int		precision;
}		t_flags;

int		ft_printf(const char *input, ...);
void	ft_printf_arg(char *str, va_list *ap, t_flags *ret);
int		ft_check_char(const char *str, char charset);
void	ft_init_flags(t_flags *ret);
int		ft_check_spell(char input);
void	ft_exec_func(char *str, va_list *ap, t_flags *ret);
void	ft_get_flags(char *str, va_list *ap, t_flags *ret);
void	ft_putchar_printf(char c, t_flags *ret);
void	ft_putstr_printf(char *str, t_flags *ret);
int		ft_atoi_printf(char *str);
char	*ft_strspell(const char *s);
void	ft_display_flags(t_flags *ret, char charset, int count, int size);
void	ft_conv_u(va_list *ap, t_flags *ret);
void	ft_putnbr_printf(int n, t_flags *ret);
int		ft_stock_putnbr(int n, t_flags *ret);
void	ft_conv_integer(va_list *ap, t_flags *ret);
void	ft_display_int_minus(int num, t_flags *ret, int count);
void	ft_display_range(int num, t_flags *ret, int count);
void	ft_putnbr_unsign(unsigned long long nbr, char *base, t_flags *ret);
int		ft_stock_unsign(unsigned long long num, char *base);
void	ft_display_unsign_minus(unsigned long long num, \
t_flags *ret, int count, char *base);
void	ft_display_unsign_range(t_flags *ret, int count);
void	ft_conv_hexa(va_list *ap, t_flags *ret);
void	ft_conv_p(va_list *ap, t_flags *ret);
void	ft_display_p(t_flags *ret, int count, unsigned long long num, \
char *tab);
void	ft_conv_char(va_list *ap, t_flags *ret);
void	ft_conv_str(va_list *ap, t_flags *ret);
void	ft_conv_str_range(char *str, t_flags *ret, int count);

#endif
