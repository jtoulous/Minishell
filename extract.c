/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoichon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:33:26 by agoichon          #+#    #+#             */
/*   Updated: 2023/02/02 16:48:51 by agoichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*extract_redir(char *line, int spot)
{
	char	*to_test;
	int	z;
	
	spot++;
	while (line[spot] == ' ' && line[spot])
		spot++;
	if (line[spot] == 44 || line[spot] == 42)//ascii des quotes
		to_test = extract_from_quotes(line, spot);
	else	
	{
		z = spot;
		while ((line[z] != ' ' || in_or_out(line, z) != 0)
			&& (line[z] != '|' || valid_pipe(line, z) != 1) 
			&& line[z])
			z++;
		to_test = ft_substr(line, spot, z - spot);
	}
	return (to_test);
}

char	*extract_wipe_quotes(char *line, int z)
{
	char	*extracted;
	int 	end;
	
	end = z + 1;
	while ((line[end] != '\"' || in_or_out(line, end) != 0)
		&& (line[end] != '\'' || in_or_out(line, end) != 0)		
		&& line[end])
		end++;
	extracted = ft_substr(line, z + 1, end - (z + 1));
	end++;
	while (line[end])
	{
		line[z] = line[end];
		z++;
		end++;
	}
	return (extracted);
}

char	*extract_wipe(char *line, int z)
{
	char	*extracted;
	int 	end;
	
	end = z + 1;
	while ((line[end] != ' ' || in_or_out(line, end) != 0)
		&& (line[end] != '|' || valid_pipe(line, end) != 1)		
		&& line[end])
		end++;
	extracted = ft_substr(line, z, end - z);
	while (line[end])
	{
		line[z] = line[end];
		z++;
		end++;
	}
	return (extracted);
}

char	*get_nxt_stuff(char *line)//return the first word u meet
{
	int	z;
	char	*extracted;

	z = 0;
	while ((line[z] == ' ' || in_or_out(line, z) == 0)
		&& (line[z] != '|' || valid_pipe(line, z) != 1)
		&& line[z])
		z++;
	if (line[z] == '\'' || line[z] == '\"')
		extracted = extract_wipe_quotes(line, z);
	else
		extracted = extract_wipe(line, z);
	return (extracted);
}
