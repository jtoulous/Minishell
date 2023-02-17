/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoichon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:33:08 by agoichon          #+#    #+#             */
/*   Updated: 2023/02/13 08:34:27 by agoichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "minishell.h"
#include <readline/readline.h>

void	error_permission(void)
{
	ft_putstr_fd(" Permission denied", STDERR_FILENO);
	err_code = 1;
}

int	error_inredir(char *failed_redir, int error)
{
	ft_putstr_fd(failed_redir, STDERR_FILENO);
	ft_putstr_fd(": No such file or directory\n", STDERR_FILENO);
	free (failed_redir);
	err_code = error;
	return (0);
}

void	error_quotes(t_data *data)
{
	data->exec_stat = 0;
	ft_putstr_fd("Don't forget to close those quotes tight, Or you'll face an error with all its might!\n", STDOUT_FILENO);
}


void	error_path(char *cmd)
{
	ft_putstr_fd(cmd, STDERR_FILENO);
	if((cmd[0] == '.' && cmd[1] == '/')
		|| cmd[0] == '/')
	{	
		err_code = 126;
		if (access(cmd, X_OK) == -1 && access(cmd, F_OK) == 0)
			ft_putstr_fd(": Permission denied", STDERR_FILENO);
		else if (access(cmd, F_OK) == 0
			&& cmd[0] != '/')
			ft_putstr_fd(": Is a directory", STDERR_FILENO);
		else
		{	
			ft_putstr_fd(": No such file or directory", STDERR_FILENO);
			err_code += 1;
		}
	}
	else if (cmd[0] == '/')
	{
		
	}
	else
	{	
		ft_putstr_fd(": command not found\n", STDERR_FILENO);
		err_code = 127;
	}
	free (cmd);
}

void	error_syntax(t_data *data, int z)
{
	char	err_char;
	
	err_char = data->line[z];
	data->exec_stat = 0;
	ft_putstr_fd("syntax error near unexpected token `", 1);
	if (err_char == '\0')
		ft_putstr_fd("newline", 1);
	else
	{	
		while (data->line[z] == err_char)
		{
			ft_putchar_fd(err_char, 1);
			z++;
		}
	}
	ft_putchar_fd(39, 1);
	ft_putchar_fd('\n', 1);
	err_code = 2;
}
