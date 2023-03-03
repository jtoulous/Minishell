/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toolbox.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoichon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:37:05 by agoichon          #+#    #+#             */
/*   Updated: 2023/03/02 12:57:09 by agoichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "minishell.h"

void	skip_out(char *line, int *z)
{
	char	q_type;
	
	q_type = line[*z];
	*z += 1;
	while (line[*z] != q_type && line[*z])
		*z += 1;
}

int	in_or_out(char *line, int index)
{
	int	z;
	
	z = 0;
	while (z < index)
	{
		if (line[z] == 39 || line[z] == 34)
			skip_out(line, &z);
		if (z > index && line[z] == 34)
			return (1);
		else if (z > index && line[z] == 39)
			return (2);
		z++;
	}
	return (0);
}

int	nb_cmd(char *line)
{
	static int	count;
	int		z;
	
	z = 0;
	if (line == NULL)
		return (count);
	count = 0;
	while (line[z])
	{
		if (line[z] == '|' && valid_pipe(line, z) == 1)
			count++;
		z++;
	}
	return (count + 1);
}

int	end_of_cmd(char *line, int spot)
{
	while ((line[spot] != '|' 
		|| valid_pipe(line, spot) != 1)
		&& line[spot])
		spot++;
	return (spot);
}

char	**convert_env(t_list *env)
{
	char	**converted;
	t_list	*tmp;
	int	z;
	
	tmp = env;
	z = ft_lstsize(env);
	converted = ft_calloc(z + 1, sizeof(char *));
	z = 0;
	while (tmp->next != NULL)
	{
		converted[z] = ft_strdup(tmp->env_copy);
		tmp = tmp->next;
		z++;
	}
	converted[z] = ft_strdup(tmp->env_copy);
	return (converted);
}


