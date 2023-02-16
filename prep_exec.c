/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prep_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoichon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 10:21:45 by agoichon          #+#    #+#             */
/*   Updated: 2023/02/16 10:21:47 by agoichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	skip_redir(char *line, int *z, int end)
{
	*z += 1;
	while (line[*z] == ' ' && *z < end)
		*z += 1;
	while ((line[*z] != ' ' || in_or_out(line, *z) != 0)
		&& *z < end)
		*z += 1;
}

void	skip_arg(char *line, int *z, int end)
{
	while (*z < end)
	{
		if (line[*z] == ' ' && in_or_out(line, *z) == 0)
			return;
		else
			*z += 1;	
	}
}

void	malloc_dat_shiat(t_data *data, int end)
{
	int	m_size;
	int	z;
	
	m_size = 0;
	z = 0;
	while (z < end)
	{
		if (data->line[z] != ' ')
		{
			skip_arg(data->line, &z, end);
			m_size++;
		}
		else
			z++;
	}
	data->argz = ft_calloc(m_size + 2 , sizeof(char *));
}

char	**path_lst(t_data *data)
{
	char	*path_list;
	char	**paths;
	
	path_list = env_search(data->env, "PATH");
	s_trimage(path_list, 5);
	paths = ft_split(path_list, ':');
	return (paths);
}

void	path_finder(t_data *data, char *cmd)
{
	char	**paths;
	int	z;
	
	z = 0;
	if (cmd[0] == '/' || check_if_builtin(cmd) == 1)
	{
		if (access(cmd, F_OK) == 0 || check_if_builtin(cmd) == 1)
			data->argz[0] = ft_strdup(cmd);
		else
			data->argz = NULL;
		return ;
	}
	paths = path_lst(data);
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
	data->argz = NULL;
	free_loop(paths);
}
