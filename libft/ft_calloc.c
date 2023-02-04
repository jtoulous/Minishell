/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoulous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 12:02:02 by jtoulous          #+#    #+#             */
/*   Updated: 2022/10/05 22:03:55 by jtoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*pt;

	if (nmemb == 0 || size == 0)
	{
		pt = malloc(0);
		return (pt);
	}
	if (nmemb * size / size != nmemb)
		return (0);
	pt = malloc(size * nmemb);
	if (!pt)
		return (0);
	ft_bzero(pt, nmemb * size);
	return (pt);
}
