/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvelle <nduvelle@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 04:26:33 by nduvelle          #+#    #+#             */
/*   Updated: 2021/10/13 14:23:28 by nduvelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/test.h"

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	printf("Mandatory part !\n");
	ft_display_hello();
	printf("number argc=|%d|\n", argc);
	while (argv[i])
		printf("value argv=|%s|\n", argv[i++]);
	//uncomment to test debug flags
	//ft_crash();
	return (0);
}
