/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 07:58:01 by nduvelle          #+#    #+#             */
/*   Updated: 2021/04/01 11:51:35 by nduvelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ptr;
	t_list	*start;

	if (!lst)
		return (NULL);
	start = ft_lstnew((f)(lst->content));
	lst = lst->next;
	while (lst)
	{
		ptr = ft_lstnew((f)(lst->content));
		if (!ptr)
			ft_lstdelone(ptr, del);
		ft_lstadd_back(&start, ptr);
		lst = lst->next;
	}
	return (start);
}
