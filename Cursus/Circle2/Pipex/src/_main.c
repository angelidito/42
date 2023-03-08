/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _main.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 17:22:16 by angmarti          #+#    #+#             */
/*   Updated: 2023/03/08 17:17:00 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/pipex.h"

int	_main(int argc, char const **argv, char *envp[])
// int	main(void)
{
	int		i;
	int		std_in_copy;
	int		std_out_copy;
	pid_t	pid;
	char	**path;
	int		fd_infile;

	// size_t	len;
	// char	*str;
	int pipe_fd[2]; // 0 - read ; 1 - write
	//
	i = 0;
	while (envp && envp[i] && ft_strncmp(envp[i], "PATH=", 5))
		i++;
	if (!envp || !envp[i])
	{
		ft_printf("\n\033[1;31mWrong environment vars.\n\n");
		exit(EXIT_FAILURE);
	}
	//|| access(argv[4], O_CREAT | O_RDWR | O_TRUNC) == -1)
	if (access(argv[1], O_RDONLY) == -1)
	{
		ft_printf("\n\033[1;31mNot accessible input file.\n\n");
		exit(EXIT_FAILURE);
	}
	path = ft_split(envp[i] + 5, ':');
	// ft_printf("%s\n\n", envp[i] + 5);
	//	ft_printf("\033[7;49;34mComincia il programma.\033[0m\n\n");
	if (argc != 5)
	{
		ft_printf("\n\033[1;31mUsage: %s infile command1 command1 outfile\n\n",
					argv[0]);
		exit(EXIT_FAILURE);
	}
	ft_printf("\n\033[7;34mExecuting: %s %s %s %s %s\033[0m\n\n", argv[0],
			argv[1], argv[2], argv[3], argv[4]);
	if (pipe(pipe_fd) == -1)
	{
		perror("\033[1;31mError while piping.");
		exit(EXIT_FAILURE);
	}
	std_in_copy = dup(STDIN_FILENO);
	std_out_copy = dup(STDOUT_FILENO);
	// FILES
	fd_infile = open(argv[1], O_RDONLY);
	pid = fork();
	if (pid == -1)
	{
		dup2(std_out_copy, 1);
		close(std_out_copy);
		ft_printf("\n\n\033[1;31mErrore nella creazione del subprocesso\033[0m\n");
		leaks();
		exit(1);
	}
	if (pid == 0)
	{
		dup2(pipe_fd[1], STDOUT_FILENO);
		dup2(pipe_fd[0], fd_infile);
		//	ft_printf("\nEntriamo nel figlio...\n");
		close(pipe_fd[0]);
		ft_freechararr(exec_cmd(argv[2], path, envp));
		close(pipe_fd[1]);
		dup2(std_out_copy, STDOUT_FILENO);
		ft_printf("\n\n\033[1;31mErrore nel processo figlio\033[0m\n");
	}
	else
	{
		dup2(pipe_fd[0], STDIN_FILENO);
		dup2(std_out_copy, STDOUT_FILENO);
		close(pipe_fd[1]);
		/* 
			i = 1;
			str = NULL;
		//	ft_printf("\nEntriamo nel padre...\n");
			len = 0;
		//	ft_printf("\nEntriamo nel ciclo...\n");
			while (len != ft_strlen(str))
			{
				len = ft_strlen(str);
				str = ft_strjoin_n_free(str, get_next_line(pipe_fd[0]));
			}
		//	ft_printf("\nUsciamo dal ciclo...\n");
			close(pipe_fd[0]);
		//	ft_printf("%s", str);
		*/
		close(pipe_fd[0]);
		dup2(open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644), STDOUT_FILENO);
		exec_cmd(argv[3], path, envp);
		dup2(std_out_copy, STDOUT_FILENO);
		ft_printf("\n\n\033[1;31mErrore nel processo padre\033[0m\n");
	}
	//	ft_printf("\n\n\033[7;49;34mProcesso %d è finito.\033[0m\n\n", pid);
	// leaks();
	return (0);
}

void	myfunction(char *cmd, char *infile)
{
	char	*argv[];
	int		status;

	// Ejecutar el comando especificado usando execve
	argv[] = {"/bin/sh", "-c", cmd, NULL};
	int fd = open(infile, O_RDONLY); // Abrir el fichero de entrada
	if (fd == -1)
	{
		perror("Error al abrir el fichero de entrada");
		return ;
	}
	pid_t pid = fork(); // Crear un proceso hijo
	if (pid == -1)
	{
		perror("Error al crear el proceso hijo");
		return ;
	}
	else if (pid == 0)
	{
		// Redirigir la entrada estándar del hijo al fichero de entrada
		if (dup2(fd, STDIN_FILENO) == -1)
		{
			perror("Error al redirigir la entrada estándar");
			_exit(EXIT_FAILURE);
		}
		execve(argv[0], argv, NULL);
		// Si execve devuelve, significa que ha habido un error
		perror("Error al ejecutar el comando");
		_exit(EXIT_FAILURE);
	}
	// Esperar a que el proceso hijo termine
	if (waitpid(pid, &status, 0) == -1)
	{
		perror("Error al esperar al proceso hijo");
		return ;
	}
	// Cerrar el fichero de entrada
	if (close(fd) == -1)
	{
		perror("Error al cerrar el fichero de entrada");
		return ;
	}
}
