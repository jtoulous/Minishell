/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoichon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 23:03:20 by agoichon          #+#    #+#             */
/*   Updated: 2022/10/04 17:27:37 by agoichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	x;
	size_t	y;
	size_t	i;

	if (size == 0 && (dst == NULL || src == NULL))
		return (0);
	x = ft_strlen(src);
	y = ft_strlen(dst);
	i = 0;
	if (size == 0 || size <= y)
		return (x + size);
	while (src[i] && (i + y) != (size - 1))
	{
		dst[y + i] = src[i];
		i++;
	}
	dst[i + y] = '\0';
	return (y + x);
}
