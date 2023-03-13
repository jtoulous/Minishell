/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoichon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 11:27:29 by agoichon          #+#    #+#             */
/*   Updated: 2023/03/13 15:17:12 by agoichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static int	built_in_bis(t_data *data)
{
	if (ft_strncmp(data->argz[0], "unset", ft_strlen(data->argz[0])) == 0)
	{
		built_in_unset(data, 1);
		return (0);
	}
	if (ft_strncmp(data->argz[0], "env", ft_strlen(data->argz[0])) == 0)
	{
		built_in_env(data);
		return (0);
	}
	if (ft_strncmp(data->argz[0], "exit", ft_strlen(data->argz[0])) == 0)
		built_in_exit(data);
	return (-1);
}

int	built_in(t_data *data)
{
	if (ft_strncmp(data->argz[0], "echo", ft_strlen(data->argz[0])) == 0)
	{
		built_in_echo(data);
		return (0);
	}
	if (ft_strncmp(data->argz[0], "cd", 2) == 0)
	{
		built_in_cd(data);
		return (0);
	}
	if (ft_strncmp(data->argz[0], "pwd", ft_strlen(data->argz[0])) == 0)
	{
		built_in_pwd(data);
		return (0);
	}
	if (ft_strncmp(data->argz[0], "export", ft_strlen(data->argz[0])) == 0)
	{
		built_in_export(data, 1, 0);
		return (0);
	}
	built_in_bis(data);
	return (-1);
}

int	check_if_builtin(char *cmd)
{
	if (ft_strncmp(cmd, "echo", ft_strlen(cmd)) == 0
		&& ft_strlen(cmd) == ft_strlen("echo"))
		return (1);
	if (ft_strncmp(cmd, "cd", ft_strlen(cmd)) == 0
		&& ft_strlen(cmd) == ft_strlen("cd"))
		return (1);
	if (ft_strncmp(cmd, "pwd", ft_strlen(cmd)) == 0
		&& ft_strlen(cmd) == ft_strlen("pwd"))
		return (1);
	if (ft_strncmp(cmd, "export", ft_strlen(cmd)) == 0
		&& ft_strlen(cmd) == ft_strlen("export"))
		return (1);
	if (ft_strncmp(cmd, "unset", ft_strlen(cmd)) == 0
		&& ft_strlen(cmd) == ft_strlen("unset"))
		return (1);
	if (ft_strncmp(cmd, "env", ft_strlen(cmd)) == 0
		&& ft_strlen(cmd) == ft_strlen("env"))
		return (1);
	if (ft_strncmp(cmd, "exit", ft_strlen(cmd)) == 0
		&& ft_strlen(cmd) == ft_strlen("exit"))
		return (1);
	return (0);
}

void	export_display(char **envp, int *i, char *name, char *result)
{
	if (ft_strchr(envp[*i], '=') == 0)
		*i += 1;
	else
	{
		if (*envp[*i] == '_')
			*i += 1;
		else
		{
			printf("declare -x %s=\"%s\"\n", name, result);
			*i += 1;
		}
	}
}
