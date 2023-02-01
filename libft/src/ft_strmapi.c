/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoichon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 15:26:17 by agoichon          #+#    #+#             */
/*   Updated: 2022/10/08 15:56:30 by agoichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	x;
	char			*s2;

	x = 0;
	if (!s || !f)
		return (0);
	s2 = malloc (sizeof(char) * (ft_strlen(s) + 1));
	if (s2)
	{
		while (s[x] != '\0')
		{
			s2[x] = (*f)(x, s[x]);
			x++;
		}
		s2[x] = '\0';
		return (s2);
	}
	else
		return (0);
}
