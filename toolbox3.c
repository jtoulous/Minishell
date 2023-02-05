#include "libft/libft.h"
#include "minishell.h"

void	free_and_close_all(t_data *data, int opt)
{
	if (opt == 2)
		free_lst(data->env);
	if (data->line)
		free (data->line);
	if (data->argz)
		free_loop(data->argz);
	close_all(data);
}

void	close_all(t_data *data)
{
	if (data->nb_cmds > 1)
		close_pipes(data->pipes, data->nb_cmds);
	if (data->infile != -1)
		close (data->infile);
	if (data->outfile != -1)
		close (data->outfile);
	if (data->prev_outfile != -1)
		close (data->prev_outfile);
}

void	close_pipes(int **pipes, int nb)
{
	int	z;
	
	z = 0;
	while (z < nb)
	{
		close (pipes[z][0]);
		close (pipes[z][1]);
		z++;
	}
}

void	free_lst(t_list *lst)
{
	t_list	*tmp;
	
	tmp = lst->next;
	while (tmp)
	{
		free (lst);
		lst = tmp;
		tmp = tmp->next;
	}
	free (lst);
}

char	*env_search(t_list *env, char *var)
{
	t_list	*tmp;
	char	*value;
	
	tmp = env;
	while (tmp)
	{
		if (ft_strncmp(var, tmp->env_copy, ft_strlen(var)) == 0)
		{
			value = ft_substr(tmp->env_copy, ft_strlen(var) + 1, 
					ft_strlen(tmp->env_copy) - ft_strlen(var));
			return (value);
		}
		tmp = tmp->next;
	}
	return (NULL);
}

void	add_history(char *line)
{
	int	i;
	int	c;
	char	history[100][1024];

	i = 0;
	c = 0;
	ft_strcpy(history[i % 100], line);
	i++;
	c = i;
	
}

int	check_if_builtin(char *cmd)
{
	if (ft_strncmp(cmd, "echo", ft_strlen(cmd)) == 0)
		return (1);
	if (ft_strncmp(cmd, "cd", ft_strlen(cmd)) == 0)
		return (1);
	if (ft_strncmp(cmd, "pwd", ft_strlen(cmd)) == 0)
		return (1);
	if (ft_strncmp(cmd, "export", ft_strlen(cmd)) == 0)
		return (1);
	if (ft_strncmp(cmd, "unset", ft_strlen(cmd)) == 0)
		return (1);
	if (ft_strncmp(cmd, "env", ft_strlen(cmd)) == 0)
		return (1);
	if (ft_strncmp(cmd, "exit", ft_strlen(cmd)) == 0)
		return (1);
	return (0);						
}
