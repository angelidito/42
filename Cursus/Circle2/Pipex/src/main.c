/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 14:43:05 by angmarti          #+#    #+#             */
/*   Updated: 2023/03/09 18:38:36 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/pipex.h"

void	cmd_not_found(char *cmd)
{
	ft_printf("pipex: command not found: %s", cmd);
	exit(EXIT_FAILURE);
}
void	check_cmds(char *cmd1, char *cmd2, char **path)
{
	char	*file;

	file = get_cmd_file(cmd1, path);
	if (!file)
		cmd_not_found(cmd1);
	file = get_cmd_file(cmd2, path);
	if (!file)
		cmd_not_found(cmd2);
}

int	main(int argc, char **argv, char **envp)
{
	int		i;
	int		fd_infile;
	int		fd_outfile;
	pid_t	pid;
	char	**path;

	int pipe_fd[2]; // 0 - read ; 1 - write
	////
	////
	ft_printf("\n\033[7;34mExecuting: %s %s \"%s\" \"%s\" %s\033[0m\n\n",
				argv[0],
				argv[1],
				argv[2],
				argv[3],
				argv[4]);
	argc = 0;
	pipe(pipe_fd);         // assuming it doesn't fail
	path = get_path(envp); // assuming it's not NULL
	i = 0;
	check_cmds(argv[2], argv[3], path);
	pid = fork(); // assuming it's not -1
	if (pid == 0)
	{
		fd_infile = open(argv[1], O_RDONLY); // assuming it's not -1
		dup2(fd_infile, STDIN_FILENO);
		dup2(pipe_fd[1], STDOUT_FILENO);
		close(pipe_fd[0]);
		exec_cmd(argv[2], path, envp);
	}
	else
	{
		fd_outfile = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
		// asassuming it's not -1
		dup2(pipe_fd[0], STDIN_FILENO);
		dup2(fd_outfile, STDOUT_FILENO);
		close(pipe_fd[1]);
		exec_cmd(argv[3], path, envp);
	}
	return (0);
}
