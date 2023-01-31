#include "minishell.h"

char	*extract_redir(char *line, int spot)
{
	char	*to_test;
	int	z;
	
	spot++;
	while (line[spot] == ' ' && line[spot])
		spot++;
	if (line[spot] == ''' || line[spot] == '"')
		to_test = extract_from_quotes(line, spot);
	else	
	{
		z = spot;
		while (line[z] != ' '
			&& (line[z] != '|' || valid_pipe?(line, z) != 1) 
			&& line[z])
			z++;
		to_test = ft_substr(line, spot, z - spot);
	}
	return (to_test);
}

char	*extract_cmd(char *line)//return the first word u meet
{
	
}
