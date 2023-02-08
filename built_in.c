/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoichon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 11:27:29 by agoichon          #+#    #+#             */
/*   Updated: 2023/02/08 09:19:53 by agoichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "minishell.h"
#include <stdlib.h>
#include <unistd.h>


static void	ft_sort_ascii(t_list **list)
{
	t_list	*tmpi;
	t_list	*tmpj;
	char	*tmp_value;
	char	*tmp_name;

	tmpi = *list;
	while(tmpi)
	{
		tmpj = tmpi->next;
		while (ft_strncmp(tmpi->name, tmpj->name, ft_strlen(tmpj->name)) > 0)
		{
			tmp_value = tmpi->value;
			tmpi->value = tmpj->value;
			tmpj->value = tmp_value;
			tmp_name = tmpi->name;
			tmpi->name = tmpj->name;
			tmpj->name = tmp_name;
		}
		tmpj = tmpj->next;
	}	
	tmpi = tmpi->next;

}	

int	built_in_export(t_data *data)
{
	int		i;
	int		j;
	int		k;

	if (data->argz[1] == NULL)
	{
		ft_sort_ascii(&data->env);
		while (data->env)
		{
			printf("%p\n", data->env->name);
		}	
	}	
	else
	{
		i = 1;
		j = 0;
		while (data->argz[i][j])
		{
			while (data->argz[i][j] != '=')
			{
				if (ft_isalpha(data->argz[i][j]) == 1)
				{
					ft_putstr_fd(&data->argz[i][j], 2);
					ft_putstr_fd(" : not a valid identifier\n", 2);
					return (0);
				}	
				data->exp->var[j] = data->argz[i][j];
				j++;
			}	
			if (data->argz[i][j] == '=')
				j++;
			k = 0;
			while (data->argz[i][j])
			{
				data->exp->new_value[k] = data->argz[i][j];
				i++;
				k++;
			}
			j = 0;
			ft_lstadd_back(data->env->content, data->env->next);
			i++;
		}
		return (0);
	}
	return (0);
}

/*static void	del(void *ptr)
{
	t_data *data = NULL;
	(void) ptr;
	{
		data->env->content = NULL;
	}	
}

void	built_in_unset(t_data *data)
{
	int	i;

	i = 0;
	while (data->argz[1][i])
	{	
		if (ft_strncmp(data->argz[1], data->env->content, ft_strlen(data->argz[1])) == 0)
			ft_lstdelone(data->env, &del);
		if (ft_isalpha(data->argz[1][i]) == 1)
		{
			ft_putstr_fd("Not a valid Indentifier\n", 2);
			break ;
		}
		i++;
	}		
}*/





int built_in (t_data *data)
{
	if (ft_strncmp(data->argz[0], "echo", ft_strlen(data->argz[0])) == 0)
	{
		built_in_echo(data);
		return(0);
	}
	if (ft_strncmp(data->argz[0], "cd", 2) == 0)
	{
		built_in_cd(data);
		return(0);
	}
	if (ft_strncmp(data->argz[0], "pwd", ft_strlen(data->argz[0])) == 0)
	{
		built_in_pwd(data);
		return(0);
	}
	if (ft_strncmp(data->argz[0], "export", ft_strlen(data->argz[0])) == 0)
	{
		built_in_export(data);
		return (0);
	}/*	if (ft_strncmp(data->argz[0], "unset", ft_strlen(data->argz[0])) == 0)
	{
		built_in_unset(data);
		return (0);
	}*/
	if (ft_strncmp(data->argz[0], "env", ft_strlen(data->argz[0])) == 0)
	{
		built_in_env(data);
		return (0);
	}
	if (ft_strncmp(data->argz[0], "exit", ft_strlen(data->argz[0])) == 0)
		built_in_exit(data);
	return (-1);
}	
