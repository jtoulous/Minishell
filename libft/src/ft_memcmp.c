/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoichon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 18:59:48 by agoichon          #+#    #+#             */
/*   Updated: 2022/10/13 14:47:37 by agoichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t s)
{
	unsigned char	*p1;
	unsigned char	*p2;
	size_t			x;

	x = 0;
	p1 = (unsigned char *)s1;
	p2 = (unsigned char *)s2;
	while (x != s)
	{
		if (p1[x] != p2[x])
			return (p1[x] - p2[x]);
		x++;
	}
	return (0);
}
