/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 17:22:16 by angmarti          #+#    #+#             */
/*   Updated: 2023/02/06 19:48:29 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/pipex.h"

void	breakpoint(void)
{
	ft_printf("––––____BREAKPOINT____––––");
}

void	child(int *pipe_fd)
{
	ft_printf("Child ft\n");
	close(pipe_fd[0]);
	breakpoint();
	if (write(pipe_fd[1], "MEMENTO MORI", 12) == -1)
	{
		ft_printf("Error while writing at fd %d.\n", pipe_fd[1]);
		exit(1);
	}
	breakpoint();
		ft_printf("\n");
	close(pipe_fd[1]);
}
void	parent(int *pipe_fd)
{
	char	buff[100];

	ft_printf("parent ft\n");
	wait(NULL);
	close(pipe_fd[1]);
	if (read(pipe_fd[0], buff, 12) == -1)
	{
		ft_printf("Error while writing at fd %d.\n", pipe_fd[1]);
		exit(1);
	}
	close(pipe_fd[0]);
	ft_printf("-_  %s\n", buff);
}

int	main(void)
{
	int		id;
	int		i;
	char	*str;

	int pipe_fd[2]; // 0 - read ; 1 - write
	str = "hola";
	i = 0;
	id = fork();
	if (pipe(pipe_fd) == -1)
	{
		perror("Error while piping.");
		exit(1);
	}
	wait(NULL);
	// i = 69;
	// close(pipe_fd[0]);
	// write(pipe_fd[1], str, sizeof(char) * ft_strlen(str));
	// close(pipe_fd[1]);
	// read(pipe_fd[0], buff, 12);
	// close(pipe_fd[0]);
	// ft_printf("%s\n", buff);
	if (id == 0)
	{
		child(pipe_fd);
	}
	else
	{
		parent(pipe_fd);
	}
	return (0);
}
