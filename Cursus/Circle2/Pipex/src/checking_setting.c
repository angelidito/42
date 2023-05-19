/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_setting.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 18:31:18 by angmarti          #+#    #+#             */
/*   Updated: 2023/05/19 18:03:10 by angmarti         ###   ########.fr       */
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
	if (access(cmd, F_OK) == 0 && !file)
	{
		print_stderr("pipex: permission denied: ");
		print_stderr(cmd);
		print_stderr("\n");
	}
	else if (!file)
	{
		print_stderr("pipex: command not found: ");
		print_stderr(cmd);
		print_stderr("\n");
	}
	free(file);
}

/**
 * The function sets variables in a t_vars struct
 * 
 * @param argc Number of arguments passed to the program
 * @param argv Arguments passed to the program
 * @param vars Variables used in the program.
 */
void	set_vars(int argc, char **argv, t_vars *vars)
{
	int	i;

	vars->here_doc = 0;
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
	{
		vars->here_doc = 1;
		vars->infile = TEMP_HERE_DOC;
		heredoc(argv[2]);
	}
	else
		vars->infile = argv[1];
	vars->outfile = argv[argc - 1];
	vars->cmds = ft_calloc(argc - (2 + vars->here_doc), sizeof(char *));
	if (!vars->cmds)
		pf_exit("Malloc error", STDERR_FILENO);
	i = 1 + vars->here_doc;
	while (++i < argc - 1)
		vars->cmds[i - (2 + vars->here_doc)] = argv[i];
}

/**
 * It checks:
 * 		the number of arguments, 
 * 		and if the environment variables are set.
 * Also sets:
 * 		the vars path, 
 * 		infile, 
 * 		outfile, 
 * 		and cmds.
 * @param argc Number of arguments passed to the program
 * @param argv Arguments passed to the program
 * @param envp Environment variables
 * @param vars Variables used in the program.
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
		ft_printf("Usage: %s infile", argv[0]);
		pf_exit(" command1 command2 [... commandN] outfile", 1);
	}
	i = 0;
	while (envp && envp[i] && ft_strncmp(envp[i], "PATH=", 5))
		i++;
	if (!envp || !envp[i])
	{
		// i = 1;
		// while (++i < argc - 1)
		// {
		// 	ft_printf("pipex: command not found: ");
		// 	ft_printf("%s", ft_split(argv[i], ' ')[0]);
		// 	ft_printf("\n");
		// }
		// print_stderr("PATH not set.");
		exit(0);
	}
	vars->path = get_path(envp);
	vars->envp = envp;
	set_vars(argc, argv, vars);
}
