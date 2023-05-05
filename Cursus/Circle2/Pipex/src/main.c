/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 14:43:05 by angmarti          #+#    #+#             */
/*   Updated: 2023/05/05 17:38:26 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/pipex.h"

void	checkpoint(void)
{
	ft_putstr_fd("\033[0m––––____checkpoint____––––\n\033[0m", STDOUT_FILENO);
}

void	leaks(void)
{
	ft_printf("\033[0m\n\n\033[7;49;33m");
	system("leaks -q pipex");
	ft_printf("\033[0m");
}

void	test(char **argv, int j, char **envp)
{
	int		i;
	char	**args;

	printf("\033[0m\n");
	args = get_cmd_args(argv[j]);
	if (!args[0])
		printf("No args\n");
	else
	{
		printf("\n\033[0mComand[%d]: ", j + 1);
		i = 1;
		printf("\033[7;49;34m%s\n", argv[j]);
	}
	i = 0;
	while (args[i])
	{
		printf("\033[0m  arg%d: \033[7;49;33m%s\n", i, args[i]);
		i++;
	}
	printf("\033[0m  CmdFile: \033[7;49;33m");
	printf("%s\n\033[1;32m", get_cmd_file(argv[0], get_path(envp)));
}

int	main(int argc, char **argv, char **envp)
{
	t_vars	vars;
	char	**cmds;
	int		i;

	if (0 && (argc > 1 && ft_strncmp(argv[1], "test", ft_strlen(argv[1])) == 0))
	{
		ft_printf("\033[7;31m                           \n");
		ft_printf("\033[7;31m         TEST MODE         \n");
		ft_printf("\033[7;31m                           \n");
		cmds = ft_calloc(100, sizeof(char *));
		i = 0;
		cmds[i++] = argv[3];
		cmds[i++] = argv[4];
		cmds[i++] = argv[4];
		i = 0;
		while (cmds[i])
			test(cmds, i++, envp);
		exit(0);
	}
	check_errors(argc, argv, envp, &vars);
	if (argc == 5)
		case2cmds(&vars);
	else
		case_n_cmds(&vars, NULL, chararrsize(vars.cmds));
	return (0);
}
