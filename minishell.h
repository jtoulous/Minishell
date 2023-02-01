#ifndef MINISHIAT_H
# define MINISHIAT_H

# define BUFFER_SIZE 1 

typedef struct s_list
{
	char		*entry;
	struct 	s_list	*nxt;
}		t_lst;

typedef struct pipex_data
{
	t_lst	*env;
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

//errorz
void	check(t_data *data);
void	check_closed_quotes(t_data *data);
int	error_inredir(char *failed_redir);
void	error_quotes(t_data *data);
void	error_path(char **argz, char *cmd);

//extract
char	*extract_redir(char *line, int spot);

//toolbox
void	skip_out(char *line, int *z);//z++, until out of closing quote or end of line
int	in_or_out(char *line, int index);
int	check_hdoc_usage(char *line, int z, int end);

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
int	valid_inredir(char *line, int spot);
int	the_last_inredir(char *line, int spot);

//outredir
void	check_outredir(t_data *data, int end);
void	set_up_outredir(t_data *data, int spot);

//trimage

//here_doc
void	hdoc_scan(t_data *data, int nb_docs);
void	fake_prep_hdoc(char *lim);
void	prep_hdoc(t_data *data, int z);
void	replace_hdoc(char *line, char *file, int spot);
void	get_doc_argz(int fd, char *lim);

/*==============================================================*/
			//NOT DONE YET
/*=============================================================*/

void	initialize_data(t_data *data, char **envp);
void	free_and_close_all(t_data *data, int opt);//si opt == 1, touche pas a env
void	heredoc_stat(t_data *data);//stack all in a tmp file, and replace "HEREDOC LIMITEUR ..." with "< heredoc.txt" in the line
void	syntax_check(t_data *data);
void	clean_dat_biach(char *line, int end)
void	trim_redir(char *line, int spot);
char	*extract_cmd(char *line);
void	pipes_prep(int **pipes, int nb_cmdz);
int	nb_cmd(char *line);
void	clean_dat_biach(char *line, int end);
int	end_of_cmd(char *line, int spot);// from u r starting point(spot) find the ending of the cmd
void	malloc_dat_shiat(t_data *data, int end);//malloc for **argz
void	path_finder(t_data *data, char *cmd);//path, access, tralala
int	count_leftovers(char *line);//count le nombre d'option restant
void	get_next_opt(char *argz, char *line);//get nxt word from line to put in argz and wipe from line
void	trim_leftovers(char *line);//wipe all until next pipe(pipe included), or end of line
void	reset_data(t_data *data);
void	regular_multi(t_data *data, int z);
void	builtinz_multi(t_data *data, int z);
void	check_builtin(char *arg);
void	execbd(char *path, char **argz, char **env);
void	close_all(t_data *data);
int	nb_hdocs(char *line);
void	trim_hdoc(char *line, int z);

#endif
