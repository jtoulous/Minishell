/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoichon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:33:32 by agoichon          #+#    #+#             */
/*   Updated: 2022/10/11 11:41:06 by agoichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft.h"

char	*ft_substr(char const *s1, unsigned int start, size_t len)
{
	char			*s2;
	unsigned int	j;
	char			*es;

	if (!s1)
		return (0);
	j = ft_strlen(s1);
	if (start >= j || len <= 0)
		es = ft_strdup("");
	if (start >= j || len <= 0)
		return (es);
	if ((start + len) > j)
	{
		s2 = malloc (((j - start) + 1) * sizeof(char));
		if (!s2)
			return (NULL);
		ft_strlcpy(s2, (s1 + start), ((j - start) + 1));
		return (s2);
	}
	s2 = malloc((len + 1) * sizeof(char));
	if (!s2)
		return (NULL);
	ft_strlcpy(s2, (s1 + start), (len + 1));
	return (s2);
}
