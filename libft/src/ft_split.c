/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoichon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 19:55:11 by agoichon          #+#    #+#             */
/*   Updated: 2022/10/13 11:49:45 by agoichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft.h"

static size_t	ft_ctword(char const *s, char c)
{
	size_t	ct;
	int		i;

	i = 0;
	if (!s[i])
		return (0);
	ct = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			ct++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (ct);
}

static	size_t	ft_schlen(char const *s, char c, size_t len)
{	
	if (!ft_strchr(s, c))
		len = ft_strlen(s);
	else
		len = ft_strchr(s, c) - s;
	return (len);
}			

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;
	size_t	len;

	if (!s)
		return (0);
	tab = ft_calloc(sizeof(char *), (ft_ctword(s, c) + 1));
	if (!tab)
		return (0);
	i = 0;
	while (*s != '\0')
	{
		while (*s == c && *s != '\0')
			s++;
		if (*s != '\0')
		{
			len = ft_schlen(s, c, len);
			tab[i] = ft_substr(s, 0, len);
			i++;
			s += len;
		}
	}
	return (tab);
}
