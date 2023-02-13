/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoichon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 09:25:01 by agoichon          #+#    #+#             */
/*   Updated: 2023/02/13 09:31:27 by agoichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
	char	**envp;

	i = 0;
	envp = convert_env(data->env);
	ft_sort_ascii(envp);
	while (envp[i])
	{
		if (*envp[i] == '_')
			i++;
		else
		{	
			printf("%sdeclare - x%s %s\n", LIGHTPURPLE, NEUTRAL, envp[i]);
			i++;
		}	
	}
}	

void	built_in_export(t_data *data)
{
	int		i;
	t_list	*val;

	if (data->argz[1] != NULL)
	{
		i = 1;
		val = ft_lstnew(data->argz[i]);
		val->env_copy = ft_strdup (data->argz[i]);
		while (data->argz[i])
		{
			if (ft_isalpha(data->argz[i][0]) == 0)
			{
				ft_putstr_fd(data->argz[i], 2);
				ft_putstr_fd(" : not a valid identifier\n", 2);
				break ;
			}
			val = ft_lstnew(data->argz[i]);
			val->env_copy = ft_strdup (data->argz[i]);
			ft_lstadd_back(&data->env, val);
			i++;
		}
	}	
	else
		built_in_export_utils(data);
}
