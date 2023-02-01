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

int	set_up_inredir(t_data *data, int spot)//ICCCCCCCCCCCCCCCI
{
	char	*file;
	
	file = extract_redir(data->line, spot);
	data->infile = open(file, O_RDONLY);
	if (data->infile == -1)
	{	
		error_inredir(file);
		return (0);
	}
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
			if (the_last_inredir(line, spot) == 1
				&& set_up_inredir(data, z) == 1)
				return (1)//open, store in data->infile
			else
			{
				file = extract_redir(data->line, z);			
				if (access(failed, F_OK) != 0)
				{
					error_inredir(file);
					return (0);
				}	
				free (file);
			}
		}
		z++;
	}
	return (1);
}
