/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 07:02:57 by nduvelle          #+#    #+#             */
/*   Updated: 2021/04/01 07:34:51 by nduvelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*ptr;

	while ((*lst))
	{
		(*del)((*lst)->content);
		ptr = *lst;
		*lst = (*lst)->next;
		free(ptr);
	}
}
