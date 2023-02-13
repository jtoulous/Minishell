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

int	error_inredir(char *failed_redir)
{
	ft_putstr_fd(failed_redir, STDOUT_FILENO);
	ft_putstr_fd(": No such file or directory\n", STDOUT_FILENO);
	free (failed_redir);
	//err_code = 1;
	return (0);
}

void	error_quotes(t_data *data)
{
	data->exec_stat = 0;
	ft_putstr_fd("va niquer ta race a pas fermer tes putains de quotesi\n", STDOUT_FILENO);
}

void	error_path(char *cmd)
{
	ft_putstr_fd(cmd, 1);
	ft_putstr_fd(": command not found\n", 1);
	free (cmd);
	//err_code = 127;
}
