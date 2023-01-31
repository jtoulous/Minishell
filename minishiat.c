#include "minishell.h"

void	simple_exec(t_data *data)
{
	int	pid;
	
	pid = fork();
	if (pid == 0)
	{	
		if (data->infile != -1)
			dup2(data->infile, STDIN);
		if (data->outfile != -1)
			dup2(data->outfile, STDOUT);
		close_all(data);	
		if (built_in?(data->argz[0]) == 1)
			execbd(data);//tappe un exit
		else
			execve(data->argz[0], data->argz, data->env);
	}
	wait (0);
}

void	exec(t_data *data, int z)
{
	if (data->nb_cmdz <= 1)
		simple_exec(data);
	else
		multiple_exec(data, z);
}

void	treat_command(t_data *data)
{
	int	z;
	
	z = 0;
	check(data)//check "" et '', ...
	if (data->exec_stat == 1)
	{
		if (data->nb_cmdz > 1)
			pipes_prep(data->pipes, data->nb_cmdz);
		while (z < data->nb_cmdz)
		{
			parse(data);
			if (data->argz != NULL)
				exec(data, z);//execbd pour built_in ou execve, check prev_outfile if != -1
			if (z < data->nb_cmdz - 1)
				reset_data(data);//restaure infile a -1 apres l avoir close, save outfile in old outfile if != -1, et tout le tralala
			z++;
		}
	}
	free_and_close_all(data, 1);//opt = 1 = don t free env,+ check access on heredoc.txt and unlink if nessessary
}

int	main(int argc, char **argv, char **envp)
{
	t_data	data;
	
	initialize_data(&data, envp);//initialise env, exec_stat a 1, outfile = -1, infile = -1, ...
	while (1)
	{
		ft_putstr_fd("Minichiass >", STDOUT);
		data.line = get_next_line(STDIN);
		data.nb_cmdz = nb_cmd(data->line);
		treat_command(&data);
	}
	free_and_close_all(&data, 2);//every fucking thing
	return (69);
}
