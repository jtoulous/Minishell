#include "minishell.h"

void	clean_dat_biach(char *line, int end)//clean the cmd being treated, replace varz($a, ...), check '\', check for $?, ...
{
}

void	prep_exec(t_data *data, int end)
{
	int	z;
	int	leftovers;
	char	*cmd;
	
	z = 1;
	malloc_dat_shiat(data, end);//**argz malloked
	cmd = extract_cmd(data->line);//+ wipe cmd form line
	if (check_if_built(cmd) != 1)
		path_finder(data, cmd);
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
	clean_dat_biach(data->line, end);
	check_inredir(data, end);//open in data->infile + trim
	check_outredir(data, end);//if multi out_redir create all(but close useless ones) save last one in data->outfile and trim them all away,
	prep_exec(data, end);
	trim_leftovers(data->line);//efface tout jusqu a la comm suivante
}
