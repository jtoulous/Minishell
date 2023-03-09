/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoichon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:35:25 by agoichon          #+#    #+#             */
/*   Updated: 2023/03/03 10:08:52 by agoichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	the_last_inredir(char *line, int spot)
{
	int	end;

	spot++;
	end = end_of_cmd(line, spot);
	while (spot < end)
	{
		if (line[spot] == '<' && valid_inredir(line, spot) == 1)
			return (0);
		spot++;
	}
	return (1);
}

int	set_up_inredir(char *file, t_data *data, int spot)
{
	data->infile = open(file, O_RDONLY);
	if (data->infile == -1)
		return (error_inredir(file, 1));
	trim_redir(data->line, spot);
	free (file);
	return (1);
}

int	check_inredir(t_data *data, int z)
{
	char	*file;

	file = extract_redir(data->line, z);
	if (the_last_inredir(data->line, z) == 1)
		return (set_up_inredir(file, data, z));
	else
	{			
		if (access(file, F_OK) != 0)
			return (error_inredir(file, 1));
		trim_redir(data->line, z);
		free (file);
	}
	return (1);
}

int	set_up_outredir(t_data *data, int spot)
{
	char	*file;

	file = extract_redir(data->line, spot);
	if (access(file, X_OK) != 0 && access(file, F_OK) == 0)
	{
		error_permission(data);
		return (0);
	}
	if (data->line[spot + 1] == '>')
		data->outfile = open(file, O_RDWR | O_CREAT | O_APPEND, 0777);
	else
		data->outfile = open(file, O_RDWR | O_CREAT | O_TRUNC, 0777);
	trim_redir(data->line, spot);
	return (1);
}

int	check_redirz(t_data *data, int end)
{
	int	z;

	z = 0;
	while (z < end)
	{
		end = end_of_cmd(data->line, 0);
		if (data->line[z] == '>' && in_or_out(data->line, z) == 0)
		{	
			if (data->outfile != -1)
				close (data->outfile);
			if (set_up_outredir(data, z) != 1)
				return (0);
		}
		if (data->line[z] == '<' && valid_inredir(data->line, z) == 1)
		{
			if (check_inredir(data, z) != 1)
				return (0);
		}
		z++;
	}
	return (1);
}
