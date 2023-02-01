/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoichon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 14:07:50 by agoichon          #+#    #+#             */
/*   Updated: 2022/10/04 14:18:21 by agoichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft.h"

void	ft_putnbr_fd(int nb, int fd)
{	
	if (nb == -2147483648)
		write (fd, "-2147483648", 11);
	else if (nb < 0)
	{
		ft_putchar_fd ('-', fd);
		ft_putnbr_fd (-nb, fd);
	}
	else if (nb >= 10)
	{
		ft_putnbr_fd ((nb / 10), fd);
		ft_putnbr_fd ((nb % 10), fd);
	}
	else
		ft_putchar_fd ((nb + '0'), fd);
}
