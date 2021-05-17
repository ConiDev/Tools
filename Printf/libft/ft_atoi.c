/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 13:12:06 by nduvelle          #+#    #+#             */
/*   Updated: 2021/04/01 13:10:54 by nduvelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	unsigned long int	res;
	int					i;
	int					signe;

	res = 0;
	i = 0;
	signe = 1;
	while ((char)str[i] == ' ' || (char)str[i] == '\t' || (char)str[i] == '\v' \
			 || (char)str[i] == '\f' || (char)str[i] == '\r' || \
			(char)str[i] == '\n')
		i++;
	if ((char)str[i] == '-' || (char)str[i] == '+')
		if ((char)str[i++] == '-')
			signe *= -1;
	while ((char)str[i] >= '0' && (char)str[i] <= '9')
	{
		res = (res * 10) + ((char)str[i] - 48);
		i++;
	}
	if (res >= 4294967295 && signe < 0)
		return (0);
	else if (res >= 4294967295)
		return (-1);
	return (signe * res);
}
