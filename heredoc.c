/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoichon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:35:22 by agoichon          #+#    #+#             */
/*   Updated: 2023/02/06 10:28:59 by agoichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <readline/readline.h>

void	get_doc_argz(int fd, char *lim)
{
	char	*buf;

	while (1)
	{
		ft_putstr_fd(">", 1);
		buf = get_next_line(1);
		if (ft_strncmp(buf, lim, ft_strlen(lim)) == 0)
		{
			mega_free(buf, lim, NULL, NULL);
			return ;
		}		
		write (fd, buf, ft_strlen(buf));
		free (buf);
	}
}

void	replace_hdoc(char *line, char *file, int spot)
{
	char	*ante;
	char	*pre;
	int	end_hd;
	int	end_line;
	
	end_hd = spot;
	while (line[end_hd] == '<' && line[end_hd] == ' ' && line[end_hd])
		end_hd++;
	while ((line[end_hd] != ' ' || in_or_out(line, end_hd) != 0)
		&& line[end_hd])
		end_hd++;
	end_line = end_hd;
	while (line[end_line])
		end_line++;
	ante = ft_substr(line, 0, spot + 1);
	pre = ft_substr(line, end_hd, end_line - end_hd);
	free (line);
	line = triple_strjoin(ante, file, pre);
	mega_free(ante, pre, NULL, NULL);
}

void	prep_hdoc(t_data *data, int z)
{
	char	*file;
	char	*fileno;
	int	fd;
	
	fileno = ft_itoa(z);
	file = ft_strjoin(".heredoc", fileno);
	free (fileno);
	fd = open(file, O_WRONLY | O_RDONLY | O_CREAT, 0777);
	get_doc_argz(fd, hdoc_limit(data->line, z));
	replace_hdoc(data->line, file, z);
	unlinkz(file);
	close (fd);
}

void	fake_prep_hdoc(char *lim)
{
	char	*buf;

	while (1)
	{
		ft_putstr_fd(">", 1);
		buf = get_next_line(1);
		if (ft_strncmp(buf, lim, ft_strlen(lim)) == 0)
		{
			mega_free(buf, lim, NULL, NULL);
			return ;
		}
	}
}

void	hdoc_scan(t_data *data)
{
	int	z;
	
	z = 0;
	while (data->line[z])
	{
		if (data->line[z] == '<' 
			&& valid_hd(data->line, z) == 1)
		{
			if (check_if_used(data->line, z, end_of_cmd(data->line, z)) == 1)//check si ta pas une autre redir dans la meme cmd  
				prep_hdoc(data, z);
			else
			{
				fake_prep_hdoc(hdoc_limit(data->line, z));
				trim_hdoc(data->line, z);
			}
		}
		z++;
	}
}
