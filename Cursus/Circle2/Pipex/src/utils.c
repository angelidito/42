/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 14:44:42 by angmarti          #+#    #+#             */
/*   Updated: 2023/03/09 17:45:22 by angmarti         ###   ########.fr       */
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
	//	ft_printf("\033[0m\n\n\033[7;49;33m");
	system("leaks -q pipex");
	// system("leaks -q pipex");
	//	ft_printf("\033[0m");
}

/**
 * It takes a command and a path, and returns the path to the command
 * 
 * @param cmd the command to be executed
 * @param path The path to the command.
 * 
 * @return The path of the command.
 */
char	*get_cmd_file(char const *cmd, char **path)
{
	int		i;
	char	**words;
	char	*result;
	char	*aux;

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
	ft_freechararr(words);
	return (result);
}


/**
 * It takes an environment variable array and returns an array of strings 
 * containing the paths in the PATH environment variable
 * 
 * @param envp The environment variables.
 * 
 * @return the path of the environment variable.
 */
char	**get_path(char *envp[])
{
	int	i;

	i = 0;
	while (envp && envp[i] && ft_strncmp(envp[i], "PATH=", 5))
		i++;
	return (ft_split(envp[i] + 5, ':'));
}

/**
 * It takes a command, a path variable and an environment variable,
	and returns an array of strings
 * with the command and its arguments
 * 
 * @param cmd the command to be executed.
 * @param path the PATH variable, split by ':'
 * @param envp is the environment variables.
 * 
 * @return The array of arguments.
 */
char	**exec_cmd(char const *cmd, char **path, char *envp[])
{
	char	**args;
	int		i;
	char	*file;

	args = ft_split(cmd, ' ');
	i = 0; // TODO: esto
	while (args[i])
		i++;
	i = -1; // se puede quitar. Si funciona sin ellos, claro.
	file = get_cmd_file(cmd, path);
	if (file)
	{
		execve(file, args, envp);
	}
	return (args);
}
