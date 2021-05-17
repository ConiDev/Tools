/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 10:12:05 by nduvelle          #+#    #+#             */
/*   Updated: 2021/04/02 14:15:38 by nduvelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char const *str, char charset)
{
	unsigned int	count;

	count = 0;
	while ((char)*str)
	{	
		if ((char)*str && (char)*str != charset)
		{
			count++;
			while ((char)*str && (char)*str != charset)
				str++;
		}
		else
			str++;
	}
	return (count);
}

static char	*ft_strndup(const char *str, char charset)
{	
	unsigned int	i;
	char			*strcpy;
	
	i = 0;
	while ((char)str[i] && (char)str[i] != charset)
		i++;
	if (!str)
		strcpy = ft_calloc(sizeof(char), 1);
	else
		strcpy = ft_calloc(sizeof(char), i + 1);
	strcpy[i] = '\0';
	while (i > 0)
	{
		strcpy[i - 1] = (char)str[i - 1];
		i--;
	}
	return (strcpy);
}

char	**ft_split(char const *s, char c)
{
	char			**strsplit;
	unsigned int	i;
	unsigned int	j;
	unsigned int	count;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	count = ft_count_words(s, c);
	strsplit = ft_calloc(sizeof(char *), count + 1);
	if (!strsplit)
		return (NULL);
	while (count-- > 0)
	{
		while ((char)s[j] == c && (char)s[j])
			j++;
		if ((char)s[j] != c && (char)s[j])
			strsplit[i++] = ft_strndup(s + j, c);
		while ((char)s[j] != c && (char)s[j])
			j++;
	}
	strsplit[i] = NULL;
	return (strsplit);
}
