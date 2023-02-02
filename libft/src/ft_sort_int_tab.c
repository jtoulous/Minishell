/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoichon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:05:30 by agoichon          #+#    #+#             */
/*   Updated: 2023/02/02 15:11:56 by agoichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(char *str)
{
	int	index;
	int	tmp;

	index = 0;
	while (str[index])
	{
		if (str[index] > str[index + 1])
		{
			tmp = str[index];
			str[index] = str[index + 1];
			str[index + 1] = tmp;
			index = 0;
		}
		else
			index++;
	}
}
