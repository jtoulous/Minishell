/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoichon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:33:20 by agoichon          #+#    #+#             */
/*   Updated: 2023/03/07 09:37:04 by agoichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
		if (pid == 0)
		{
			if (data->infile != -1)
				dup2(data->infile, STDIN_FILENO);
			if (data->outfile != -1)
				dup2(data->outfile, STDOUT_FILENO);
			close_all(data);
			if (built_in(data) == -1)
				execve(data->argz[0], data->argz, data->envp);
			else
			{	
				free_loop(data->envp);
				free_and_close_all(data, 3);
			}	
			exit (0);
		}
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
		if (pid == 0)
		{
			if (data->infile != -1)
				dup2(data->infile, STDIN_FILENO);
			if (data->outfile != -1)
				dup2(data->outfile, STDOUT_FILENO);
			else
				dup2(data->pipes[0][1], STDOUT_FILENO);
			close_all(data);
			if (built_in(data) == -1)
				execve(data->argz[0], data->argz, data->envp);
			free_and_close_all(data, 3);
			free_loop(data->envp);
			exit (0);
		}
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
		if (pid == 0)
		{
			if (data->prev_outfile != -1)
				dup2(data->prev_outfile, STDIN_FILENO);
			else if (data->infile != -1)
				dup2(data->infile, STDIN_FILENO);
			else
				dup2(data->pipes[z - 1][0], STDIN_FILENO);
			if (data->outfile != -1)
				dup2(data->outfile, STDOUT_FILENO);
			close_all(data);
			if (built_in(data) == -1)
				execve(data->argz[0], data->argz, data->envp);
			free_and_close_all(data, 3);
			free_loop(data->envp);
			exit (0);
		}
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
		if (pid == 0)
		{
			if (data->prev_outfile != -1)
				dup2(data->prev_outfile, STDIN_FILENO);
			else if (data->infile != -1)
				dup2(data->infile, STDIN_FILENO);
			else
				dup2(data->pipes[z - 1][0], STDIN_FILENO);
			if (data->outfile != -1)
				dup2(data->outfile, STDOUT_FILENO);
			else
				dup2(data->pipes[z][1], STDOUT_FILENO);
			close_all(data);
			if (built_in(data) == -1)
				execve(data->argz[0], data->argz, data->envp);
			free_and_close_all(data, 3);
			free_loop(data->envp);
			exit (0);
		}
	}
	free_loop(data->envp);
}
