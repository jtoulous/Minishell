#include "minishell.h"

void	syntax_check(t_data *data)
{
}

/*void	test_to_open(t_data *data, int spot)
{
	int		fd;	
	char		*to_test;
	
	to_test = extract_redir(data->line, spot);
	fd = open(to_test, O_RDONLY);
	if (fd == -1)
		error_inredir(data, to_test);
	mega_close(fd, -1, -1, -1);
	if (the_last_inredir?(data->line, spot) != 1)//check si c la derniere redir, sinon tu la tege
		trim_redir(data->line, spot);
	free (to_test);
}*/

/*void	check_infiles(t_data *data, int end)
{
	int	z;
	
	z = 0;
	while (z < end)
	{
		if (data->line[z] == '<' 
			&& valid_inredir?(data->line, spot) == 1
			&& data->exec_stat == 1)
			test_to_open(data, z);//tema squi ya derriere la redir et test l open
		z++;
	}
}*/

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
	//if (data->exec_stat == 1)
	//	check_infiles(data);
}
