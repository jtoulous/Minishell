/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoichon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 09:27:32 by agoichon          #+#    #+#             */
/*   Updated: 2023/03/16 09:51:24 by agoichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	built_in_pwd(t_data *data)
{
	char	cwd[PATH_MAX];

	(void) data;
	if (getcwd(cwd, sizeof(cwd)) == NULL)
		ft_putstr_fd("Error getting current working directory\n", 1);
	else
		printf("%s\n", cwd);
}

void	built_in_env(t_data *data, int z, int y)
{
	if (!data->envp[0])
		return ;
	z = 1;
	while (data->envp[z])
	{
		y = 0;
		while (data->envp[z][y])
		{
			if (data->envp[z][y] == '=')
			{	
				printf("%s\n", data->envp[z]);
				break ;
			}
			if (data->envp[z][y] == '\0')
			{
				z++;
				y = 0;
				break ;
			}	
			y++;
		}
		z++;
	}
}

static void	built_in_unset_two(t_data *data, t_list *tmp, t_list *p_tmp, int i)
{	
	while (ft_strncmp(tmp->next->env_copy, data->argz[i],
			ft_strlen(data->argz[i])) != 0)
	{
		tmp = tmp->next;
		if (tmp->next == NULL)
		{
			tmp = NULL;
			g_err_code = 0;
			free(tmp);
			return ;
		}	
	}
	p_tmp = tmp->next;
	tmp->next = p_tmp->next;
	g_err_code = 0;
	free(p_tmp->env_copy);
	free(p_tmp);
}

static void	first_check_unset(t_data *data, int i)
{
	ft_putstr_fd(data->argz[i], 2);
	ft_putstr_fd(" : not a valid identifier\n", 2);
	g_err_code = 1;
}

void	built_in_unset(t_data *data, int i)
{
	t_list	*tmp;
	t_list	*p_tmp;

	if (data->argz[1] == NULL)
		return ;
	tmp = data->env;
	p_tmp = NULL;
	while (data->argz[i])
	{
		if (ft_isalpha(data->argz[i][0]) == 0 || data->argz[i][0] == '/')
		{
			first_check_unset(data, i);
			return ;
		}
		if (ft_strncmp(tmp->env_copy, data->argz[i],
				ft_strlen(data->argz[i])) == 0)
		{
			data->env = data->env->next;
			free(tmp->env_copy);
			free(tmp);
		}
		else
			built_in_unset_two(data, tmp, p_tmp, i);
		i++;
	}
}
