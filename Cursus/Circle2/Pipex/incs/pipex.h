/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:44:24 by angmarti          #+#    #+#             */
/*   Updated: 2023/05/23 17:18:35 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# define _GNU_SOURCE
# include "../libs/mylibft/incs/libft.h"
# include "colors.h"
# include "pipex_structs.h"
# include <fcntl.h> /* Open function */
# include <time.h>

# ifndef TEMP_HERE_DOC
#  define TEMP_HERE_DOC "/tmp/pipex_here_doc"
# endif

// BACKSLASHES

void	remove_escapes(t_list **lst);
char	*str_remove_escapes(char *str);

//	CASE TWO CMDS (NO BONUS)

void	case_2_cmds(t_vars *vars);

//	CASE _N_ CMDS (BONUS)

void	case_n_cmds(t_vars *vars, int *prev_fd, int n_comands);

//	CHECKING_SETTING (BONUS)

void	check_cmd(char *cmd, char **path);
void	check_errors(int argc, char **argv, char **envp, t_vars *vars);
void	set_vars(int argc, char **argv, char **envp, t_vars *vars);

//	CHECKING_SETTING (NO BONUS)

void	check_cmd(char *cmd, char **path);
void	check_errors_no_bonus(int argc, char **argv, char **envp);
void	set_vars_no_bonus(int argc, char **argv, char **envp, t_vars *vars);

//	ERRORS

void	my_perror(char *s);
void	print_stderr(char *str);
void	pf_exit(char *s, int fd);

//	GET COMAND ARGUMENTS

char	**get_cmd_args(char const *cmd);

//	GETTING_EXECUTING

int		chararrsize(char **chararr);
void	exec_cmd(char *cmd, char **path, char *envp[]);
char	*get_cmd_file(char *cmd, char **path_var);
char	**get_path(char *envp[]);

// HERE_DOC

void	heredoc(char *limiter, int n_comands);

//	FT_FUNCTIONS

void	ft_freechararr(char **chararr);
char	*ft_strjoin_n_free(const char *s1, const char *s2);
char	*ft_strjoin_n_free_op(const char *s1, const char *s2, int f1, int f2);

// FT_SPLIT_NOT_ESCAPED

char	**ft_split_not_escaped(char const *s, char c);

#endif
