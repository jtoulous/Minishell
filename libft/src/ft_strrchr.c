/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoichon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 14:11:06 by agoichon          #+#    #+#             */
/*   Updated: 2022/10/13 14:56:04 by agoichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	if (s[i] == c % 256)
		return ((char *) &s[i]);
	while (i != 0)
	{
		if (s[i] == c % 256)
			return ((char *)&s[i]);
		i--;
	}
	if (c % 256 == s[i])
		return ((char *)&s[i]);
	return (NULL);
}
