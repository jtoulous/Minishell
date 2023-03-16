/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoichon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 13:06:06 by agoichon          #+#    #+#             */
/*   Updated: 2023/03/16 08:52:49 by agoichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static void	cd_utils(t_data *data)
{
	char	*tmp;
	char	buf[1024];

	chdir(data->argz[1]);
	tmp = env_search(data->env, "PWD");
	if (!tmp)
		return ;
	free (data->argz[1]);
	data->argz[1] = ft_strjoin("OLDPWD=", tmp);
	built_in_export(data, 1, 0, 0);
	mega_free(data->argz[1], tmp, NULL, NULL);
	getcwd(buf, 1023);
	data->argz[1] = ft_strjoin("PWD=", buf);
	built_in_export(data, 1, 0, 0);
}

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
			cd_utils(data);
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
