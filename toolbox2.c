#include "minishell.h"

void	export_env(t_list *env, char **envp)
{
	int	z;
	
	z = 0;
	while (envp[z])
	{
		ft_lstadd_back(&env, ft_lstnew(envp[z]));
		z++;
	}
}

void	init_data(t_data *data, char **envp)
{
	export_env(data->env, envp);
	data->infile = -1;
	data->outfile = -1;
	argz = NULL;
	exec_stat = 1;
	prev_outfile = -1;	
}

void	reset_data(t_data *data)
{
	data->infile = -1;
	data->old_outfile = data->outfile;
	data->outfile = -1;
	free_loop(argz);
	trim_leftovers(data->line);	
}

void	pipes_prep(int **pipes, int nb_cmdz)
{
	int	z;
	
	z = 0;
	pipes = ft_calloc(nb_cmdz, sizeof(int *));
	while (z < nb_cmdz)
	{
		pipes[z] = ft_calloc(2, sizeof(int));
		pipe(pipes[z]);
		z++;
	}
}
