/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoichon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 11:27:29 by agoichon          #+#    #+#             */
/*   Updated: 2023/02/10 15:28:01 by agoichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft/libft.h"
#include "minishell.h"
#include <stdlib.h>
#include <unistd.h>

/*-------------------export*/
static void	ft_swap(char **s1, char **s2)
{
	char *tmp;

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

void	built_in_export(t_data *data)
{
	int		i;
	//t_list *val;
	char	**envp;

	if (data->argz[1] != NULL)
	{
		i = 1;
		while (data->argz[i])
		{
				if (ft_isalpha(data->argz[i][0]) == 0)
				{
					ft_putstr_fd(data->argz[i], 2);
					ft_putstr_fd(" : not a valid identifier\n", 2);
					break ;
				}	
				export_env(&data->env, &data->argz[i]);
		}
	}
	else 
	{	
		i = 0;
		envp = convert_env(data->env);

		ft_sort_ascii(envp);
		while (envp[i])
		{
			if (*envp[i] == '_')
				break;
			printf("%sdeclare - x%s %s\n", LIGHTPURPLE, NEUTRAL, envp[i]);
			i++;
		}
	}

}

/*---------------------unset---------------------------------------------*/
void built_in_unset(t_data *data)
{
	t_list *tmp;
	t_list *p_tmp;
	int		i;

	if (data->argz[1] == NULL)
		return ;
	i = 1;
	while (data->argz[i])
	{	
		tmp = data->env;
		while (ft_strncmp(tmp->next->env_copy, data->argz[i], ft_strlen(data->argz[i])) != 0)
			tmp = tmp->next;
		p_tmp = tmp->next;
		tmp->next = p_tmp->next;
		i++;
	}	
	free(p_tmp);
}	

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
	}
		if (ft_strncmp(data->argz[0], "unset", ft_strlen(data->argz[0])) == 0)
	{
		built_in_unset(data);
		return (0);
	}
	if (ft_strncmp(data->argz[0], "env", ft_strlen(data->argz[0])) == 0)
	{
		built_in_env(data);
		return (0);
	}
	if (ft_strncmp(data->argz[0], "exit", ft_strlen(data->argz[0])) == 0)
		built_in_exit(data);
	return (-1);
}	
