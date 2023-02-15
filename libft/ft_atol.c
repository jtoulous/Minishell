/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoichon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 15:07:18 by agoichon          #+#    #+#             */
/*   Updated: 2023/02/15 15:55:34 by agoichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_atol(const char *nptr)
{
	int			i;
	long long	n;
	int			s;

	s = 1;
	n = 0;
	i = 0;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			s = -1;
		i++;
	}
	while (nptr[i] <= '9' && nptr[i] >= '0')
	{
		n = (n * 10) + (nptr[i] - '0');
		i++;
	}
	return (n * s);
}

long long	ft_atol_check(const char *nptr)
{
	int				i;
	long long		n;
	int				s;

	s = 1;
	n = 0;
	i = 0;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			s = -1;
		i++;
	}
	while (nptr[i] <= '9' && nptr[i] >= '0')
	{
		n = (n * 10) + (nptr[i] - '0');
		i++;
		if ((n * s) < -9223372036854775807 || (n * s) > 9223372036854775807)
			return (1);
	}
	return (0);
}
