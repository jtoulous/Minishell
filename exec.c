#include "minishell.h"

void	builtinz_multi_first(t_data *data)
{
	int	pid;
	
	pid = fork();
	if (pid == 0)
	{
		if (data->infile != -1)
			dup2(data->infile, STDIN);
		if (data->outfile != -1)
			dup2(data->outfile, STDOUT);
		else 
			dup2(data->pipe[0][1], STDOUT);
		close_all(data);
		execbd(data);
	}
	wait (0);
}

/*void	builtinz_multi(t_data *data, int z)
{
	int	pid;
	
	pid = fork();
	if (pid == 0)
	{	
		if (data->infile != -1)
			dup2(data->infile, STDIN);
		else
			dup2(data->pipes[z - 1][], STDIN)
		execbd(data->argz[0], data->argz, data->env);
}*/

void	multi_exec(t_data *data, int z)
{
	if (built_in?(data->argz[0]) == 1)
	{
		if (z == 0)
			builtinz_multi_first(data);
		else
			builtinz_multi(data, z);
	}
	else
	{	
		if (z == 0)
			regularz_multi_first(data, z);
		else
			regularz_multi(data, z);
	}
}
