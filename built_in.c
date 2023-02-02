/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoichon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 11:27:29 by agoichon          #+#    #+#             */
/*   Updated: 2023/02/02 16:43:27 by agoichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	built_in_echo(t_data *data)
{
	int	i;
	int	j;

	if (ft_strncmp(data->argz[1], "-n", 2) == 0)
	{
		j = 3;
		while (data->argz[1][j] == 'n')
			j++;
		i = 2;
		if (ft_strncmp(data->argz[i], "-n", 2))
			i++;
		while (data->argz[i])
		{
			printf("%s", data->argz[i]);
			i++;
		}
	}		
	else
	{
		i = 1;
		while (data->argz[i])
		{
			printf("%s", data->argz[i]);
			i++;
		}
		printf("\n");
	}
}

static void	built_in_cd(t_data *data)
{
	if (access(data->argz[1], F_OK) == 0 && data->argz[2] == NULL)
		chdir(data->argz[1]);
	else if (data->argz[2] != NULL)
		ft_putstr_fd("too many arguments\n", 2);
	else if (access(data->argz[1], F_OK) != 0)
		ft_putstr_fd("No such file or Directory\n", 2);
}

void	built_in_pwd(t_data *data)
{
	char	cwd[PATH_MAX];

	if (getcwd(cwd, sizeof(cwd)) == NULL)
	{
		ft_putstr_fd("Error getting current working directory\n", 1);
	}
	else
		ft_putstr_fd(cwd, 0);
}	

static int	built_in_export(t_data *data)
{
	int		i;
	int		j;
	int 	k;
	char	*variable;
	char	*new_value;

	if (data->argz[1] == NULL)
	{
		i = 0;
		ft_sort_int_tab(data->env->env_copy);
		while (data->env->env_copy[i])
		{
			printf("%s\n", data->env->env_copy);
			i++;
		}
		return (0);
	}	
	else
	{
		i = 1;
		j = 0;
		if (ft_isalpha(data->argz[i])
		while (data->argz[i][j]) 
		{
			while (data->argz[i][j] != '=')
			{
				variable[j] = data->argz[i][j];
				j++;
			}	
			if (data->argz[i][j] == '=')
				j++;
			k = 0;
			while (data->argz[i][j])
			{
				new_value[k] = data->argz[i][j];
				i++;
				k++;
			}
			ft_lstadd_back(data->env->entry, data->env->nxt);
		}	
	}	
}	

void	built_in_unset(t_data *data)
{
	int	i;

	i = 0;
	while (data->argz[1][i])
	{	
		if (ft_isalpha(data->argz[1][i]) == 1)
		{
			ft_putstr_fd("Not a valid Indentifier\n", 2);
			break ;
		}
		i++;
		if (ft_strncmp(data->argz[1], data->env->env_copy, ft_strlen(data->argz[1])) == 0)
			
	}		
}

void	built_in_env(t_data *data)
{
	int	i;

	i = 0;
	while (data->env->entry)
	{
		printf("%p\n", data->env->env_copy);
		i++;
	}
}

int	built_in_exit(t_data *data)
{
	int	i;
	int n;

	i = 0;
	n = 0;
	if (data->argz[2] != NULL)
	{
			ft_putstr_fd("exit\n", 1);
			ft_putstr_fd("too many arguments\n", 1);
			return (1);
	}	
	if (data->argz[1] != NULL)
	{	
		while (data->argz[1][i])
		{	
			if (ft_isdigit(data->argz[1][i]) == 1)
			{
				ft_putstr_fd("exit\n", 2);
				ft_putstr_fd("numeric argument required\n", 2);
				exit(2);
			}					
			i++;	
		}
		n = ft_atoi(data->argz[1]);
	}
	ft_putstr_fd("exit", 1);
	free_and_close_all(&data, 2);
	exit (n % 256);
}	

int built_in (t_data *data)
{
	if (ft_strncmp(data->argz[0], "echo", ft_strlen(data->argz[0])) == 0)
		built_in_echo(data);
	if (ft_strncmp(data->argz[0], "cd", 2) == 0)
		built_in_cd(data);
	if (ft_strncmp(data->argz[0], "pwd", ft_strlen(data->argz[0])) == 0)
		built_in_pwd(data);
	if (ft_strncmp(data->argz[0], "export", ft_strlen(data->argz[0])) == 0)
		built_in_export(data);
	if (ft_strncmp(data->argz[0], "unset", ft_strlen(data->argz[0])) == 0)
		built_in_unset(data);
	if (ft_strncmp(data->argz[0], "env", ft_strlen(data->argz[0])) == 0)
		built_in_env(data);
	if (ft_strncmp(data->argz[0], "exit", ft_strlen(data->argz[0])) == 0)
		built_in_exit(data);
	return (-1);

}	
