#include "minishell.h"

t_env	*new_env(char *new_entry)
{
	t_env	*new;
	
	new = malloc(sizeof(t_env));
	new->entry = ft_strdup(new_entry);
	new->nxt = NULL;
}

void	add_env(t_env **env, t_env *new)
{
	t_env	*tmp;
	
	if (!*env)
		*env = new;
	else
	{
		tmp = *env;
		while (tmp->nxt != NULL)
			tmp = tmp->nxt;
		tmp->nxt = new;
	}
}

void	export_env(t_env *env, char **envp)
{
	int	z;
	
	z = 0;
	while (envp[z])
	{
		add_env(&env, new_env(envp[z]));
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
	free_loop(argz)	
}
