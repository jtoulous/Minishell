/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toolbox2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoichon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:37:33 by agoichon          #+#    #+#             */
/*   Updated: 2023/03/16 09:53:07 by agoichon         ###   ########.fr       */
/*   Updated: 2023/03/15 15:12:43 by agoichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	export_env(t_list **env, char **envp)
{
	int	z;

	z = 0;
	while (envp[z])
	{
		ft_lstadd_back(env, ft_lstnew(ft_strdup(envp[z])));
		z++;
	}
}

void	init_data(t_data *data, char **envp)
{
	data->env = NULL;
	data->envp = NULL;
	if (envp[0] != NULL)
		export_env(&data->env, envp);
	else
		create_env(&data->env);
	data->infile = -1;
	data->outfile = -1;
	data->argz = NULL;
	data->exec_stat = 1;
	data->nb_forks = 0;
	data->err_stat = 0;
	data->doc_stat = 0;
	data->stdin_copy = -1;
}

void	reset_data(t_data *data)
{
	if (data->infile != -1)
		close (data->infile);
	if (data->outfile != -1)
		close (data->outfile);
	data->infile = -1;
	data->outfile = -1;
	free_loop(data->argz);
	data->argz = NULL;
	trim_leftovers(data->line);
	data->err_stat = 0;
}

void	pipes_prep(t_data *data, int nb_cmdz)
{
	int	z;

	z = 0;
	data->pipes = ft_calloc(nb_cmdz, sizeof(int *));
	while (z < nb_cmdz)
	{
		data->pipes[z] = ft_calloc(2, sizeof(int));
		pipe(data->pipes[z]);
		z++;
	}
}

int	count_leftovers(char *line, int end)
{
	int	z;
	int	leftovers;

	z = 0;
	leftovers = 0;
	while (line[z] == ' ' && z < end)
			z++;
	while (z < end)
	{
		if (line[z] != ' ')
		{
			leftovers++;
			while ((line[z] != ' ' || in_or_out(line, z) != 0)
				&& z < end)
				z++;
		}
		else
			z++;
	}
	return (leftovers);
}
