/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_setting.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 18:31:18 by angmarti          #+#    #+#             */
/*   Updated: 2023/05/05 17:35:50 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/pipex.h"

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
	{
		print_stderr("pipex: command not found: ");
		print_stderr(cmd);
		print_stderr("\n");
	}
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
		pf_exit("Malloc Error.", STDERR_FILENO);
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
	int		i;
	char	*tmp;

	i = argc;
	while (--i > 1)
	{
		tmp = ft_strtrim(argv[i], " \t\v\f\r");
		if (!tmp || !*tmp)
			pf_exit("Wrong arguments.", 1);
		free(tmp);
	}
	if (argc < 5)
	{
		ft_printf("\nUsage: %s infile", argv[0]);
		pf_exit(" command1 command2 [... commandN] outfile", 1);
	}
	i = 0;
	while (envp && envp[i] && ft_strncmp(envp[i], "PATH=", 5))
		i++;
	if (!envp || !envp[i])
		pf_exit("PATH not set.", 1);
	vars->path = get_path(envp);
	vars->envp = envp;
	set_vars(argc, argv, vars);
}
