/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoichon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 11:32:37 by agoichon          #+#    #+#             */
/*   Updated: 2022/10/13 14:48:18 by agoichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*destination;
	unsigned char		*source;
	size_t				i;

	destination = (unsigned char *) dest;
	source = (unsigned char *) src;
	if (!dest && !src)
		return (0);
	i = 0;
	while (i < n)
	{
		destination[i] = source[i];
		i++;
	}
	return ((void *)destination);
}
