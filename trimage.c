#include "minishell.h"

void	trim_redir(char *line, int spot)
{
	int	z;
	
	z = spot + 1;
	while (line[z] == ' ' && line[z])
		z++;
	while (line[z] != ' ' && line[z])
		z++;
	while (line[z])
	{
		line[spot] = line[z];
		spot++;
		z++;
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
}

void	trim_hdoc(char *line, int spot)
{
	int	z;
	
	z = spot;
	while ((line[z] == '<' || line[z] == ' ')
		&& line[z])
		z++;
	while (line[z] != ' ' && line[z])
		z++;
	while (line[z])
	{
		line[spot] = line[z];
		spot++;
		z++; 
	}
}
