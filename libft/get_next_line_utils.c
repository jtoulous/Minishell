/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoulous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 18:11:15 by jtoulous          #+#    #+#             */
/*   Updated: 2022/11/03 18:11:20 by jtoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*read_the_fkin_file(int fd, char *buf, char *line)
{
	int	ret;

	while (newline_check(buf) != 1)
	{	
		ret = read(fd, buf, BUFFER_SIZE);
		buf[ret] = '\0';
		line = copy(buf, line, 0, 0);
		if (!line)
			return (NULL);
		if (ret <= 0 && line[0] == '\0')
		{
			free (line);
			return (NULL);
		}
		if (ret < BUFFER_SIZE)
			return (line);
	}
	return (line);
}

char	*clean(char *buf, size_t z, size_t y)
{
	while (buf[z] && buf[z] != '\n')
		z++;
	if (buf[z] == '\n')
	{
		z++;
		while (buf[z])
		{
			buf[y] = buf[z];
			z++;
			y++;
		}
		buf[y] = '\0';
	}
	else
		buf[0] = '\0';
	return (buf);
}
