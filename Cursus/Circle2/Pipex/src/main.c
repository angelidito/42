/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 14:43:05 by angmarti          #+#    #+#             */
/*   Updated: 2023/05/19 18:57:29 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_vars	vars;

	check_errors(argc, argv, envp, &vars);
	if (argc == (5 + vars.here_doc))
		case2cmds(&vars);
	else
		case_n_cmds(&vars, NULL, chararrsize(vars.cmds));
	return (0);
}
