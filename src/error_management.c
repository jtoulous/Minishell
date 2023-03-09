/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoichon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:33:08 by agoichon          #+#    #+#             */
/*   Updated: 2023/03/09 14:52:30 by agoichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	error_permission(t_data *data)
{
	ft_putstr_fd(" Permission denied\n", STDERR_FILENO);
	data->err_stat = 1;
	g_err_code = 1;
}

int	error_inredir(char *failed_redir, int error)
{
	ft_putstr_fd(failed_redir, STDERR_FILENO);
	ft_putstr_fd(": No such file or directory\n", STDERR_FILENO);
	free (failed_redir);
	g_err_code = error;
	return (0);
}

void	error_quotes(t_data *data)
{
	data->exec_stat = 0;
	ft_putstr_fd("Don't forget to close those quotes tight ", STDOUT_FILENO);
	ft_putstr_fd("Or you'll face an error with all its might!\n", STDOUT_FILENO);
}

void	error_path(char *cmd)
{
	ft_putstr_fd(cmd, STDERR_FILENO);
	if ((cmd[0] == '.' && cmd[1] == '/')
		|| cmd[0] == '/')
	{	
		g_err_code = 126;
		if (access(cmd, X_OK) == -1 && access(cmd, F_OK) == 0)
			ft_putstr_fd(": Permission denied", STDERR_FILENO);
		else if (access(cmd, F_OK) == 0
			&& cmd[0] != '/')
			ft_putstr_fd(": Is a directory", STDERR_FILENO);
		else
		{	
			ft_putstr_fd(": No such file or directory", STDERR_FILENO);
			g_err_code += 1;
		}
	}
	else
	{	
		ft_putstr_fd(": command not found\n", STDERR_FILENO);
		g_err_code = 127;
	}
	free (cmd);
}

void	error_syntax(t_data *data, int z, int opt)
{
	char	err_char;

	err_char = data->line[z];
	data->exec_stat = 0;
	ft_putstr_fd(" syntax error near unexpected token `", STDERR_FILENO);
	if (err_char == '\0' && opt != 2)
		ft_putstr_fd("newline", STDERR_FILENO);
	else
	{	
		while (data->line[z] == err_char)
		{
			ft_putchar_fd(err_char, STDERR_FILENO);
			z++;
		}
	}
	ft_putchar_fd(39, STDERR_FILENO);
	ft_putchar_fd('\n', STDERR_FILENO);
	g_err_code = 2;
}
