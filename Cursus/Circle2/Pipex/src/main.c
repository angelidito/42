/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 17:22:16 by angmarti          #+#    #+#             */
/*   Updated: 2023/02/07 15:55:13 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/pipex.h"
#include <fcntl.h> /* Open function */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void	breakpoint(void)
{
	ft_printf("––––____BREAKPOINT____––––");
}

void	child(int *pipe_fd)
{
	char	buffer[512];
	pid_t	pid;

	pid = fork();
	close(pipe_fd[1]); /* cerramos el lado de escritura del pipe */
	while ((read(pipe_fd[0], buffer, 1)) > 0)
		write(1, buffer, 1);
	close(pipe_fd[0]);
	if (pid)
	{
		waitpid(0, NULL, 0);
		ft_printf("Termina el hijo.\n");
	}
	else
	{
		ft_printf("Termina el nieto.\n");
	}
}

void	parent(int *pipe_fd)
{
	char	buffer[512];

	close(pipe_fd[0]); /* cerramos el lado de lectura del pipe */
	ft_strlcpy(buffer, "Esto llega a traves de la tuberia\n", 35);
	write(pipe_fd[1], buffer, ft_strlen(buffer));
	close(pipe_fd[1]);
	waitpid(0, NULL, 0);
	ft_printf("Termina el padre.\n");
}

int	main(int argc, char const *argv[])
{
	int		i;
	char	*str;
	pid_t	pid;

	if (argc < 2)
	{
		fprintf(stderr, "Usage: %s file1 command1 command1 file2\n", argv[0]);
		// exit(EXIT_FAILURE);
	}
	ft_printf("Comienza el Programa.\n");
	int pipe_fd[2]; // 0 - read ; 1 - write
	str = "hola";
	i = 0;
	if (pipe(pipe_fd) == -1)
	{
		perror("Error while piping.");
		exit(EXIT_FAILURE);
	}
	// if ((pid = fork()) == 0)
	// {
	// 	child(pipe_fd);
	// }
	// else
	// {
	// 	parent(pipe_fd);
	// }
	char	*args[] = {"ls", "-l", NULL};
	execve("/bin/ls", args, NULL);
	perror("execve");
	exit(EXIT_FAILURE);
	return (0);
}
