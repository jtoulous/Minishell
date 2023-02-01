#include "minishell.h"

void	syntax_check(t_data *data)
{
}

void	check_closed_quotes(t_data *data)
{
	int	z;
	
	z = 0;
	while (data->line[z])
	{
		if (data->line[z] == '"' || data->line[z] == ''')
			skip_out(data->line, &z);
		if (data->line[z] == '\0')
			error_quotes(data);
		else
			z++;
	}
}

void	check(t_data *data)
{
	int	nb_docs;
	
	check_closed_quotes(data);
	if (data->exec_stat == 1)
		syntax_check(data);
	nb_docs = nb_hdocs(data->line);
	if (nb_doc != 0)
		hdoc_scan(data, nb_docs);
}
