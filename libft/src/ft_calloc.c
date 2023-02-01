/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoichon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 11:08:15 by agoichon          #+#    #+#             */
/*   Updated: 2022/11/28 13:09:37 by agoichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft.h"

void	*ft_calloc(size_t nmeb, size_t size)
{
	void	*str;

	if ((nmeb * size == 1) && (size != 1))
		return (0);
	str = malloc(size * nmeb);
	if (!str)
		return (0);
	ft_memset(str, 0, nmeb * size);
	return (str);
}
