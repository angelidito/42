/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 14:43:05 by angmarti          #+#    #+#             */
/*   Updated: 2023/03/16 18:35:43 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/pipex.h"


int	main(int argc, char **argv, char **envp)
{
	t_vars	vars;

	vars.argc = argc;
	vars.argv = argv;
	vars.envp = envp;
	check_errors(&vars);
	if (argc == 5)
		case2cmds(&vars);
	else
		case_n_cmds(&vars);
		return (0);
}
