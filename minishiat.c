/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishiat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoichon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:36:35 by agoichon          #+#    #+#             */
/*   Updated: 2023/03/08 13:33:11 by agoichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "minishell.h"
#include <readline/history.h>
#include <readline/readline.h>
#include <signal.h>

void	treat_command(t_data *data)
{
	int	z;

	z = 0;
	check(data);
	if (data->exec_stat == 1)
	{
		if (data->nb_cmds > 1)
			pipes_prep(data, data->nb_cmds);
		while (z < data->nb_cmds)
		{
			parse(data);
			if (data->argz != NULL)
			{	
				g_err_code = 0;
				exec(data, z);
			}	
			if (z < data->nb_cmds - 1)
				reset_data(data);
			z++;
		}
	}
	free_and_close_all(data, 1);
}

void	wait_loop(t_data *data)
{
	int	z;
	int	status;

	z = 0;
	if (data->err_stat != 1 && data->nb_forks != 0)
	{
		status = 1;
		waitpid(data->last_pid, &status, 0);
		if (WIFEXITED(status))
			g_err_code = WEXITSTATUS(status);
	}
	while (z < data->nb_forks - 1)
	{
		status = 0;
		waitpid(-1, &status, 0);
		z++;
	}
	data->nb_forks = 0;
	data->err_stat = 0;
}

int	main(int argc, char **argv, char **envp)
{
	t_data	data;

	(void) argc;
	(void) argv;
	init_data(&data, envp);
	while (1)
	{
		signal(SIGINT, handle_sigint);
		signal(SIGQUIT, SIG_IGN);
		data.line = readline("\e[0;31mküçük_kabuk🦃>\e[0;m ");
		if (data.line == NULL)
			break ;
		add_history(data.line);
		data.nb_cmds = nb_cmd(data.line);
		treat_command(&data);
		wait_loop(&data);
	}
	ft_putstr_fd("exit", 1);
	free_loop(data.argz);
	free_and_close_all(&data, 2);
	return (0);
}
