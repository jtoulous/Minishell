/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoichon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 09:29:04 by agoichon          #+#    #+#             */
/*   Updated: 2023/02/14 13:44:17 by agoichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "minishell.h"

static void	built_in_exit_utils(t_data *data)
{
	int	i;

	i = 0;
	while (data->argz[1][i])
	{	
		if (ft_isdigit(data->argz[1][i]) == 0)
		{
			ft_putstr_fd("exit\n", 2);
			printf("%s: %s: numeric argument required\n",
				data->argz[0], data->argz[1]);
			exit(2);
		}					
		i++;
	}
}	

int	built_in_exit(t_data *data)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
		if (data->argz[1] != NULL)
	{	
		built_in_exit_utils(data);
		n = ft_atoi(data->argz[1]);
	}
if (data->argz[2] != NULL)
	{
		if (ft_isdigit(data->argz[1][i++]) == 0)
			exit(1);
		printf("exit\n");
		printf("%s: too many arguments\n", data->argz[0]);
		return (1);
	}	
	ft_putstr_fd("exit\n", 1);
	free_and_close_all(data, 2);
	exit (n % 256);
}
