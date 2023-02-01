#include "minishell.h"

void	skip_out(char *line, int *z)
{
	char	q_type;
	
	q_type = line[*z];
	*z++;
	while (line[*z] != q_type && line[*z])
		*z++;
}

int	in_or_out(char *line, int index)
{
	int	z;
	
	z = 0;
	while (z < index)
	{
		if (line[z] == '"' || line[z] == ''')
			skip_out(data->line, &z);
		z++;
	}
	if (z > index && line[z] == '"')
		return (1);
	else if (z > index && line[z] == ''')
		return (2);
	return (0);
}

void	pipes_prep(int **pipes, int nb_cmdz)
{
}

int	nb_cmd(char *line)
{
}

int	check_hdoc_usage(char *line, int z, int end)
{
	while (z < end)
	{
		if (line[z] == '<' && valid_inredir(line, z) == 1)
			return (0);
		z++;
	}
	return (1);
}

void	unlinkz(char *new)//
{
	static t_list	*unlinks;
	
	if (new)
	{
		add_lst()
	}
}

