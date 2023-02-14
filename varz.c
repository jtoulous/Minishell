/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   varz.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoichon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:37:56 by agoichon          #+#    #+#             */
/*   Updated: 2023/02/04 13:01:10 by agoichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	replace_var(t_data *data, int spot, int end_var, char *var_val)
{
	char	*ante;
	char	*pre;
	
	ante = ft_substr(data->line, 0, spot);
	pre = ft_substr(data->line, end_var, ft_strlen(data->line) - end_var);
	free (data->line);
	data->line = triple_strjoin(ante, var_val, pre);
	mega_free(ante, pre, NULL, NULL);
}

void	sub_var(t_data *data, int spot, int end_var)
{
	char	*var_val;
	char	*var;
	
	var = ft_substr(data->line, spot + 1, end_var - (spot + 1));
	var_val = env_search(data->env, var);
	//if (data->line[end_var + 1] == """)
	//	end_var++;
	if (!var_val)
		m_trime(data->line, spot, end_var);
	else
		replace_var(data, spot, end_var, var_val);
	mega_free(var_val, var, NULL, NULL);
}

/*void	sub_err_code(t_data *data, int spot)
{
	
}*/

void	scan_varz(t_data *data, int end, int spot)
{
		int	in_out;
		int	z;
		
		z = spot + 1;
		if (data->line[spot] == '$')
		{
			in_out = in_or_out(data->line, z);
			//if (data->line[spot + 1] == '!' && in_or_out != 2)
				//sub_err_code(data, spot);
			if (in_out != 2)
			{
				while (data->line[z] != ' ' 
					&& data->line[z] != 34
					&& (data->line[z] != '$') 
					&& z < end)
					z++;
				sub_var(data, spot, z);
			}
		}
}
