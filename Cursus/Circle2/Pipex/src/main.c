/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 17:22:16 by angmarti          #+#    #+#             */
/*   Updated: 2023/02/09 18:39:52 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/pipex.h"

void	breakpoint(void)
{
	ft_printf("\033[0m––––____BREAKPOINT____––––\n\033[0m");
}

/**
 * It runs the command `leaks -q fdf` and prints the result in yellow.
 * Usage: atexit(leaks);
 */
void	leaks(void)
{
	ft_printf("\033[0m\n\n\033[7;49;33m");
	system("leaks -q pipex");
	ft_printf("\033[0m");
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

void	set_path(char **path)
{
	path[0] = "/usr/local/bin";
	path[1] = "/usr/bin";
	path[2] = "/bin";
	path[3] = "/usr/sbin";
	path[4] = "/sbin";
	path[5] = "/usr/local/munki";
	path[6] = NULL;
}

char	*get_cmd_path(char const *cmd)
{
	char	*path[7];
	int		i;
	char	**words;
	char	*result;
	char	*aux;

	set_path(path);
	i = -1;
	words = ft_split(cmd, ' ');
	while (++i < 6)
	{
		aux = ft_strjoin("/", words[0]);
		result = ft_strjoin(path[i], aux);
		free(aux);
		if (access(result, X_OK) == 0)
			break ;
		free(result);
	}
	i = -1;
	ft_freechararr(words);
	return (result);
}

char	**exec_cmd(char const *cmd, char const *arg)
{
	char	**temp_arg;
	int		i;
	char	**argv;

	temp_arg = ft_split(cmd, ' ');
	i = 0;
	while (temp_arg[i])
		i++;
	argv = ft_calloc(i + 2, sizeof(char *));
	i = -1;
	while (temp_arg[++i])
		argv[i] = temp_arg[i];
	argv[i] = ft_strtrim(arg, " \n\t\r\f\v");
	free(temp_arg);
	i = -1;
	while (argv[++i])
		ft_printf("%s ", argv[i]);
	ft_printf("\n", argv[i]);
	execve(get_cmd_path(cmd), argv, NULL);
	return (argv);
}

// int main(int argc, char const *argv[])
int	main(void)
{
	int			argc;
	char const	*argv[6];
	pid_t		pid;
	char		*str;
	int			i;

	int pipe_fd[2]; // 0 - read ; 1 - write
	int std_fd[2];  // 0 - STDIN_FILENO ; 1 - STDOUT_FILENO
	//
	argc = 5;
	argv[0] = "./pipezzz";
	argv[1] = "   infile  ";
	argv[2] = "  cat -e -n  ";
	argv[3] = "  wc  -w   ";
	argv[4] = "  outfile ";
	argv[5] = NULL;
	if (argc != 5)
	{
		ft_printf("\n\033[1;31mUsage: %s infile command1 command1 outfile\n\n",
					argv[0]);
		exit(EXIT_FAILURE);
	}
	ft_printf("\033[7;49;34mComienza el Programa.\033[0m\n\n");
	if (pipe(pipe_fd) == -1)
	{
		perror("Error while piping.");
		exit(EXIT_FAILURE);
	}
	std_fd[1] = dup(STDOUT_FILENO);
	std_fd[0] = dup(STDIN_FILENO);
	// Hijo
	if ((pid = fork()) == 0)
	{
		dup2(pipe_fd[1], STDOUT_FILENO);
		close(pipe_fd[1]);
		dup2(pipe_fd[0], STDIN_FILENO);
		close(pipe_fd[0]);
		ft_freechararr(exec_cmd(argv[2], argv[1]));
		// atexit(leaks);
		// leaks();
		exit(1);
	}
	// Padre
	else
	{
		// dup2(std_fd[0], pipe_fd[1]);
		// close(std_fd[1]);
		// dup2(std_fd[0], pipe_fd[0]);
		// close(std_fd[0]);
		//
		// dup2(std_fd[1], pipe_fd[1]);
		// close(pipe_fd[1]);
		// dup2(std_fd[0], pipe_fd[0]);
		// close(pipe_fd[0]);
		close(pipe_fd[1]);
		get_next_line(pipe_fd[0]);
		str = get_next_line(pipe_fd[0]);
		i = 1;
		while (str != 0)
		{
			printf("%d _-^-_%s", i++, str);
			str = get_next_line(pipe_fd[0]);
		}
		close(pipe_fd[0]);
	}
	ft_printf("\n\n\033[7;49;34mAcaba el Programa.\033[0m\n");
	return (0);
}
