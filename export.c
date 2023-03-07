/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoichon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 09:25:01 by agoichon          #+#    #+#             */
/*   Updated: 2023/03/07 10:44:00 by agoichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	built_in_export_utils(t_data *data)
{
	int		i;
	int		len;
	char	**envp;
	char	*result;
	char	*name;

	i = 0;
	envp = convert_env(data->env);
	ft_sort_ascii(envp);
	while (envp[i])
	{	
		len = 0;
		while (envp[i][len] != '=' && envp[i][len])
			len++;
		result = ft_strchr(envp[i], '=') + 1;
		name = ft_substr(envp[i], 0, len);
		if (ft_strchr(envp[i], '=') == 0)
			i++;
		else
		{
			if (*envp[i] == '_')
				i++;
			else
			{	
				printf("declare -x %s=\"%s\"\n", name, result);
				free(name);
				i++;
			}
		}	
	}
	g_err_code = 0;
	free_loop(envp);
}	

void	built_in_export(t_data *data)
{
	int		i;
	int		j;
	t_list	*p_val;
	char	*c_val;

	if (data->argz[1] != NULL)
	{
		if (data->argz[1][0] == '=')
		{
			g_err_code = 1;
			ft_putstr_fd(data->argz[1], 2);
			ft_putstr_fd(" : not a valid identifier\n", 2);
			return ;
		}
		i = 1;
		j = 0;
		if (data->nb_cmds > 1)
			return ;
		c_val = export_tools(data->argz, i);
		p_val = data->env;
		while (data->argz[i])
		{
			while (p_val->next != NULL)
			{	
				if (ft_strncmp(p_val->env_copy, c_val,
						ft_strlen(p_val->env_copy)) == 0)
				{
					free(p_val->env_copy);
					p_val->env_copy = NULL;
					p_val->env_copy = ft_strdup(data->argz[i]);
					return ;
				}	
				p_val = p_val->next;
			}
			if (ft_isalpha(data->argz[i][0]) == 0)
			{
				ft_putstr_fd(data->argz[i], 2);
				ft_putstr_fd(" : not a valid identifier\n", 2);
				g_err_code = 1;
				return ;
			}
			while (data->argz[i][j] != '=' && data->argz[i][j])
			{
				if (data->argz[i][j] == '\0')
				{
					j = 0;
					while (data->argz[i][j])
					{	
						if (ft_isalnum(data->argz[i][j]) == 0)
						{
							g_err_code = 1;
							ft_putstr_fd(" not a valid identifier\n", 2);
							return ;
						}
						j++;
					}		
				}	
				j++;
			}
			if (data->argz[i][j - 1] == '-')
			{
				ft_putstr_fd(" not a valid identifier\n", 2);
				g_err_code = 1;
				return ;
			}
			ft_lstadd_back(&data->env, ft_lstnew(ft_strdup(data->argz[i])));
			i++;
		}
	}	
	else
		built_in_export_utils(data);
}
