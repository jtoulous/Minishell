/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoichon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 16:16:50 by agoichon          #+#    #+#             */
/*   Updated: 2022/10/13 14:50:24 by agoichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft.h"

void	*ft_memmove( void *dest, const void *src, size_t n)
{
	unsigned char		*destination;
	unsigned char		*source;

	destination = (unsigned char *) dest;
	source = (unsigned char *) src;
	if (!dest && !src)
		return (0);
	if (destination > source)
	{
		while (n > 0)
		{	
			n--;
			destination[n] = source[n];
		}	
	}
	else
		ft_memcpy(dest, src, n);
	return ((void *)destination);
}
