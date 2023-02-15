/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoichon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 09:27:32 by agoichon          #+#    #+#             */
/*   Updated: 2023/02/15 15:41:45 by agoichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "minishell.h"
#include <stdlib.h>

void	built_in_cd(t_data *data)
{
	char	*path;

	if (data->argz[1] == NULL)
	{
		path = getenv("HOME");
		chdir(path);
	}
	else
	{	
		if (access(data->argz[1], F_OK) == 0 && data->argz[2] == NULL)
			chdir(data->argz[1]);
		else if (data->argz[2] != NULL)
		{	
			ft_putstr_fd(" too many arguments\n", 2);
			err_code = 1;
			return ;
		}
		else
		{
			ft_putstr_fd(" No such file or directory\n", 2);
			err_code = 1;
			return ;
		}
		err_code = 0;
	}
}

void	built_in_pwd(t_data *data)
{
	char	cwd[PATH_MAX];

	(void) data;
	if (getcwd(cwd, sizeof(cwd)) == NULL)
		ft_putstr_fd("Error getting current working directory\n", 1);
	else
		printf("%s\n", cwd);
}

void	built_in_env(t_data *data)
{
	while (data->env != NULL)
	{
		printf("%s\n", data->env->env_copy);
		data->env = data->env->next;
	}
}

void	built_in_unset(t_data *data)
{
	t_list	*tmp;
	t_list	*p_tmp;
	int		i;

	if (data->argz[1] == NULL)
		return ;
	i = 1;
	tmp = data->env;
	while (data->argz[i])
	{
		if (ft_strncmp(tmp->env_copy, data->argz[i], ft_strlen(data->argz[i])) == 0)
		{
			data->env = data->env->next;
			free(tmp);
		}
		else
		{
			while (ft_strncmp(tmp->next->env_copy, data->argz[i], ft_strlen(data->argz[i])) != 0)
				tmp = tmp->next;
			p_tmp = tmp->next;
			tmp->next = p_tmp->next;
			err_code = 0;
			free(p_tmp);
		}	
		i++;
	}
}
