#include "minishell.h"

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

int	valid_pipe(char *line, int spot)
{
	if (line[spot] == '|' 
		&& in_or_out(line, spot) == 0)
		return (1);
	return (0);
}

int	valid_hd(char *line, int spot)
{
	if (line[spot] == '<' 
		&& line[spot + 1] == '<'
		&& in_or_out(line, spot) == 0)
		return (1);
	return (0);
}
