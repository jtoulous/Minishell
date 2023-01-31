#include "minishell.h"

void	error_inredir(t_data *data, char *failed_redir)
{
	data->exec_stat = 0;
	ft_putstr_fd(failed_redir, STDOUT);
	ft_putstr_fd(": No such file or directory", STDOUT);
}

void	error_quotes(t_data *data)
{
	data->exec_stat = 0;
	ft_putstr_fd("va niquer ta race a pas fermer tes putains de quotes", STDOUT);
}

void	error_path(char **argz, char *cmd)
{
	free (argz);
	argz = NULL;
	ft_putstr_fd(cmd, 1);
	ft_putstr_fd(": command not found", 1);
	free (cmd);
}
