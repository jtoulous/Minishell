/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toolbox.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoichon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:37:05 by agoichon          #+#    #+#             */
/*   Updated: 2023/02/02 17:07:31 by agoichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	skip_out(char *line, int *z)
{
	char	q_type;
	
	q_type = line[*z];
	*z++;
	while (line[*z] != q_type && line[*z])
		*z++;
}

int	in_or_out(char *line, int index)
{
	int	z;
	t_data	*data;
	
	z = 0;
	while (z < index)
	{
		if (line[z] == 44 || line[z] == 34)
			skip_out(data->line, &z);
		z++;
	}
	if (z > index && line[z] == 34)
		return (1);
	else if (z > index && line[z] == 44)
		return (2);
	return (0);
}

int	nb_cmd(char *line)
{
	static int	count;
	int		z;
	
	z = 0;
	if (line == NULL)
		return (count);
	count = 0;
	while (line[z])
	{
		if (line[z] == '|' && valid_pipe(line, z) == 1)
			count++;
	}
	return (count + 1);
}

int	end_of_cmd(char *line, int spot)
{
	while ((line[spot] != '|' 
		|| valid_pipe(line, spot) != 1)
		&& line[spot])
		spot++;
	return (spot);
}

