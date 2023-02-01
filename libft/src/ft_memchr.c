/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoichon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 16:25:25 by agoichon          #+#    #+#             */
/*   Updated: 2022/10/03 18:57:14 by agoichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft.h"

void	*ft_memchr( const void *s, int c, size_t n)
{
	unsigned char	*str;
	size_t			i;

	str = (unsigned char *)s;
	i = 0;
	while (i != n)
	{
		if (str[i] == (unsigned char) c % 256)
			return ((void *)&str[i]);
		i++;
	}
	return (NULL);
}
