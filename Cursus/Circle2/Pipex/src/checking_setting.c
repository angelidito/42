/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_setting.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 18:31:18 by angmarti          #+#    #+#             */
/*   Updated: 2023/04/02 18:13:33 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/pipex.h"

/**
 * It prints the error message associated with the last system call, 
 * and then exits the program
 * 
 * @param s The string to print.
 */
void	my_perror(char *s)
{
	perror(s);
	exit(EXIT_FAILURE);
}

/**
 * It checks if a command exists in the path
 * 
 * @param cmd the command to check
 * @param path the path to the command
 */
void	check_cmd(char *cmd, char **path)
{
	char	*file;

	file = get_cmd_file(cmd, path);
	if (!file)
		ft_printf("pipex: command not found: %s\n", cmd);
}

/**
 * It takes the command line arguments and assigns them to the appropriate 
 * variables
 * 
 * @param vars a pointer to the t_vars struct
 */
void	set_vars(int argc, char **argv, t_vars *vars)
{
	int	i;

	vars->infile = argv[1];
	vars->outfile = argv[argc - 1];
	vars->cmds = ft_calloc(argc - 2, sizeof(char *));
	if (!vars->cmds)
	{
		ft_printf("\n\033[1;31mMalloc Error.\n\n");
		exit(EXIT_FAILURE);
	}
	i = 1;
	while (++i < argc - 1)
		vars->cmds[i - 2] = argv[i];
}

/**
 * It checks the number of arguments, checks if the environment variables 
 * are set, and set the vars path, infile, outfile, and cmds
 * 
 * @param vars a pointer to a t_vars structure.
 */
void	check_errors(int argc, char **argv, char **envp, t_vars *vars)
{
	int	i;

	if (argc < 5)
	{
		ft_printf("\n\033[1;31mUsage: %s infile", argv[0]);
		ft_printf(" command1 command1 outfile\n\n");
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (envp && envp[i] && ft_strncmp(envp[i], "PATH=", 5))
		i++;
	if (!envp || !envp[i])
	{
		ft_printf("\n\033[1;31mWrong environment vars.\n\n");
		exit(EXIT_FAILURE);
	}
	vars->path = get_path(envp);
	vars->envp = envp;
	set_vars(argc, argv, vars);
}
