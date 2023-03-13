/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 14:43:05 by angmarti          #+#    #+#             */
/*   Updated: 2023/03/13 18:05:03 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/pipex.h"

void	cmd_not_found(char *cmd)
{
	ft_printf("pipex: command not found: %s\n", cmd);
	exit(EXIT_FAILURE);
}

void	check_cmd(char *cmd, char **path)
{
	char	*file;

	file = get_cmd_file(cmd, path);
	if (!file)
		cmd_not_found(cmd);
}

void	check_errors(int argc, char **argv, char **envp, int *pipe_fd)
{
	int	i;

	i = 0;
	while (envp && envp[i] && ft_strncmp(envp[i], "PATH=", 5))
		i++;
	if (!envp || !envp[i])
	{
		ft_printf("\n\033[1;31mWrong environment vars.\n\n");
		exit(EXIT_FAILURE);
	}
	if (argc != 5)
	{
		ft_printf("\n\033[1;31mUsage: %s infile command1 command1 outfile\n\n",
					argv[0]);
		exit(EXIT_FAILURE);
	}
	if (pipe(pipe_fd) == -1)
	{
		perror("\033[1;31mError while piping.");
		exit(EXIT_FAILURE);
	}
}

void	child(char **argv, char **envp, char **path, int *pipe_fd)
{
	int	fd_infile;

	check_cmd(argv[2], path);
	fd_infile = open(argv[1], O_RDONLY); // assuming it's not -1
	if (fd_infile == -1)
	{
		ft_printf("\n\033[1;31mNot accessible input file.\n\n");
		exit(EXIT_FAILURE);
	}
	dup2(fd_infile, STDIN_FILENO);
	dup2(pipe_fd[1], STDOUT_FILENO);
	close(pipe_fd[0]);
	exec_cmd(argv[2], path, envp);
	exit(EXIT_FAILURE);
}
void	parent(char **argv, char **envp, char **path, int *pipe_fd)
{
	int	fd_outfile;

	check_cmd(argv[3], path);
	fd_outfile = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (fd_outfile == -1)
	{
		ft_printf("\n\033[1;31mNot accessible input file.\n\n");
		exit(EXIT_FAILURE);
	}
	dup2(pipe_fd[0], STDIN_FILENO);
	dup2(fd_outfile, STDOUT_FILENO);
	close(pipe_fd[1]);
	exec_cmd(argv[3], path, envp);
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv, char **envp)
{
	int		i;
	pid_t	pid;
	char	**path;

	int pipe_fd[2]; // 0 - read ; 1 - write
	////
	////
	check_errors(argc, argv, envp, pipe_fd);
	path = get_path(envp); // assuming it's not NULL
	i = 0;
	pid = fork();
	if (pid == -1)
	{
		perror("\033[1;31mError while forking.");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		child(argv, envp, path, pipe_fd);
	}
	else
	{
		parent(argv, envp, path, pipe_fd);
	}
	return (0);
}
