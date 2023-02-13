/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoichon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:31:53 by agoichon          #+#    #+#             */
/*   Updated: 2023/02/10 13:08:07 by agoichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

//# define BUFFER_SIZE 1 

/*Colors*/
/*---------------------------------------------------------------------*/
# define BLACK "\e[0;30m"
# define GREY "\e[1;30m"
# define DARKRED "\e[0;31m"
# define PINK "\e[1;31m"
# define DARKGREEN "\e[0;32m"
# define LIGHTGREEN "\e[1;32m"
# define ORANGE "\e[0;33m"
# define YELLOW "\e[1;33m" 
# define DARKBLUE "\e[0;34m"
# define LIGHTBLUE "\e[1;34m"
# define DARKPURPLE "\e[0;35m"
# define LIGHTPURPLE "\e[1;35m"
# define DARKCYAN "\e[0;36m"
# define LIGHTCYAN "\e[1;36"
# define LIGHTGREY "\e[0;37m"
# define WHITE "\e[1;37m"
# define NEUTRAL "\e[0;m"
/*--------------------------------------------------------------------*/

# include "libft/libft.h"
# include <linux/limits.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <signal.h>
/*readline*/
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>

//extern int	err_code;

typedef struct pipex_data
{
	t_list	*env;
	char	*line;
	char	**argz;
	int		**pipes;
	int		infile;
	int		outfile;
	int		prev_outfile;
	int		exec_stat;
	int		nb_cmds;
}		t_data;

//minishiat.c
void	treat_command(t_data *data);

//parse.c
void	clean_dat_biach(t_data *data);
void	prep_exec(t_data *data, int end);
void	parse(t_data *data);

//error_management.c
int		error_inredir(char *failed_redir);
void	error_quotes(t_data *data);
void	error_path(char *cmd);

//checks.c
void	check_closed_quotes(t_data *data);
void	check(t_data *data);
//void	syntax_check(t_data *data);
int		check_if_fork(t_data *data);
int		check_if_builtin(char *cmd);

//exec.c
void	exec(t_data *data, int z);
void	simple_exec(t_data *data);
void	first_multiple(t_data *data);
void	last_multiple(t_data *data, int z);
void	multiple_exec(t_data *data, int z);

//extract.c
char	*extract_from_quotes(char *line, int spot);
char	*extract_redir(char *line, int spot);
char	*extract_wipe_quotes(char *line, int z);
char	*extract_wipe(char *line, int z);
char	*get_nxt_stuff(char *line);

//heredoc.c
void	hdoc_scan(t_data *data);
void	fake_prep_hdoc(char *lim);
void	prep_hdoc(t_data *data, int z);
void	replace_hdoc(char *line, char *file, int spot);
void	get_doc_argz(int fd, char *lim);

//inredir.c
int		the_last_inredir(char *line, int spot);
int		set_up_inredir(char *file, t_data *data, int spot);
int		check_inredir(t_data *data, int end);
void	treat_command(t_data *data);

//outredir.c
void	set_up_outredir(t_data *data, int spot);
void	check_outredir(t_data *data, int end);

//prep_exec.c
void	path_finder(t_data *data, char *cmd);
char	**path_lst(t_data *data);
void	malloc_dat_shiat(t_data *data, int end);
void	skip_arg(char *line, int *z, int end);
void	skip_redir(char *line, int *z, int end);

//toolbox3.c
char	*env_search(t_list *env, char *var);
void	free_lst(t_list *lst);
void	close_pipes(int **pipes, int nb);
void	close_all(t_data *data);
void	free_and_close_all(t_data *data, int opt);

//toolbox1.c
void	skip_out(char *line, int *z);
int		in_or_out(char *line, int index);
int		nb_cmd(char *line);
int		end_of_cmd(char *line, int spot);
char	**convert_env(t_list *env);

//toolbox2.c
void	export_env(t_list **env, char **envp);
void	init_data(t_data *data, char **envp);
void	reset_data(t_data *data);
void	pipes_prep(t_data *data, int nb_cmdz);
int		count_leftovers(char *line, int end);

//toolbox_hd.c
int		check_if_used(char *line, int spot, int end);
int		nb_hdocs(char *line);
void	unlinkz(char *new);
int		lim_size(char *line, int spot);
void	skip_n_copy_quote(char *line, char *fnl, int *spot, int *z);
char	*hdoc_limit(char *line, int spot);

//trimage.c
void	trim_redir(char *line, int spot);
void	trim_leftovers(char *line);
void	trim_hdoc(char *line, int spot);

//valid_check.c
int		valid_inredir(char *line, int spot);
int		valid_pipe(char *line, int spot);
int		valid_hd(char *line, int spot);

//varz.c
void	replace_var(char *line, int spot, int end_var, char *var_val);
void	sub_var(t_data *data, int spot, int end_var);
void	scan_varz(t_data *data, int end, int spot);

//builtin.c
int		built_in(t_data *data);
void	built_in_unset(t_data *data);
void	built_in_export(t_data *data);;

//echo.c
void	built_in_echo(t_data *data);

//path.c
void	built_in_cd(t_data *data);
void	built_in_pwd(t_data *data);
void	built_in_env(t_data *data);

//exit.c
int		built_in_exit(t_data *data);

//signal.c
void	handle_sigint(int sig);
void	handle_sigquit(int sig);

#endif
