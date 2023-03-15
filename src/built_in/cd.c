/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoichon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 13:06:06 by agoichon          #+#    #+#             */
/*   Updated: 2023/03/15 10:48:37 by agoichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"
#include <stdlib.h>
#include <unistd.h>

void	built_in_cd(t_data *data)
{
	char	*path;
	char	*tmp;
	char	*pwd;
	char	*new_pwd;

	if (data->argz[1] == NULL)
	{
		path = getenv("HOME");
		chdir(path);
	}
	else
	{	
		if (access(data->argz[1], F_OK) == 0 && data->argz[2] == NULL)
		{
			tmp = getenv("PWD");
			chdir(data->argz[1]);
			pwd = ft_strdup(data->argz[1]);
			data->argz[2] = ft_strdup("OLDPWD=");
			free(data->argz[1]);
			data->argz[1] = ft_strjoin(data->argz[2], tmp);
			built_in_export(data, 1, 0, 0);
			free(data->argz[2]);
			data->argz[2] = ft_strdup("PWD=");
			new_pwd = ft_strjoin("/", pwd);
			free(data->argz[1]);
			data->argz[1] = triple_strjoin(data->argz[2], tmp , new_pwd);
			mega_free(NULL, pwd, new_pwd, NULL);
			built_in_export(data, 1, 0, 0);
}
		else if (data->argz[2] != NULL)
		{	
			ft_putstr_fd(" too many arguments\n", 2);
			g_err_code = 1;
			return ;
		}
		else
		{
			ft_putstr_fd(" No such file or directory\n", 2);
			g_err_code = 1;
			return ;
		}
		g_err_code = 0;
	}
}
