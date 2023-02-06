/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trimage.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoichon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:37:42 by agoichon          #+#    #+#             */
/*   Updated: 2023/02/04 13:01:51 by agoichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	trim_redir(char *line, int spot)
{
	int	z;
	
	z = spot + 1;
	while (line[z] == ' ' && line[z])
		z++;
	while ((line[z] != ' ' || in_or_out(line, z) != 0)
		&& (line[z] != '|' || valid_pipe(line, z) != 0)
		&& line[z])
		z++;
	while (line[z])
	{
		line[spot] = line[z];
		spot++;
		z++;
	}
	while (line[spot])
	{
		line[spot] = '\0';
		spot++;
	}
}

void	trim_leftovers(char *line)
{
	int	z;
	int 	y;
	
	z = 0;
	y = 0;
	while ((line[z] != '|' || valid_pipe(line, z) != 1)
		&& line[z])
		z++;
	z++;
	while (line[z])
	{
		line[y] = line[z];
		z++;
		y++;
	}
	while (line[y])
	{
		line[y] = '\0';
		y++;
	}
}

void	trim_hdoc(char *line, int spot)
{
	int	z;
	
	z = spot;
	while ((line[z] == '<' || line[z] == ' ')
		&& line[z])
		z++;
	while ((line[z] != ' ' || in_or_out(line, z) != 1)
		&& (line[z] != '|' || valid_pipe(line, z) != 1) 
		&& line[z])
		z++;
	while (line[z])
	{
		line[spot] = line[z];
		spot++;
		z++; 
	}
}
