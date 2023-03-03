/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoichon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:33:26 by agoichon          #+#    #+#             */
/*   Updated: 2023/03/03 10:03:53 by agoichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*extract_from_quotes(char *line, int spot)
{
	int		end;
	int		z;
	char	*extract;

	z = 0;
	end = spot + 1;
	while ((line[end] != ' ' || in_or_out(line, end) != 0)
		&& (line[end] != '|' || valid_pipe(line, end) != 1)
		&& line[end])
		end++;
	extract = ft_calloc(end - spot + 1, sizeof(char));
	while ((line[spot] != ' ' || in_or_out(line, spot) != 0)
		&& (line[spot] != '|' || valid_pipe(line, spot) != 1)
		&& line[spot])
	{
		if (line[spot] != 34 && line[spot] != 39)
		{
			extract[z] = line[spot];
			z++;
		}
		spot++;
	}
	return (extract);
}

char	*extract_redir(char *line, int spot)
{
	char	*to_test;
	int		z;

	spot++;
	while ((line[spot] == ' '
			|| line[spot] == '>'
			|| line[spot] == '<')
		&& line[spot])
		spot++;
	if (line[spot] == 34 || line[spot] == 39)
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

char	*extract_wipe(char *line, int z)
{
	char	*extract;
	int		end;

	end = z + 1;
	while ((line[end] != ' ' || in_or_out(line, end) != 0)
		&& valid_pipe(line, end) != 1
		&& line[end])
		end++;
	extract = ft_substr(line, z, end - z);
	clean_quotes(extract);
	while (line[end])
	{
		line[z] = line[end];
		z++;
		end++;
	}
	while (line[z])
	{
		line[z] = '\0';
		z++;
	}
	return (extract);
}

void	clean_quotes(char *extract)
{
	int		z;
	char	q_type;

	z = 0;
	while (extract[z])
	{
		if (extract[z] == 34 || extract[z] == 39)
		{
			q_type = extract[z];
			m_trim(extract, z, z);
			while (extract[z] != q_type && extract[z])
				z++;
			m_trim(extract, z, z);
		}
		else
			z++;
	}
}

char	*get_nxt_stuff(char *line)
{
	int		z;
	char	*extracted;

	z = 0;
	while (line[z] == ' ' && line[z])
		z++;
	extracted = extract_wipe(line, z);
	return (extracted);
}
