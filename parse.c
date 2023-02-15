#include "minishell.h"

void	clean_dat_biach(t_data *data)//clean the cmd being treated, replace varz($a, ...), check '\', check for $?, ...
{
	int	z;
	int	end;
	
	z = 0;
	end = end_of_cmd(data->line, 0);
	while (z < end)
	{
		if (scan_varz(data, end, z) != 1)
			z++;
		end = end_of_cmd(data->line, 0);
	}
}


void	prep_exec(t_data *data, int end)
{
	int	z;
	int	leftovers;
	char	*cmd;
	
	z = 1;
	malloc_dat_shiat(data, end);//**argz malloked
	cmd = get_nxt_stuff(data->line);//+ wipe cmd form line
	path_finder(data, cmd);//check if the mofo already typed path in com
	if (data->argz == NULL)
		error_path(cmd);
	else
	{
		leftovers = count_leftovers(data->line, end_of_cmd(data->line, 0));
		while (z <= leftovers)
		{
			data->argz[z] =get_nxt_stuff(data->line);//and wipe it
			z++;
		}
		data->argz[z] = NULL;
	}
}

void	parse(t_data *data)
{
	int	end;
	
	end = end_of_cmd(data->line, 0);
	clean_dat_biach(data);
	if (check_inredir(data, end) != 1)//open in data->infile + trim
		return ;
	check_outredir(data, end);//if multi out_redir create all(but close useless ones) save last one in data->outfile and trim them all away,
	prep_exec(data, end);
}
