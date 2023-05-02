/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case2cmds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 14:43:05 by angmarti          #+#    #+#             */
/*   Updated: 2023/04/09 17:46:45 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/pipex.h"

void	child(t_vars *vars, int *pipe_fd)
{
	int	fd_infile;

	check_cmd(vars->cmds[0], vars->path);
	fd_infile = open(vars->infile, O_RDONLY);
	if (fd_infile == -1)
	{
		ft_printf("\n\033[1;31mNot accessible input file.\n\n");
		exit(EXIT_FAILURE);
	}
	dup2(fd_infile, STDIN_FILENO);
	dup2(pipe_fd[1], STDOUT_FILENO);
	// ft_putstr_fd("\033[0m––––____checkpoint____––––\n\033[0m", STDOUT_FILENO);
	close(pipe_fd[0]);
	exec_cmd(vars->cmds[0], vars->path, vars->envp);
}

void	parent(t_vars *vars, int *pipe_fd)
{
	int	fd_outfile;

	check_cmd(vars->cmds[1], vars->path);
	fd_outfile = open(vars->outfile, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (fd_outfile == -1)
	{
		ft_printf("\n\033[1;31mNot accessible output file.\n\n");
		exit(EXIT_FAILURE);
	}
	dup2(pipe_fd[0], STDIN_FILENO);
	dup2(fd_outfile, STDOUT_FILENO);
	close(pipe_fd[1]);
	exec_cmd(vars->cmds[1], vars->path, vars->envp);
}

void	case2cmds(t_vars *vars)
{
	int		pipe_fd[2];
	pid_t	pid;

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
		child(vars, pipe_fd);
	else
		parent(vars, pipe_fd);
}
