/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toolbox_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoichon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 09:58:55 by agoichon          #+#    #+#             */
/*   Updated: 2023/03/09 15:05:53 by agoichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_swap(char **s1, char **s2)
{
	char	*tmp;

	tmp = ft_strdup(*s1);
	*s1 = ft_strdup(*s2);
	*s2 = ft_strdup(tmp);
	free (tmp);
}

void	ft_sort_ascii(char **str)
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

char	*export_tools(char **argz, int i)
{
	int		j;
	char	*rtn;

	j = 0;
	rtn = ft_calloc(sizeof(char), ft_strlen(argz[i]) + 1);
	while (argz[i][j] != '=' && argz[i][j])
	{
		rtn[j] = argz[i][j];
		j++;
	}
	return (rtn);
}
