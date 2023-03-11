/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoichon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:33:20 by agoichon          #+#    #+#             */
/*   Updated: 2023/03/11 09:22:20 by agoichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <signal.h>

void	exec(t_data *data, int z)
{
	if (data->nb_cmds <= 1)
		simple_exec(data);
	else if (z == 0)
		first_multiple(data);
	else if (z + 1 < data->nb_cmds)
		multiple_exec(data, z);
	else
		last_multiple(data, z);
}

void	simple_exec(t_data *data)
{
	int		pid;

	data->envp = convert_env(data->env);
	if (check_if_fork(data) != 1)
	{
		data->nb_forks++;
		pid = fork();
		signal(SIGINT, handle_sigchild);
		signal(SIGQUIT, handle_sigquit);
		if (pid == 0)
			simple_child(data);
		data->last_pid = pid;
	}
	free_loop(data->envp);
}

void	first_multiple(t_data *data)
{
	int		pid;

	data->envp = convert_env(data->env);
	if (check_if_fork(data) != 1)
	{	
		data->nb_forks++;
		pid = fork();
		signal(SIGINT, handle_sigchild);
		signal(SIGQUIT, handle_sigquit);
		if (pid == 0)
			first_child(data);
	}
	free_loop(data->envp);
}

void	last_multiple(t_data *data, int z)
{
	int		pid;

	data->envp = convert_env(data->env);
	if (check_if_fork(data) != 1)
	{
		data->nb_forks++;
		pid = fork();
		signal(SIGINT, handle_sigchild);
		signal(SIGQUIT, handle_sigquit);
		if (pid == 0)
			last_child(data, z);
		data->last_pid = pid;
	}
	free_loop(data->envp);
}

void	multiple_exec(t_data *data, int z)
{
	int		pid;

	data->envp = convert_env(data->env);
	if (check_if_fork(data) != 1)
	{
		data->nb_forks++;
		pid = fork();
		signal(SIGINT, handle_sigchild);
		signal(SIGQUIT, handle_sigquit);
		if (pid == 0)
			multiple_child(data, z);
	}
	free_loop(data->envp);
}
