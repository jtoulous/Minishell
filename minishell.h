#ifndef MINISHIAT_H
# define MINISHIAT_H

# define BUFFER_SIZE 1 

# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <linux/limits.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

typedef struct pipex_data
{
	t_list		*env;
	char		*line;
	char		**argz;
	int		**pipe;
	int		infile;
	int		outfile;
	int		prev_outfile;
	int		exec_stat;
}		t_data;
/*==================================================*/
			/*DONE*/
/*====================================================*/

//built_in
void	built_in(t_data *data);

//errorz
void	check(t_data *data);
void	check_closed_quotes(t_data *data);
int	error_inredir(char *failed_redir);
void	error_quotes(t_data *data);
void	error_path(char **argz, char *cmd);

//extract
char	*extract_redir(char *line, int spot);

//toolbox 1, 2, ...
void	skip_out(char *line, int *z);//z++, until out of closing quote or end of line
int	in_or_out(char *line, int index);
int	nb_cmd(char *line);
int	end_of_cmd(char *line, int spot);
void	initialize_data(t_data *data, char **envp);
void	reset_data(t_data *data);
void	pipes_prep(int **pipes, int nb_cmdz);
void	export_env(t_list *env, char **envp);

//parse
void	parse(t_data *data, int x);
void	prep_exec(t_data *data, int end);


//exec
void	exec(t_data *data, int z);
void	simple_exec(t_data *data);
void	multiple_exec(t_data *data, int z);
void	built_inz(t_data *data, int z);

//inredir
void	check_inredir(t_data *data, int end);
void	set_up_inredir(char *file, t_data *data, int spot);
int	the_last_inredir(char *line, int spot);

//outredir
void	check_outredir(t_data *data, int end);
void	set_up_outredir(t_data *data, int spot);

//trimage
void	trim_hdoc(char *line, int z);
void	trim_leftovers(char *line);//wipe all until next com
void	trim_redir(char *line, int spot);

//here_doc
void	hdoc_scan(t_data *data, int nb_docs);
void	fake_prep_hdoc(char *lim);
void	prep_hdoc(t_data *data, int z);
void	replace_hdoc(char *line, char *file, int spot);
void	get_doc_argz(int fd, char *lim);
void	unlinkz(char *new);
int	nb_hdocs(char *line);
int	check_if_used(char *line, int spot, int end);

//valid_check
int	valid_inredir(char *line, int spot);
int	valid_pipe(char *line, int spot);
int	valid_hd(char *line, int spot);
/*==============================================================*/
			//NOT DONE YET
/*=============================================================*/

void	free_and_close_all(t_data *data, int opt);//si opt == 1, touche pas a env
void	syntax_check(t_data *data);
void	clean_dat_biach(t_data *data, int end);
char	*extract_cmd(char *line);
void	malloc_dat_shiat(t_data *data, int end);//malloc for **argz
void	path_finder(t_data *data, char *cmd);//path, access, tralala
int	count_leftovers(char *line);//count le nombre d'option restant
void	get_next_opt(char *argz, char *line);//get nxt word from line to put in argz and wipe from line
void	regular_multi(t_data *data, int z);
void	builtinz_multi(t_data *data, int z);
void	check_builtin(char *arg);
void	execbd(char *path, char **argz, char **env);
void	close_all(t_data *data);
char	*env_search(t_list *env, char *var);

#endif
