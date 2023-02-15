/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 17:22:16 by angmarti          #+#    #+#             */
/*   Updated: 2023/02/15 16:58:38 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/pipex.h"

void	breakpoint(void)
{
	//	ft_printf("\033[0m––––____BREAKPOINT____––––\n\033[0m");
}

/**
 * It runs the command `leaks -q fdf` and prints the result in yellow.
 * Usage: atexit(leaks);
 */
void	leaks(void)
{
	//	ft_printf("\033[0m\n\n\033[7;49;33m");
	system("leaks -q pipex");
	// system("leaks -q pipex");
	//	ft_printf("\033[0m");
}

// void	set_path(char **path)
// {
// 	path[0] = "/usr/local/bin";
// 	path[1] = "/usr/bin";
// 	path[2] = "/bin";
// 	path[3] = "/usr/sbin";
// 	path[4] = "/sbin";
// 	path[5] = "/usr/local/munki";
// 	path[6] = NULL;
// }

char	*get_cmd_path(char const *cmd, char **path)
{
	int		i;
	char	**words;
	char	*result;
	char	*aux;

	// char	*path[7];
	// set_path(path);
	i = -1;
	words = ft_split(cmd, ' ');
	result = NULL;
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

char	**exec_cmd(char const *cmd, char const *arg, char **path, char *envp[])
{
	char	**temp_arg;
	int		i;
	char	**argv;
	char	*cmd_path;

	temp_arg = ft_split(cmd, ' ');
	i = 0;
	while (temp_arg[i])
		i++;
	argv = ft_calloc(i + 2, sizeof(char *));
	i = -1;
	while (temp_arg[++i])
		argv[i] = temp_arg[i];
	argv[i] = ft_strtrim(arg, " \n\t\r\f\v");
	free(temp_arg); // necesario?
	i = -1;
	// while (argv[++i])
	// //	ft_printf("%s ", argv[i]);
	// ft_printf("\n", argv[i]);
	cmd_path = get_cmd_path(cmd, path);
	if (cmd_path)
		execve(cmd_path, argv, envp);
	return (argv);
}

int	main(int argc, char const **argv, char *envp[])
// int	main(void)
{
	int		i;
	int		std_in_copy;
	int		std_out_copy;
	pid_t	pid;
	char	**path;

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
	path = ft_split(envp[i] + 5, ':');
	// ft_printf("%s\n\n", envp[i] + 5);
	//	ft_printf("\033[7;49;34mComincia il programma.\033[0m\n\n");
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
	std_in_copy = dup(0);
	std_out_copy = dup(1);
	dup2(pipe_fd[0], STDIN_FILENO);
	dup2(pipe_fd[1], STDOUT_FILENO);
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
		//	ft_printf("\nEntriamo nel figlio...\n");
		close(pipe_fd[0]);
		ft_freechararr(exec_cmd(argv[2], argv[1], path, envp));
		close(pipe_fd[1]);
		dup2(std_out_copy, STDOUT_FILENO);
		ft_printf("\n\n\033[1;31mErrore nel processo figlio\033[0m\n");
	}
	else
	{
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
		exec_cmd(argv[3], NULL, path, envp);
		dup2(std_out_copy, STDOUT_FILENO);
		ft_printf("\n\n\033[1;31mErrore nel processo padre\033[0m\n");
	}
	//	ft_printf("\n\n\033[7;49;34mProcesso %d è finito.\033[0m\n\n", pid);
	// leaks();
	return (0);
}

// // int main(int argc, char const *argv[])
// int	main(void)
// {
// 	int	std_out_copy;

// 	int pipe_fd[2]; // 0 - read ; 1 - write
// 	std_out_copy = dup(1);
// //	ft_printf("\033[7;49;34mComienza el Programa.\033[0m\n\n");
// 	if (pipe(pipe_fd) == -1)
// 	{
// 		perror("\033[1;31mError while piping.");
// 		exit(EXIT_FAILURE);
// 	}
// 	dup2(pipe_fd[1], STDIN_FILENO);
// 	close(pipe_fd[1]);
// 	dup2(std_out_copy, 1);
// 	close(std_out_copy);
// //	ft_printf("\ndup2(%d, %d);\n", pipe_fd[1], STDIN_FILENO);
// //	ft_printf("\n--__----+-+_**--HA FUNCIONADO _____---_-_-------_____\n");
// 	wait(0);
// 	//
// 	// dup2(std_fd[1], pipe_fd[1]);
// 	// close(pipe_fd[1]);
// 	// dup2(std_fd[0], pipe_fd[0]);
// 	// close(pipe_fd[0]);
// 	close(pipe_fd[1]);
// //	ft_printf("\n\n\033[7;49;34mAcaba el Programa.\033[0m\n");
// 	return (0);
// }
