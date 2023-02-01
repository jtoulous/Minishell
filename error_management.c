#include "minishell.h"
#include <unistd.h>

int	error_inredir(char *failed_redir)
{
	ft_putstr_fd(failed_redir, STDOUT_FILENO);
	ft_putstr_fd(": No such file or directory", STDOUT_FILENO);
	free (failed_redir);
	return (0);
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
