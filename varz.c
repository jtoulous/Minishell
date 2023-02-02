/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   varz.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoichon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:37:56 by agoichon          #+#    #+#             */
/*   Updated: 2023/02/02 16:37:57 by agoichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	remove_var(char *line, int spot, int end_var)//icicicicici
{
	
}

void	str_sub(char *line, int spot, int end)
{
	char	*ante;
	char	*pre;
	
	if (!line)
		return;
	ante = ft_substr(line, 0, spot);
	pre = ft_substr(line, end, ft_strlen(line) - end);
	free (line);
	line = ft_strjoin(ante, pre);
	mega_free(ante, pre, NULL, NULL);
}

void	sub_var(t_data *data, int spot, int end_var, int end_com)
{
	char	*var_val;
	
	var_val = env_search(data->env, 
	ft_substr(data->line, spot + 1, end_var - (spot + 1));
	//if (data->line[end_var + 1] == """)
	//	end_var++;
	if (!var_val)
		str_sub(data->line, spot, end_var);
	else
		replace_var(data->line, spot, end_var, var_val);//ICIIIIII
}

void	scan_varz(t_data *data, int end, int spot)
{
		int	in_or_out;
		int	z;
		
		z = spot + 1;
		if (data->line[spot] == '$')
		{
			in_or_out = in_or_out(data->line, z);
			if (in_or_out != 2)
			{
				while (data->line[z] != ' ' 
					&& data->line[z] != '"'
					&& z < end - 1)
					z++;
				sub_var(data, spot, z, end);
			}
		}
}
