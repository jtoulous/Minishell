/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoichon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 09:25:01 by agoichon          #+#    #+#             */
/*   Updated: 2023/03/13 11:17:51 by agoichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"
#include <stdlib.h>

static void	export_display(char **envp, int *i, char *name, char *result)
{
	if (ft_strchr(envp[*i], '=') == 0)
		*i += 1;
	else
	{
		if (*envp[*i] == '_')
			*i += 1;
		else
		{	
			printf("declare -x %s=\"%s\"\n", name, result);
			free(name);
			*i += 1;
		}
	}	
}

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
		export_display(envp, &i, name, result);
	}
	g_err_code = 1;
	free_loop(envp);
}	

int	export_check_three(t_data *data, int *i, int *j)
{
	while (data->argz[*i][*j] != '=' && data->argz[*i][*j])
	{
		if (data->argz[*i][*j] == '\0')
		{
			*j = 0;
			while (data->argz[*i][*j])
			{	
				if (ft_isalnum(data->argz[*i][*j]) == 0)
				{
					g_err_code = 1;
					ft_putstr_fd(" not a valid identifier\n", 2);
					return (0);
				}
				*j += 1;
			}		
		}	
		*j += 1;
	}
	if (data->argz[*i][*j - 1] == '-')
	{
		ft_putstr_fd(" not a valid identifier\n", 2);
		g_err_code = 1;
		return (0);
	}
	return (1);
}

int	export_check_two(t_data *data, t_list *p_val, char *c_val, int i)
{
	while (p_val != NULL)
	{
		if (ft_strncmp(p_val->env_copy, c_val,
				ft_strlen(c_val)) == 0)
		{
			free(p_val->env_copy);
			p_val->env_copy = NULL;
			p_val->env_copy = ft_strdup(data->argz[i]);
			return (0);
		}	
		p_val = p_val->next;
	}
	if (ft_isalpha(data->argz[i][0]) == 0)
	{
		ft_putstr_fd(data->argz[i], 2);
		ft_putstr_fd(" : not a valid identifier\n", 2);
		g_err_code = 1;
		return (0);
	}
	return (1);
}

void	built_in_export(t_data *data, int i, int j)
{
	t_list	*p_val;
	char	*c_val;
	int		len;
	char	*tmp;

	if (data->argz[1] != NULL)
	{
		if (export_check_one(data) == 0)
			return ;
		c_val = export_tools(data->argz, i);
		p_val = data->env;
		while (data->argz[i])
		{
			if (export_check_two(data, p_val, c_val, i) == 0)
				return ;
			if (export_check_three(data, &i, &j) == 0)
				return ;
			len = ft_strlen(c_val);
			if (c_val[len - 1] == '+')
			{
				while (p_val != NULL)
				{
					if (ft_strncmp(p_val->env_copy, c_val, ft_strlen(c_val) - 1) == 0)
					{
						free(c_val);
						c_val = ft_strdup(p_val->env_copy);
						tmp = ft_strchr(data->argz[i], '=') + 1;
						free(p_val->env_copy);
						p_val->env_copy = ft_strjoin(c_val, tmp);
						free(c_val);
						return ;
					}	
					p_val = p_val->next;
				}	
			}	
			ft_lstadd_back(&data->env, ft_lstnew(ft_strdup(data->argz[i])));
			i++;
		}
	}	
	else
		built_in_export_utils(data);
}
