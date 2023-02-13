/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errorz.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoichon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:58:47 by agoichon          #+#    #+#             */
/*   Updated: 2023/02/04 12:52:27 by agoichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*void	syntax_check(t_data *data)
{
	
}
*/
void	check_closed_quotes(t_data *data)
{
	int	z;
	
	z = 0;
	while (data->line[z])
	{
		if (data->line[z] == 34 || data->line[z] == 39)
			skip_out(data->line, &z);
		if (data->line[z] == '\0')
			error_quotes(data);
		else
			z++;
	}
}

void	check(t_data *data)
{
	int	nb_docs;
	
	check_closed_quotes(data);
	if (data->exec_stat == 1)
	//	syntax_check(data);
	{
		nb_docs = nb_hdocs(data->line);
		if (nb_docs != 0)
			hdoc_scan(data);
	}
}

int	check_if_fork(t_data *data)
{
	if (ft_strncmp(data->argz[0], "cd", ft_strlen(data->argz[0])) == 0)
	{
		built_in(data);
		return (1);
	}	
	if (ft_strncmp(data->argz[0], "export", ft_strlen(data->argz[0])) == 0)
	{
		built_in(data);
		return (1);
	}	
	if (ft_strncmp(data->argz[0], "unset", ft_strlen(data->argz[0])) == 0)
	{
		built_in(data);
		return (1);
	}	
	if (ft_strncmp(data->argz[0], "exit", ft_strlen(data->argz[0])) == 0)
	{
		built_in(data);
		return (1);
	}
	return (0);
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
