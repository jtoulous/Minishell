/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toolbox3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoichon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 10:15:32 by agoichon          #+#    #+#             */
/*   Updated: 2023/03/07 09:45:10 by agoichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_and_close_all(t_data *data, int opt)
{
	if (opt > 1)
	{	
		free_lst(data->env);
		if (opt == 2)
			return ;
	}
	if (data->line)
	{	
		free (data->line);
		data->line = NULL;
	}
	if (data->argz)
	{	
		free_loop(data->argz);
		data->argz = NULL;
	}
	if (opt != 3)
		close_all(data);
	data->exec_stat = 1;
	if (data->doc_stat == 1)
	{
		data->doc_stat = 0;
		unlinkz(NULL);
	}
}

void	close_all(t_data *data)
{
	if (data->nb_cmds > 1 && data->exec_stat == 1)
		close_pipes(data->pipes, data->nb_cmds);
	if (data->infile != -1)
	{	
		close (data->infile);
		data->infile = -1;
	}
	if (data->outfile != -1)
	{	
		close (data->outfile);
		data->outfile = -1;
	}
	if (data->prev_outfile != -1)
	{	
		close (data->prev_outfile);
		data->prev_outfile = -1;
	}
}

void	close_pipes(int **pipes, int nb)
{
	int	z;

	z = 0;
	while (z < nb)
	{
		close (pipes[z][0]);
		close (pipes[z][1]);
		free (pipes[z]);
		z++;
	}
	free (pipes);
}

void	free_lst(t_list *lst)
{
	t_list	*tmp;

	while (lst != NULL)
	{
		tmp = lst->next;
		free(lst->env_copy);
		lst->env_copy = NULL;
		free(lst);
		lst = tmp;
	}
	lst = NULL;
}

char	*env_search(t_list *env, char *var)
{
	t_list	*tmp;
	char	*value;

	tmp = env;
	while (tmp)
	{
		if (ft_strncmp(var, tmp->env_copy, ft_strlen(var)) == 0
			&& tmp->env_copy[ft_strlen(var)] == '=')
		{
			value = ft_substr(tmp->env_copy, ft_strlen(var) + 1,
					ft_strlen(tmp->env_copy) - ft_strlen(var));
			return (value);
		}
		tmp = tmp->next;
	}
	return (NULL);
}
