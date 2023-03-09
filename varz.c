/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   varz.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoichon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:37:56 by agoichon          #+#    #+#             */
/*   Updated: 2023/03/07 09:46:00 by agoichon         ###   ########.fr       */
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
	if (!var_val)
		m_trim(data->line, spot, end_var - 1);
	else
		replace_var(data, spot, end_var, var_val);
	mega_free(var_val, var, NULL, NULL);
}

void	sub_err_code(t_data *data, int spot)
{
	int		z;
	char	*ante;
	char	*pre;
	char	*error;

	z = spot + 2;
	while (data->line[z])
		z++;
	error = ft_itoa(g_err_code);
	ante = ft_substr(data->line, 0, spot);
	pre = ft_substr(data->line, spot + 2, z - (spot + 2));
	free (data->line);
	data->line = triple_strjoin(ante, error, pre);
	mega_free(ante, pre, error, NULL);
}

int	scan_varz(t_data *data, int end, int spot, int z)
{
	if (data->line[spot] == '$' && in_or_out(data->line, z) != 2)
	{
		if (data->line[z] == ' '
			|| data->line[z] == 34
			|| data->line[z] == 39
			|| data->line[z] == '\0'
			|| valid_pipe(data->line, z) == 1)
			return (0);
		if (data->line[z] == '?')
			sub_err_code(data, spot);
		else
		{
			while (data->line[z] != ' '
				&& data->line[z] != 34
				&& data->line[z] != 39
				&& (data->line[z] != '$')
				&& z < end)
				z++;
			sub_var(data, spot, z);
		}
		return (1);
	}
	return (0);
}
