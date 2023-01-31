#include "minishell.h"

int	the_last_inredir(char *line, int spot)
{
	int	end;
	
	end = end_of_cmd(line, spot);
	while (spot < end)
	{
		if (line[spot] == '<' && valid_inredir(line, spot) == 0)
			return (0);
		z++;
	}
	return (1);
}

int	valid_inredir(char *line, int spot)
{
	int	end;
	
	end = end_of_cmd(line, spot);
	if (in_or_out(line, spot) != 0)
		return (0);
	while (spot < end)
	{
		if (line[spot] != ' ')
			return (1);
		spot++;
	}
	return (0);
}

void	set_up_inredir(t_data *data, int spot)//ICCCCCCCCCCCCCCCI
{
	char	*file;
	
	file = extract_redir(data->line, spot);
	data->infile = open(file, O_RDONLY);
	if (data->infile == -1)
		error_msg("");
	trim_redir(data->line, spot);
	free (file);
}

void	check_inredir(t_data *data, int end)//////iciiciciciicic
{
	int	z;
	
	z = 0;
	while (z < end)
	{
		if (data->line[z] == '<' && valid_inredir(data->line, z) == 1)
		{
			if (the_last_inredir(line, spot) == 1)
				set_up_inredir(data, z);//open, store in data->infile
			else
				if (access(extract_redir(data->line, z), F_OK) == 0)
			return ;
		}
		z++;
	}
}
