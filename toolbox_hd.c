#include "minishell.h"

int	check_if_used(char *line, int spot, int end)
{
	while (spot < end)
	{
		if (line[spot] == '<' 
			&& (valid_inredir(line, spot) == 1)
			|| valid_hd(line, spot) == 1)
			return (0);
	}
	return (1);
}

int	nb_hdocs(char *line)
{
	int	count;
	int	z;
	
	z = 0;
	count = 0;
	while (line[z])
	{
		if (line[z] == '<' && valid_hd(line, z) == 1)
			count++;
		z++;
	}
	return (count);
}

void	unlinkz(char *new)//
{
	static t_list	*unlinks;
	t_list		*tmp;
	
	if (new)
	{
		ft_lstadd_back(&unlinks, ft_lstnew(new));
		return ;
	}
	tmp = unlinks;
	while (tmp->next != NULL)
	{
		unlink(tmp->entry);
		tmp = tmp->next;
	}
	unlink(tmp->entry);
	free_lst(unlinks);
}
