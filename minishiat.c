/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishiat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoichon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:36:35 by agoichon          #+#    #+#             */
/*   Updated: 2023/02/06 10:47:26 by agoichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "minishell.h"
#include <readline/history.h>
#include <readline/readline.h>
#include <signal.h>

void	simple_exec(t_data *data)
{
	int	pid;
	char	**envp;
		
	envp = convert_env(data->env);
	pid = fork();
	if (pid == 0)
	{	
		if (data->infile != -1)
			dup2(data->infile, STDIN_FILENO);
		if (data->outfile != -1)
			dup2(data->outfile, STDOUT_FILENO);
		close_all(data);	
		//if (built_in(data))
		//	execbd(data);//tappe un exit
		//else
			execve(data->argz[0], data->argz, envp);//env t_list et non char **
	}
	free_loop(envp);
}

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

void	treat_command(t_data *data)
{
	int	z;
	
	z = 0;
	check(data);//check "" et '', ...
	if (data->exec_stat == 1)
	{
		if (data->nb_cmds > 1)
			pipes_prep(data->pipes, data->nb_cmds);
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

int	main(int argc, char **argv, char **envp)
{
	t_data	*data;

	(void) argc;
	(void) argv;
	signal(SIGINT, handle_sigint);
	signal(SIGQUIT, SIG_IGN);
	data = malloc(sizeof(t_data) * 1);
	init_data(data, envp);//initialise env, exec_stat a 1, outfile = -1, infile = -1, ..., argz = NULL
	while (1)
	{
		data->line =readline ("\e[0;36mprompt >\e[0;m");
		if (data->line == NULL)
			break;
		while (data->line != NULL)
		{
			add_history(data->line);
			free(data->line);
			data->line = readline("\e[0;36mprompt >\e[0;m");
		}	
		data->nb_cmds = nb_cmd(data->line);
		treat_command(data);
	}
	ft_putstr_fd("exit", 1);
	free_and_close_all(data, 2);// + env
	return (69);
}
