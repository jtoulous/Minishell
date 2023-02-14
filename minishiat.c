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
	check(data);//check "" et '', ...
	if (data->exec_stat == 1)
	{
		if (data->nb_cmds > 1)
			pipes_prep(data, data->nb_cmds);
		while (z < data->nb_cmds)
		{
			parse(data);
			if (data->argz != NULL)
				exec(data, z);//execbd pour built_in ou execve, check prev_outfile if != -1
			if (z < data->nb_cmds - 1)
				reset_data(data);//set infile a -1 after close, save outfile in old outfile if != -1 + trim_leftovers
			z++;
		}
	}
	free_and_close_all(data, 1);// - env
}

void	wait_loop(t_data *data)
{
	int	z;
	
	z = 0;
	while (z < data->nb_forks)
	{
		waitpid(-1, NULL, 0);
		z++;
	}
	data->nb_forks = 0;
}

int	main(int argc, char **argv, char **envp)
{
	t_data	data;

	(void) argc;
	(void) argv;
	signal(SIGINT, handle_sigint);
	signal(SIGQUIT, SIG_IGN);
	init_data(&data, envp);//initialise env, exec_stat a 1, outfile = -1, infile = -1, ..., argz = NULL
	while (1)
	{
		data.line =readline("\e[0;31mküçük_kabuk🦃>\e[0;m ") ;
		if (data.line == NULL)
			break;
		add_history(data.line);
		data.nb_cmds = nb_cmd(data.line);
		treat_command(&data);
		wait_loop(&data);
	}
	ft_putstr_fd("exit", 1);
	free_and_close_all(&data, 2);// + env
	return (0);
}
