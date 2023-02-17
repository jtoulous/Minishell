/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outredir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoichon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:36:47 by agoichon          #+#    #+#             */
/*   Updated: 2023/02/02 16:36:49 by agoichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	set_up_outredir(t_data *data, int spot)
{
	char	*file;
	
	file = extract_redir(data->line, spot);
	if (access(file, X_OK) != 0 && access(file, F_OK) == 0)
	{
		error_permission();
		return (0);
	}
	if (data->line[spot + 1] == '>')
		data->outfile = open(file, O_WRONLY | O_CREAT | O_APPEND, 0777);
	else
		data->outfile = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	trim_redir(data->line, spot);
	return (1);
}

int	check_outredir(t_data *data, int end)
{
	int	z;
	
	z = 0;
	while (z < end)
	{
		if (data->line[z] == '>' && in_or_out(data->line, z) == 0)
		{	
			if (data->outfile != -1)
				close (data->outfile);
			if (set_up_outredir(data, z) != 1)
				return (0);
		}
		z++;
	}
	return (1);
}
