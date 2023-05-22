/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 14:43:05 by angmarti          #+#    #+#             */
/*   Updated: 2023/05/22 18:41:24 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_vars	vars;

	vars.here_doc = 0;
	if (ft_strlen(argv[1]) == 8 && ft_strncmp(argv[1], "here_doc", 8) == 0)
		vars.here_doc = 1;
	check_errors(argc, argv, envp, &vars);
	if (argc == 5)
		case2cmds(&vars);
	else
		case_n_cmds(&vars, NULL, chararrsize(vars.cmds));
	return (0);
}
