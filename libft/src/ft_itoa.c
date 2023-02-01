/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoichon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 16:07:51 by agoichon          #+#    #+#             */
/*   Updated: 2022/10/10 16:35:04 by agoichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft.h"

static long	ft_count(long n)
{
	long	s;

	s = 0;
	if (n < 0)
		s++;
	else if (n == 0)
		s++;
	while (n != 0)
	{
		s++;
		n /= 10;
	}
	return (s);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	nb;
	int		s;

	nb = n;
	s = ft_count(nb);
	str = malloc(sizeof(char) * (s + 1));
	if (!str)
		return (0);
	if (nb < 0)
	{
		str[0] = '-';
		nb *= -1;
	}
	if (nb == 0)
		str[0] = '0';
	str[s] = '\0';
	while (nb > 0)
	{
		str[s - 1] = (nb % 10) + '0';
		nb /= 10;
		s--;
	}
	return (str);
}	
