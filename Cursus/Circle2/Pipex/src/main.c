/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 14:43:05 by angmarti          #+#    #+#             */
/*   Updated: 2023/03/29 19:20:27 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	// int		std_fd[2];
	t_vars	vars;

	check_errors(argc, argv, envp, &vars);
	if (argc == 5)
	{
		case2cmds(&vars);
		return (0);
	}
	// std_fd[0] = dup(STDIN_FILENO);
	// std_fd[1] = dup(STDOUT_FILENO);
	// case_n_cmds(&vars, std_fd, chararrsize(vars.cmds));
	return (0);
}
