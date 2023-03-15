/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prep_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoichon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 10:21:45 by agoichon          #+#    #+#             */
/*   Updated: 2023/03/15 11:22:09 by jtoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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
			return ;
		else
			*z += 1;
	}
}

char	**path_lst(t_data *data)
{
	char	*path_list;
	char	**paths;

	path_list = env_search(data->env, "PATH");
	if (!path_list)
		return (NULL);
	paths = ft_split(path_list, ':');
	free (path_list);
	return (paths);
}

static int	check_if_dir(char *cmd)
{
	DIR	*test;

	test = opendir(cmd);
	if (test == NULL && access(cmd, X_OK) == 0)
		return (0);
	if (test != NULL)
		closedir(test);
	return (1);
}

int	check_already_pathed(t_data *data, char *cmd)
{
	if (cmd[0] == '/' || check_if_builtin(cmd) == 1
		|| cmd[0] == '.')
	{
		if (cmd[0] == '.')
		{
			if (check_if_dir(cmd) == 1)
			{
				free_loop(data->argz);
				data->argz = NULL;
				return (1);
			}
			else
				data->argz[0] = ft_strdup(cmd);
		}		
		else if (access(cmd, R_OK) == 0 || check_if_builtin(cmd) == 1)
			data->argz[0] = ft_strdup(cmd);
		else
		{
			free_loop(data->argz);
			data->argz = NULL;
		}	
		return (1);
	}
	return (0);
}
