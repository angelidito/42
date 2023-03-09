/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 14:43:05 by angmarti          #+#    #+#             */
/*   Updated: 2023/03/09 17:57:12 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	ft_printf("\n\033[7;34mExecuting: %s %s \"%s\" \"%s\" %s\033[0m\n\n",
				argv[0],
				argv[1],
				argv[2],
				argv[3],
				argv[4]);
	int i;          ////
	int fd_infile;  ////
	int fd_outfile; ////
	int pipe_fd[2]; // 0 - read ; 1 - write
	// int std_fd_cpy[2]; // 0 - read ; 1 - write
	pid_t pid;   ////
	char **path; ////
	////
	argc = 0;
	pipe(pipe_fd);         // assuming it doesn't fail
	path = get_path(envp); // assuming it's not NULL
	i = 0;
	pid = fork(); // assuming it's not -1
	if (pid == 0) // child
	{
		fd_infile = open(argv[1], O_RDONLY); // assuming it's not -1
		dup2(fd_infile, STDIN_FILENO);
		dup2(pipe_fd[1], STDOUT_FILENO);
		close(pipe_fd[0]);
		exec_cmd(argv[2], path, envp);
	}
	else // parent
	{
		
		fd_outfile = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
		dup2(pipe_fd[0], STDIN_FILENO);
		dup2(fd_outfile, STDOUT_FILENO);
		// dup2(pipe_fd[0], STDIN_FILENO);
		// close(pipe_fd[0]);
		close(pipe_fd[1]);
		exec_cmd(argv[3], path, envp);
	}
	ft_printf("\nIl processo è finito.\n");
	ft_printf("\n\n\033[7;49;34mProcesso %d è finito.\033[0m\n\n", pid);
	return (0);
}
