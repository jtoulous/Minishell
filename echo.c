/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoichon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 09:24:11 by agoichon          #+#    #+#             */
/*   Updated: 2023/02/08 09:27:05 by agoichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	built_in_echo_utils(t_data *data)
{
	int	i;

	i = 1;
	while (data->argz[i])
	{
		printf("%s ", data->argz[i]);
		i++;
	}
	printf("\n");
}	

void	built_in_echo(t_data *data)
{
	int	i;
	int	j;

	if (ft_strncmp(data->argz[1], "-n", ft_strlen(data->argz[1])) == 0)
	{
		j = 1;
		while (data->argz[1][j] == 'n')
			j++;
		i = 2;
		while (ft_strncmp(data->argz[i], "-n", 2) == 0)
			i++;
		while (data->argz[i])
		{
			if (data->argz[i + 1] != NULL)
				printf("%s ", data->argz[i]);
			else
				printf("%s", data->argz[i]);
			i++;
		}
	}		
	else
		built_in_echo_utils(data);
}
