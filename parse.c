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

void	prep_exec(t_data *data, int end)//ICICICICICIIC
{
	int	z;
	int	leftovers;
	char	*cmd;
	
	z = 1;
	malloc_dat_shiat(data, end);//**argz malloked
	cmd = extract_cmd(data->line);//+ wipe cmd form line
	if (check_if_built(cmd) != 1)
		path_finder(data, cmd);//check if the mofo already typed path in com
	if (!data->argz[0])
		error_path(data->argz, cmd);
	else
	{
		leftovers = count_leftovers(data->line);
		while (z <= leftovers)
		{
			get_next_opt(data->argz[z], data->line);//and wipe it
			z++;
		}
		data->argz[z] = NULL;
	}
	free (cmd);
}

void	parse(t_data *data)//efface la cmd qui vient d etre traiter
{
	int	end;
	
	end = end_of_cmd(data->line, 0);
	clean_dat_biach(data, end);
	if (check_inredir(data, end) != 1)//open in data->infile + trim
		return ;
	check_outredir(data, end);//if multi out_redir create all(but close useless ones) save last one in data->outfile and trim them all away,
	prep_exec(data, end);
}
