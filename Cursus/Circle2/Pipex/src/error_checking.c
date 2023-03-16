/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checking.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 18:31:18 by angmarti          #+#    #+#             */
/*   Updated: 2023/03/16 18:31:34 by angmarti         ###   ########.fr       */
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
		ft_printf("command not found: %s\n", cmd);
}

/**
 * It checks the number of arguments, checks if the environment variables 
 * are set, and set the path var
 * 
 * @param vars a pointer to a t_vars structure.
 */
void	check_errors(t_vars *vars)
{
	int	i;

	if (vars->argc < 5)
	{
		ft_printf("\n\033[1;31mUsage: %s infile command1 command1 outfile\n\n",
					vars->argv[0]);
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (vars->envp && vars->envp[i] && ft_strncmp(vars->envp[i], "PATH=", 5))
		i++;
	if (!vars->envp || !vars->envp[i])
	{
		ft_printf("\n\033[1;31mWrong environment vars.\n\n");
		exit(EXIT_FAILURE);
	}
	vars->path = get_path(vars->envp);
}
