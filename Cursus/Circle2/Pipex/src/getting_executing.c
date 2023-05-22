/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getting_executing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 14:44:42 by angmarti          #+#    #+#             */
/*   Updated: 2023/05/19 18:57:11 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/pipex.h"

/**
 * It returns the number of elements in a char **
 * 
 * @param chararr The array of strings to be counted.
 * 
 * @return The number of elements in the array.
 */
int	chararrsize(char **chararr)
{
	int	i;

	i = 0;
	while (chararr[i])
		i++;
	return (i);
}

char	*find_file(char **words, char **path)
{
	char	*file;
	int		i;
	char	*aux;

	i = -1;
	file = NULL;
	while (++i < 6)
	{
		aux = ft_strjoin("/", words[0]);
		file = ft_strjoin(path[i], aux);
		free(aux);
		if (access(file, X_OK) == 0)
			break ;
		free(file);
		file = NULL;
	}
	return (file);
}

/**
 * It takes a command and a path, and returns the path to the command
 * 
 * @param cmd the command to be executed
 * @param path The path to the command.
 * 
 * @return The path of the command.
 */
char	*get_cmd_file(char *cmd, char **path)
{
	int		i;
	char	**words;
	char	*file;

	if (!cmd)
		return (NULL);
	cmd = str_remove_escapes(cmd);
	if ((*cmd == '/' || (*cmd == '.' && cmd[1] == '/')) && access(cmd,
			X_OK) == 0)
		return ((char *)cmd);
	i = -1;
	words = ft_split_not_escaped(cmd, ' ');
	file = find_file(words, path);
	free(cmd);
	ft_freechararr(words);
	return (file);
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
 * and returns an array of strings with the command and its arguments
 * 
 * @param cmd the command to be executed.
 * @param path the PATH variable, split by ':'
 * @param envp is the environment variables.
 * 
 * @return The array of arguments.
 */
void	exec_cmd(char *cmd, char **path, char *envp[])
{
	char	**args;
	char	*file;

	args = get_cmd_args(cmd);
	file = get_cmd_file(cmd, path);
	execve(file, args, envp);
	exit(127);
}
