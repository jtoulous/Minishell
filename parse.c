/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoichon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 10:06:24 by agoichon          #+#    #+#             */
/*   Updated: 2023/03/07 09:42:56 by agoichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	clean_dat_biach(t_data *data)
{
	int	z;
	int	end;

	z = 0;
	end = end_of_cmd(data->line, 0);
	while (z < end)
	{
		if (scan_varz(data, end, z) != 1)
			z++;
		end = end_of_cmd(data->line, 0);
	}
}

void	prep_exec(t_data *data, int end)
{
	int		z;
	int		leftovers;
	char	*cmd;

	z = 1;
	malloc_dat_shiat(data, end);
	cmd = get_nxt_stuff(data->line);
	path_finder(data, cmd);
	if (data->argz == NULL && cmd[0] != '/')
		error_path(cmd);
	else if (data->argz == NULL)
		error_inredir(cmd, 127);
	else
	{
		leftovers = count_leftovers(data->line, end_of_cmd(data->line, 0));
		while (z <= leftovers)
		{
			data->argz[z] = get_nxt_stuff(data->line);
			z++;
		}
		data->argz[z] = NULL;
		free (cmd);
	}
}

void	parse(t_data *data)
{
	int	end;

	end = end_of_cmd(data->line, 0);
	clean_dat_biach(data);
	if (check_redirz(data, end) != 1)
		return ;
	end = end_of_cmd(data->line, 0);
	prep_exec(data, end);
}
