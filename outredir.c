#include "minishell.h"

void	set_up_outredir(t_data *data, int spot)
{
	char	*file;
	
	file = extract_redir(data->line, spot);
	if (data->line[spot + 1] == '>')
		data->outfile = open(file, O_WRONLY | O_CREAT | O_APPEND, 0777);
	else
		data->outfile = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	trim_redir(data->line, spot);
}

void	check_outredir(t_data *data, int end)
{
	int	z;
	
	z = 0;
	while (z < end)
	{
		if (data->line[z] == '>' && in_or_out(data->line, z) == 0)
		{	
			if (data->outfile != -1)
				close (data->outfile);
			set_up_outredir(data, z);
		}
		z++;
	}
}
