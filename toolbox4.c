/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toolbox4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoichon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 10:50:10 by agoichon          #+#    #+#             */
/*   Updated: 2023/03/07 10:53:36 by agoichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_loop(char **str)
{
	int	z;

	z = 0;
	if (str)
	{
		while (str[z])
		{
			free (str[z]);
			z++;
		}
		free (str);
	}
	str = NULL;
}

void	skip_n_copy_quote(char *line, char *fnl, int *spot, int *z)
{
	char	q_type;

	q_type = line[*spot];
	*spot += 1;
	while (line[*spot] != q_type && line[*spot])
	{
		fnl[*z] = line[*spot];
		*z += 1;
		*spot += 1;
	}
	*spot += 1;
}

void	path_finder(t_data *data, char *cmd)
{
	char	**paths;
	int		z;

	z = 0;
	if (check_already_pathed(data, cmd) == 1)
		return ;
	paths = path_lst(data);
	if (paths != NULL)
	{
		while (paths[z])
		{
			data->argz[0] = triple_strjoin(paths[z], "/", cmd);
			if (access(data->argz[0], F_OK) == 0)
			{
				free_loop(paths);
				return ;
			}
			free (data->argz[0]);
			z++;
		}
	}
	data->argz = NULL;
	free_loop(paths);
}
