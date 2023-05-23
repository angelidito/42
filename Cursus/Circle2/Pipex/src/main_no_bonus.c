/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_no_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 14:43:05 by angmarti          #+#    #+#             */
/*   Updated: 2023/05/23 16:19:23 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_vars	vars;

	check_errors_no_bonus(argc, argv, envp);
	set_vars_no_bonus(argc, argv, envp, &vars);
	case_2_cmds(&vars);
	return (0);
}
