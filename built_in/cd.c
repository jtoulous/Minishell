/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoichon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 13:06:06 by agoichon          #+#    #+#             */
/*   Updated: 2023/03/09 14:54:32 by agoichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	built_in_cd(t_data *data)
{
	char	*path;

	if (data->argz[1] == NULL)
	{
		path = getenv("HOME");
		chdir(path);
	}
	else
	{	
		if (access(data->argz[1], F_OK) == 0 && data->argz[2] == NULL)
			chdir(data->argz[1]);
		else if (data->argz[2] != NULL)
		{	
			ft_putstr_fd(" too many arguments\n", 2);
			g_err_code = 1;
			return ;
		}
		else
		{
			ft_putstr_fd(" No such file or directory\n", 2);
			g_err_code = 1;
			return ;
		}
		g_err_code = 0;
	}
}
