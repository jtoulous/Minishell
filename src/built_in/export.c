/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoichon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 09:25:01 by agoichon          #+#    #+#             */
/*   Updated: 2023/03/13 15:15:31 by agoichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static int	export_check_three(t_data *data, int *i, int *j)
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

static int	export_check_two(t_data *data, t_list *p_val, char *c_val, int i)
{
	while (p_val != NULL)
	{
		if (ft_strncmp(p_val->env_copy, c_val,
				ft_strlen(c_val)) == 0)
		{
			free(p_val->env_copy);
			p_val->env_copy = NULL;
			p_val->env_copy = ft_strdup(data->argz[i]);
			free (c_val);
			return (0);
		}	
		p_val = p_val->next;
	}
	if (ft_isalpha(data->argz[i][0]) == 0)
	{
		ft_putstr_fd(data->argz[i], 2);
		ft_putstr_fd(" : not a valid identifier\n", 2);
		g_err_code = 1;
		free (c_val);
		return (0);
	}
	return (1);
}

static int	plus_check(t_data *data, char *c_val, t_list *p_val, int i)
{
	char	*tmp;

	if (c_val[ft_strlen(c_val) - 1] == '+')
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
				return (1);
			}	
			p_val = p_val->next;
		}	
	}
	return (0);
}

static void	export_checks(t_data *data, int i, int j)
{
	t_list	*p_val;
	char	*c_val;

	if (export_check_one(data) == 0)
		return ;
	c_val = export_tools(data->argz, i);
	p_val = data->env;
	while (data->argz[i])
	{
		if (export_check_two(data, p_val, c_val, i) == 0)
			return ;
		if (export_check_three(data, &i, &j) == 0)
		{	
			free (c_val);
			return ;
		}	
		if (plus_check(data, c_val, p_val, i) == 1)
			return ;
		ft_lstadd_back(&data->env, ft_lstnew(ft_strdup(data->argz[i])));
		i++;
	}
	free (c_val);
}

void	built_in_export(t_data *data, int i, int j)
{
	int		z;
	int		len;
	char	*result;
	char	*name;

	if (data->argz[1] != NULL)
		export_checks(data, i, j);
	else
	{
		z = 0;
		ft_sort_ascii(data->envp);
		while (data->envp[z])
		{	
			len = 0;
			while (data->envp[z][len] != '=' && data->envp[z][len])
				len++;
			result = ft_strchr(data->envp[z], '=') + 1;
			name = ft_substr(data->envp[z], 0, len);
			export_display(data->envp, &z, name, result);
			free (name);
		}
		g_err_code = 1;
	}
}
