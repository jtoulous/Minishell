#include "minishell.h"

void	skip_redir(char *line, int *z, int end)
{
	*z++;
	while (line[*z] == ' ' && *z < end)
		*z++;
	while ((line[*z] != ' ' || in_or_out(line, *z) != 0)
		&& *z < end)
		*z++;
}

void	skip_arg(char *line, int *z, int end)
{
	while (*z < end)
	{
		if (line[*z] == ' ' && in_or_out(line, *z) == 0)
			return;
		else
			*z++;	
	}
}

void	malloc_dat_shiat(t_data *data, int end)
{
	int	m_size;
	int	z;
	
	m_size = 0;
	z = 0;
	while (z < end)
	{
		if ((data->line[z] == '<' || data->line[z] == '>')
			&& in_or_out(data->line, z) != 0)
			skip_redir(data->line, &z, end);
		else if (data->line[z] != " ")
		{
			skip_arg(data->line, &z, end);
			m_size++;
		}
		else
			z++;
	}
	data->argz = ft_calloc(m_size + 2 , sizeof(char *));
}
