/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoichon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 11:27:29 by agoichon          #+#    #+#             */
/*   Updated: 2023/01/31 16:39:14 by agoichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "minishell.h"
//#include "minishell.h"
#include <stdlib.h>
#include <unistd.h>
#include <linux/limits.h>
#include <stdio.h>
typedef struct env_list
{
	char			*line;
	struct env_list	*nxt;
}		t_env;

typedef struct pipex_data
{
	t_env		*env;
	char		*line;
	char		**argz;
	int		**pipe;
	int		infile;
	int		outfile;
	int		prev_outfile;
	int		exec_stat;
}		t_data;

void	built_in_echo(t_data data)
{
	int i;
	int j;
	if (ft_strncmp(data.argz[0], "echo", 4) == 0)
	{
		if (ft_strncmp(data.argz[1], "-n", 2) == 0)
		{
			j = 3;
			while (data.argz[1][j] == 'n')
			{
				j++;
			}
			i = 2;
			if (ft_strncmp(data.argz[i], "-n", 2))
				i++;
			while (data.argz[i])
			{
				printf("%s", data.argz[i]);
				i++;
			}
		}		
		else	
		{
			i = 1;
			while (data.argz[i])
			{
				printf("%s", data.argz[i]);
				i++;
			}
			printf("\n");
		}
	}
}

void	built_in_cd(t_data data)
{
	if (ft_strncmp(data.argz[0], "cd", 2) == 0)
	{
		if (access(data.argz[1], F_OK) == 0 && data.argz[2] == NULL)
			chdir(data.argz[1]);
		else if (data.argz[2] != NULL)
			ft_putstr_fd("too many arguments\n", 1);
		else if (access(data.argz[1], F_OK) != 0)
			ft_putstr_fd("No such file or Directory\n", 1);
	}
}

void	built_in_pwd(t_data data)
{
	char cwd[PATH_MAX];

	if (ft_strncmp(data.argz[0], "pwd", ft_strlen(data.argz[0])) == 0)
	{	
		if (getcwd(cwd, sizeof(cwd)) == NULL)
		{
			ft_putstr_fd("Error getting cirrent workimg directory\n", 1);
		}
		else
			ft_putstr_fd(cwd, 0);
	}	
}

void built_in_export(t_data data)
{
	char *value;
	char *new_value;
	int	i;
	int	j;
	int	k;

	j = 1;
	if(ft_strncmp(data.argz[0], "export", ft_strlen(data.argz[0])) == 0)
	{
		i = 0;
		k = 0;
		while(ft_isprint(data.argz[j][i]) == 0)
		{
			while (data.argz[j][i] != '=')
			{	
				value[k] = data.argz[j][i];
				i++;
				k++;
			}	
			if (data.argz[j][i] == '=')
				j++;
			k = 0;
			while(data.argz[j][i] != '\0')
			{	
				new_value[k] = data.argz[j][i];
				i++;
				k++;
			}
			value = getenv(new_value);
		}	
		j++;
	}	
}

void	built_in_unset(t_data data)
{

}

void	built_in_env(t_data data)
{

}	

void	built_in_exit(t_data data)
{
	int	i;

	i = 0;
	if (ft_strncmp(data.argz[0], "exit", ft_strlen(data.argz[0])) == 0)
	{
		if (data.argz[1] != NULL)
		{	
			
			i = ft_atoi(data.argz[1]);
		}
		ft_putstr_fd("exit", 0);
		free_and_close_all(data, 2);
		exit (i);
	}	
}


