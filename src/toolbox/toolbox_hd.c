/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toolbox_hd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoichon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:37:39 by agoichon          #+#    #+#             */
/*   Updated: 2023/03/09 17:54:48 by jtoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	check_if_used(char *line, int spot, int end)
{
	spot++;
	while (spot < end)
	{
		if (line[spot] == '<'
			&& (valid_hd(line, spot) == 1
				|| valid_inredir(line, spot) == 1))
			return (0);
		spot++;
	}
	return (1);
}

int	nb_hdocs(char *line)
{
	int	count;
	int	z;

	z = 0;
	count = 0;
	while (line[z])
	{
		if (line[z] == '<' && valid_hd(line, z) == 1)
			count++;
		z++;
	}
	return (count);
}

void	unlinkz(char *new)
{
	static t_list	*unlinks = NULL;
	t_list			*tmp;

	if (new)
	{
		ft_lstadd_back(&unlinks, ft_lstnew(new));
		return ;
	}
	if (unlinks != NULL)
	{
		tmp = unlinks;
		while (tmp->next != NULL)
		{
			unlink(tmp->env_copy);
			tmp = tmp->next;
		}
		unlink(tmp->env_copy);
		free_lst(unlinks);
		unlinks = NULL;
	}
}

int	lim_size(char *line, int spot)
{
	int	z;

	z = spot;
	while (line[z] != ' ')
		z++;
	return (z - spot + 1);
}

char	*hdoc_limit(char *line, int spot)
{
	char	*fnl;
	int		z;

	z = 0;
	while ((line[spot] == '<'
			|| line[spot] == ' ')
		&& line[spot])
		spot++;
	fnl = ft_calloc(lim_size(line, spot),
			sizeof(char));
	while (line[spot] != ' ')
	{
		if (line[spot] == 34 || line[spot] == 39)
			skip_n_copy_quote(line, fnl, &spot, &z);
		else
		{	
			fnl[z] = line[spot];
			z++;
			spot++;
		}	
	}	
	return (fnl);
}
