/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishiat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoichon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:36:35 by agoichon          #+#    #+#             */
/*   Updated: 2023/02/05 13:19:00 by agoichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
	struct	sigaction sa_int;
	struct	sigaction sa_tstp;
	struct	sigaction sa_quit;

	(void) argc;
	(void) argv;
	sa_int.sa_flags = SA_SIGINFO;
	sa_int.sa_sigaction = handle_sigint;
	sigemptyset(&sa_int.sa_mask);
	sigaction(SIGINT, &sa_int, NULL);
	sa_tstp.sa_flags = SA_SIGINFO;
	sa_tstp.sa_sigaction = handle_eof;
	sigemptyset(&sa_tstp.sa_mask);
	sigaction(SIGINT, &sa_tstp, NULL);
	sa_quit.sa_flags = SA_SIGINFO;
	sa_quit.sa_sigaction = handle_sigquit;
	sigemptyset(&sa_quit.sa_mask);
	sigaction(SIGINT, &sa_quit, NULL);
	data = malloc(sizeof(t_data) * 1);
	init_data(data, envp);//initialise env, exec_stat a 1, outfile = -1, infile = -1, ..., argz = NULL
	while (1)
	{
		ft_putstr_fd("ta_mere_en_string_2_guerre >", STDOUT_FILENO);
		data->line = get_next_line(STDIN_FILENO);
		data->nb_cmds = nb_cmd(data->line);
		//add_history(data->line);
		treat_command(data);
	}
	free_and_close_all(data, 2);// + env
	return (69);
}
