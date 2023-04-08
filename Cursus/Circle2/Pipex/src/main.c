/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 14:43:05 by angmarti          #+#    #+#             */
/*   Updated: 2023/04/08 22:17:43 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/pipex.h"

void	checkpoint(void)
{
	ft_printf("\033[0m––––____checkpoint____––––\n\033[0m");
}

void	leaks(void)
{
	ft_printf("\033[0m\n\n\033[7;49;33m");
	system("leaks -q pipex");
	ft_printf("\033[0m");
}

void	test(char **argv, int j)
{
	int		i;
	char	**args;

	printf("\033[0m\n");
	args = get_cmd_args(argv[j]);
	if (!args[0])
		printf("No args\n");
	else
	{
		printf("\n\033[0mComand[%d]: \033[7;49;34m", j);
		i = 1;
		// while (i < argc)
		// {
			printf("\033[7;49;34m%s ", argv[j]);
		// 	i++;
		// }
		printf("\033[0m\nRESULT: \n");
	}
	i = 0;
	while (args[i])
	{
		printf("\033[0margs[%d]: \033[7;49;33m%s\n", i, args[i]);
		i++;
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_vars	vars;
	int		j;

	if (argc > 1 && ft_strncmp(argv[1], "test", 4) == 0)
	{
		j = 3;
		while (argv[j+1])
			test(argv, j++);
		exit(0);
	}
	check_errors(argc, argv, envp, &vars);
	if (argc == 5)
		case2cmds(&vars);
	else
		case_n_cmds(&vars, NULL, chararrsize(vars.cmds));
	return (0);
}
