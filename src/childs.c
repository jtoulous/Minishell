/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoichon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 11:23:06 by agoichon          #+#    #+#             */
/*   Updated: 2023/03/15 15:44:48 by jtoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	simple_child(t_data *data)
{
	if (data->infile != -1)
		dup2(data->infile, STDIN_FILENO);
	if (data->outfile != -1)
		dup2(data->outfile, STDOUT_FILENO);
	close_all(data);
	if (built_in(data) == -1)
		execve(data->argz[0], data->argz, data->envp);
	free_loop(data->envp);
	free_and_close_all(data, 3);
	mega_close(0, 1, 2, -1);
	exit (0);
}

void	first_child(t_data *data)
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
	mega_close(0, 1, 2, -1);
	exit (0);
}

void	last_child(t_data *data, int z)
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
	mega_close(0, 1, 2, -1);
	exit (0);
}

void	multiple_child(t_data *data, int z)
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
	mega_close(0, 1, 2, -1);
	exit (0);
}
