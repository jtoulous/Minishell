/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoichon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:58:47 by agoichon          #+#    #+#             */
/*   Updated: 2023/03/02 11:24:14 by agoichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	check_syntax(t_data *data, char to_check)
{
	int	z;

	z = 0;
	if (to_check == '|')
	{
		check_syntax_pipes(data);
		return ;
	}
	while (data->line[z] && data->exec_stat == 1)
	{
		if (data->line[z] == to_check && in_or_out(data->line, z) == 0)
		{
			if (data->line[z + 1] == to_check)
				z++;
			z++;
			while (data->line[z] == ' ' && data->line[z])
				z++;
			if (data->line[z] == '<' || data->line[z] == '>'
				|| valid_pipe(data->line, z) == 1
				|| data->line[z] == '\0')
				error_syntax(data, z);
		}
		z++;
	}
}

void	check_syntax_pipes(t_data *data)
{
	int	z;

	z = 0;
	while (data->line[z] && data->exec_stat == 1)
	{
		if (valid_pipe(data->line, z) == 1)
		{
			z++;
			while (data->line[z] == ' ' && data->line[z])
				z++;
			if (data->line[z] == '\0')
				error_syntax(data, z);
		}
		z++;
	}
}

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
	check_closed_quotes(data);
	if (data->exec_stat == 1)
		check_syntax(data, '<');
	if (data->exec_stat == 1)
	{
		if (nb_hdocs(data->line) != 0)
			hdoc_scan(data);
		check_syntax(data, '>');
		if (data->exec_stat == 1)
			check_syntax(data, '|');
	}
}

int	check_if_fork(t_data *data, char **envp)
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
		free_loop(envp);
		built_in(data);
		return (1);
	}
	return (0);
}
