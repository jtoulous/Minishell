#include "minishell.h"

void	clean_dat_biach(t_data *data, int end)//clean the cmd being treated, replace varz($a, ...), check '\', check for $?, ...
{
	int	z;
	
	z = 0;
	while (z < end)
	{
		scan_varz(data, end, z);
		z++;
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
	if (!data->argz[0])
	{
		error_path(data->argz, cmd);
		free (cmd);
	}	
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
	clean_dat_biach(data, end);
	if (check_inredir(data, end) != 1)//open in data->infile + trim
		return ;
	check_outredir(data, end);//if multi out_redir create all(but close useless ones) save last one in data->outfile and trim them all away,
	prep_exec(data, end);
}
