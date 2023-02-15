/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoichon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 09:25:01 by agoichon          #+#    #+#             */
/*   Updated: 2023/02/14 16:52:59 by agoichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "minishell.h"
#include <stdlib.h>

static void	ft_swap(char **s1, char **s2)
{
	char	*tmp;

	tmp = ft_strdup(*s1);
	*s1 = ft_strdup(*s2);
	*s2 = ft_strdup(tmp);
	free (tmp);
}	

static void	ft_sort_ascii(char **str)
{
	int		i;

	i = 0;
	while (str[i + 1])
	{	
		if (ft_strcmp(str[i], str[i + 1]) > 0)
		{
			ft_swap(&str[i], &str[i + 1]);
			i = 0;
		}
		else
			i++;
	}	
}

void	ft_strcp(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
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
		printf("declare -x %s=\"%s\"\n", name, result);
		free(name);
		i++;
	}
	free(envp);
}	

static char	*export_tools(char **str, int i)
{
	int		j;
	char	*rtn;

	j = 0;
	rtn = ft_calloc(sizeof(char), ft_strlen(str[i]));
	while (str[i][j] != '=' && str[i][j])
	{
		rtn[j] = str[i][j];
		j++;
	}
	return (rtn);
}	

void	built_in_export(t_data *data)
{
	int		i;
	int		j;
	t_list	*p_val;
	char	*c_val;

	if (data->argz[1] != NULL)
	{
		i = 1;
		j = 0;
		c_val = export_tools(data->argz, i);
		p_val = data->env;
		while (data->argz[i])
		{
			while (p_val)
			{	
				if (ft_strncmp(p_val->env_copy, c_val, ft_strlen(c_val)) == 0)
				{
					free(p_val->env_copy);
					p_val->env_copy = ft_strdup(data->argz[i]);
					return ;
				}	
				p_val = p_val->next;
			}
			if (ft_isalpha(data->argz[i][0]) == 0)
			{
				ft_putstr_fd(data->argz[i], 2);
				ft_putstr_fd(" : not a valid identifier\n", 2);
				break ;
			}
			ft_lstadd_back(&data->env, ft_lstnew(ft_strdup(data->argz[i])));
			i++;
		}
	}	
	else
		built_in_export_utils(data);
}
