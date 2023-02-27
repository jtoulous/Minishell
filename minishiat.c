/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishiat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoichon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:36:35 by agoichon          #+#    #+#             */
/*   Updated: 2023/02/13 15:05:10 by agoichon         ###   ########.fr       */
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
				err_code = 0;
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
	if (data->err_stat != 1)
	{	
		waitpid(data->last_pid, &status, 0);
		if (WIFEXITED(status))
		err_code = WEXITSTATUS(status);
	}
	while (z < data->nb_forks - 1)
	{
		waitpid(-1, NULL, 0);
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
	signal(SIGINT, handle_sigint);
	signal(SIGQUIT, SIG_IGN);
	init_data(&data, envp);
	while (1)
	{
		data.line =readline("\e[0;31mküçük_kabuk🦃>\e[0;m ") ;
		//data.line = ft_strdup(argv[1]);
		if (data.line == NULL)
			break;
		add_history(data.line);
		data.nb_cmds = nb_cmd(data.line);
		treat_command(&data);
		wait_loop(&data);
	}
	ft_putstr_fd("exit", 1);
	free_and_close_all(&data, 2);
	return (0);
}
