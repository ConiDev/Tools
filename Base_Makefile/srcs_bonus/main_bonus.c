/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvelle <nduvelle@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 22:49:37 by nduvelle          #+#    #+#             */
/*   Updated: 2021/10/13 04:54:01 by nduvelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/test_bonus.h"

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	printf("Bonus part !\n");
	ft_display_hello();
	printf("number argc=|%d|\n", argc);
	while (argv[i])
		printf("value argv=|%s|\n", argv[i++]);
	return (0);
}
