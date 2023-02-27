/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inredir.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoichon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:35:25 by agoichon          #+#    #+#             */
/*   Updated: 2023/02/02 16:35:34 by agoichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	the_last_inredir(char *line, int spot)//GOOD
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
	//int	z;
	char	*file;
	
	/*z = 0;
	while (z < end)
	{
		end = end_of_cmd(data->line, z);
		if (data->line[z] == '<' && valid_inredir(data->line, z) == 1)
		{*/
			file = extract_redir(data->line, z);
			if (the_last_inredir(data->line, z) == 1)
				return (set_up_inredir(file, data, z));//open, store in data->infile
			else
			{			
				if (access(file, F_OK) != 0)
					return (error_inredir(file, 1));
				trim_redir(data->line, z);
				free (file);
			}
		//}
		//z++;
	//}
	return (1);
}
