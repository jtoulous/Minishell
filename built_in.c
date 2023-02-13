/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoichon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 11:27:29 by agoichon          #+#    #+#             */
/*   Updated: 2023/02/13 09:31:06 by agoichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

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
		built_in_export(data);
		return (0);
	}
	if (ft_strncmp(data->argz[0], "unset", ft_strlen(data->argz[0])) == 0)
	{
		built_in_unset(data);
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
