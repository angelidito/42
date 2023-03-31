/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_n_cmds.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 14:43:05 by angmarti          #+#    #+#             */
/*   Updated: 2023/03/29 19:17:10 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/pipex.h"

void	_child(t_vars *vars, int *pipe_fd, int std_fd[], int n)
{
	int	fd_infile;

	check_cmd(vars->cmds[n], vars->path);
	fd_infile = open(vars->infile, O_RDONLY);
	if (fd_infile == -1)
	{
		ft_printf("\n\033[1;31mNot accessible input file.\n\n");
		exit(EXIT_FAILURE);
	}
	dup2(fd_infile, std_fd[0]);
	dup2(pipe_fd[1], std_fd[1]);
	close(pipe_fd[0]);
	exec_cmd(vars->cmds[n], vars->path, vars->envp);
}

void	_parent(t_vars *vars, int *pipe_fd, int std_fd[], int n)
{
	int	fd_outfile;

	check_cmd(vars->cmds[n], vars->path);
	fd_outfile = open(vars->outfile, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (fd_outfile == -1)
	{
		ft_printf("\n\033[1;31mNot accessible output file.\n\n");
		exit(EXIT_FAILURE);
	}
	dup2(pipe_fd[0], std_fd[0]);
	dup2(fd_outfile, std_fd[1]);
	close(pipe_fd[1]);
	exec_cmd(vars->cmds[n], vars->path, vars->envp);
}

// void case_n_cmds(t_vars *vars)
// {
// 	int pipe_fd[2];
// 	pid_t pid;

// 	if (pipe(pipe_fd) == -1)
// 	{
// 		perror("\033[1;31mPipe error: ");
// 		exit(EXIT_FAILURE);
// 	}
// 	pid = fork();
// 	if (pid == -1)
// 	{
// 		perror("\033[1;31mError while forking.");
// 		exit(EXIT_FAILURE);
// 	}
// 	if (pid == 0)
// 		_child(vars, pipe_fd);
// 	else
// 		_parent(vars, pipe_fd);
// }

void	case_n_cmds(t_vars *vars, int std_fd[], int n)
{
	int		pipe_fd[2];
	pid_t	pid;

	if (n == 0)
		_child(vars, pipe_fd, std_fd, 0);
	if (pipe(pipe_fd) == -1)
	{
		perror("\033[1;31mPipe error: ");
		exit(EXIT_FAILURE);
	}
	pid = fork();
	if (pid == -1)
	{
		perror("\033[1;31mError while forking.");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
		case_n_cmds(vars, pipe_fd, n - 1);
	else
		_parent(vars, pipe_fd, std_fd, n - 1);
}
