/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoichon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:33:08 by agoichon          #+#    #+#             */
/*   Updated: 2023/02/02 16:33:10 by agoichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	error_inredir(char *failed_redir)
{
	ft_putstr_fd(failed_redir, STDOUT_FILENO);
	ft_putstr_fd(": No such file or directory", STDOUT_FILENO);
	free (failed_redir);
	return (0);
}

void	error_quotes(t_data *data)
{
	data->exec_stat = 0;
	ft_putstr_fd("va niquer ta race a pas fermer tes putains de quotes", STDOUT_FILENO);
}

void	error_path(char *cmd)
{
	ft_putstr_fd(cmd, 1);
	ft_putstr_fd(": command not found", 1);
	free (cmd);
}
