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

int	set_up_inredir(char *file, t_data *data, int spot)//ICCCCCCCCCCCCCCCI
{
	data->infile = open(file, O_RDONLY);
	if (data->infile == -1)
		return (error_inredir(file));
	trim_redir(data->line, spot);
	free (file);
	return (1);
}

int	check_inredir(t_data *data, int end)//////iciiciciciicic
{
	int	z;
	char	*file;
	
	z = 0;
	while (z < end)
	{
		if (data->line[z] == '<' && valid_inredir(data->line, z) == 1)
		{
			file = extract_redir(data->line, z);
			if (the_last_inredir(line, spot) == 1)
				return (set_up_inredir(file, data->line, z) == 1)//open, store in data->infile
			else
			{			
				if (access(file, F_OK) != 0)
					return (error_inredir(file));
				free (file);
			}
		}
		z++;
	}
	return (1);
}
