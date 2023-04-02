/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_n_cmds.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 14:43:05 by angmarti          #+#    #+#             */
/*   Updated: 2023/04/02 18:20:19 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/pipex.h"

/**
 * It opens the input file and returns the file descriptor
 * 
 * @param infile the name of the file to open
 * @param flags O_RDONLY, O_RDWR
 * 
 * @return The file descriptor of the input file.
 */
int	open_in(char *infile, int flags)
{
	int	fd_infile;

	fd_infile = open(infile, flags);
	if (fd_infile == -1)
	{
		ft_printf("\n\033[1;31mNot accessible input file.\n\n");
		exit(EXIT_FAILURE);
	}
	return (fd_infile);
}

/**
 * It opens the output file and returns the file descriptor
 * 
 * @param outfile the name of the file to open
 * @param flags O_WRONLY, O_CREAT, O_TRUNC, O_APPEND
 * @param mode The mode is specified in octal, and is the same as the mode 
 * argument to open(2).
 * 
 * @return The file descriptor of the output file.
 */
int	open_out(char *outfile, int flags, int mode)
{
	int	fd_outfile;

	fd_outfile = open(outfile, flags, mode);
	if (fd_outfile == -1)
	{
		ft_printf("\n\033[1;31mNot accessible output file.\n\n");
		exit(EXIT_FAILURE);
	}
	return (fd_outfile);
}

void	n_child(t_vars *vars, int *pipe_fd)
{
	int	fd_infile;

	check_cmd(vars->cmds[0], vars->path);
	fd_infile = open_in(vars->infile, O_RDONLY);
	dup2(fd_infile, STDIN_FILENO);
	dup2(pipe_fd[1], STDOUT_FILENO);
	close(pipe_fd[0]);
	exec_cmd(vars->cmds[0], vars->path, vars->envp);
}

void	n_parent(t_vars *vars, int *pipe_fd, int fd_out, int cmd)
{
	check_cmd(vars->cmds[cmd], vars->path);
	dup2(pipe_fd[0], STDIN_FILENO);
	dup2(fd_out, STDOUT_FILENO);
	close(pipe_fd[1]);
	exec_cmd(vars->cmds[cmd], vars->path, vars->envp);
}

void	case_n_cmds(t_vars *vars, int *prev_fd, int n_comands)
{
	int		pipe_fd[2];
	pid_t	pid;
	int		fd_outfile;

	if (n_comands == 1)
	{
		n_child(vars, prev_fd);
		return ;
	}
	if (pipe(pipe_fd) == -1)
		my_perror("\033[1;31mPipe error: ");
	pid = fork();
	if (pid == -1)
		my_perror("\033[1;31mError while forking.");
	if (!prev_fd)
		fd_outfile = open_out(vars->outfile, O_CREAT | O_RDWR | O_TRUNC, 0644);
	else
		fd_outfile = prev_fd[1];
	if (pid == 0)
		case_n_cmds(vars, pipe_fd, n_comands - 1);
	else
		n_parent(vars, pipe_fd, fd_outfile, n_comands - 1);
}
