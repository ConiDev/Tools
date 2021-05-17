/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 17:50:27 by nduvelle          #+#    #+#             */
/*   Updated: 2021/03/31 09:00:34 by nduvelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*s_tab;

	s_tab = malloc(sizeof(s_tab));
	if (!s_tab)
		return (NULL);
	s_tab->content = content;
	s_tab->next = 0;
	return (s_tab);
}
