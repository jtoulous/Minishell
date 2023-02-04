/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoichon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:31:53 by agoichon          #+#    #+#             */
/*   Updated: 2023/02/02 17:05:28 by agoichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define BUFFER_SIZE 1 

# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <linux/limits.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>

typedef struct pipex_data
{
	t_list		*env;
	char		*line;
	char		**argz;
	int		**pipes;
	int		infile;
	int		outfile;
	int		prev_outfile;
	int		exec_stat;
	int		nb_cmds;
}		t_data;

int	error_inredir(char *failed_redir);
void	error_quotes(t_data *data);
void	error_path(char **argz, char *cmd);
void	check_closed_quotes(t_data *data);
void	check(t_data *data);
void	exec(t_data *data, int z);
void	simple_exec(t_data *data);
void	first_multiple(t_data *data);
void	last_multiple(t_data *data, int z);
void	multiple_exec(t_data *data, int z);
char	*extract_from_quotes(char *line, int spot);
char	*extract_redir(char *line, int spot);
char	*extract_wipe_quotes(char *line, int z);
char	*extract_wipe(char *line, int z);
char	*get_nxt_stuff(char *line);
void	hdoc_scan(t_data *data, int nb_docs);
void	fake_prep_hdoc(char *lim);
void	prep_hdoc(t_data *data, int z);
void	replace_hdoc(char *line, char *file, int spot);
void	get_doc_argz(int fd, char *lim);
int	the_last_inredir(char *line, int spot);
int	set_up_inredir(char *file, t_data *data, int spot);
int	check_inredir(t_data *data, int end);
void	treat_command(t_data *data);
void	set_up_outredir(t_data *data, int spot);
void	check_outredir(t_data *data, int end);
void	clean_dat_biach(t_data *data, int end);
void	prep_exec(t_data *data, int end);
void	parse(t_data *data);
void	path_finder(t_data *data, char *cmd);
char	**path_lst(t_data *data);
void	malloc_dat_shiat(t_data *data, int end);
void	skip_arg(char *line, int *z, int end);
void	skip_redir(char *line, int *z, int end);
char	*env_search(t_list *env, char *var);
void	free_lst(t_list *lst);
void	close_pipes(int *pipes, int nb);
void	close_all(t_data *data);
void	free_and_close_all(t_data *data, int opt);
void	skip_out(char *line, int *z);
int	in_or_out(char *line, int index);
int	nb_cmd(char *line);
int	end_of_cmd(char *line, int spot);
char	**convert_env(t_list *env);
void	export_env(t_list *env, char **envp);
void	init_data(t_data *data, char **envp);
void	reset_data(t_data *data);
void	pipes_prep(int **pipes, int nb_cmdz);
int	count_leftovers(char *line, int end);
int	check_if_used(char *line, int spot, int end);
int	nb_hdocs(char *line);
void	unlinkz(char *new);
void	trim_redir(char *line, int spot);
void	trim_leftovers(char *line);
void	trim_hdoc(char *line, int spot);
int	valid_inredir(char *line, int spot);
int	valid_pipe(char *line, int spot);
int	valid_hd(char *line, int spot);
void	replace_var(char *line, int spot, int end_var, char *var_val);
void	sub_var(t_data *data, int spot, int end_var, int end_com);
void	scan_varz(t_data *data, int end, int spot);
char	*hdoc_limit(char *line, int spot);

#endif
