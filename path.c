/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoichon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 09:27:32 by agoichon          #+#    #+#             */
/*   Updated: 2023/02/13 10:14:53 by agoichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
			ft_putstr_fd("too many arguments\n", 2);
		else if (access(data->argz[1], F_OK) != 0)
			ft_putstr_fd("No such file or Directory\n", 2);
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
	int		i;
	char	**envp;

	i = 0;
	envp = convert_env(data->env);
	while (envp[i])
	{
		printf("%s\n", envp[i]);
		i++;
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
	while (data->argz[i])
	{	
		tmp = data->env;
		while (ft_strncmp(tmp->next->env_copy,
				data->argz[i], ft_strlen(data->argz[i])) != 0)
			tmp = tmp->next;
		p_tmp = tmp->next;
		tmp->next = p_tmp->next;
		i++;
	}	
	free(p_tmp);
}
