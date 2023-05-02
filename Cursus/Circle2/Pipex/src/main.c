/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 14:43:05 by angmarti          #+#    #+#             */
/*   Updated: 2023/05/01 18:04:52 by angmarti         ###   ########.fr       */
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
		// while (i < argc)
		// {
		printf("\033[7;49;34m%s\n", argv[j]);
		// 	i++;
		// }
		// printf("\033[0m\nRESULT: \n");
	}
	i = 0;
	while (args[i])
	{
		printf("\033[0m  arg%d: \033[7;49;33m%s\n", i, args[i]);
		i++;
	}
	printf("\033[0m  CmdFile: \033[7;49;33m%s\n\033[1;32m",
			get_cmd_file(argv[0], get_path(envp)));
	execve(get_cmd_file(argv[0], get_path(envp)), args, envp);
}

int	main(int argc, char **argv, char **envp)
{
	t_vars	vars;
	char	**cmds;
	int		i;

	if ((argc > 1 && ft_strncmp(argv[1], "test", ft_strlen(argv[1])) == 0))
	{
		ft_printf("\033[7;31m                           \n");
		ft_printf("\033[7;31m         TEST MODE         \n");
		ft_printf("\033[7;31m                           \n");
		cmds = ft_calloc(100, sizeof(char *));
		i = 0;
		////////////////////////
		// TEST CMDS
		cmds[i++] = "awk '{count++} END {print count}'";
		// cmds[i++] = "awk {no quotes}";
		// cmds[i++] = "awk '{quotes}'";
		// cmds[i++] = "awk '{ quo \\' tes}'";
		// cmds[i++] = "awk '{ quo \\' tes}'";
		// cmds[i++] = "awk '{quoteleft}";
		// cmds[i++] = "awk \'{escq\\\"uotes}\'";
		// cmds[i++] = "awk '{quoteleft}";
		// cmds[i++] = "awk \'{escquoteleft}";
		// cmds[i++] = "awk {quoteright}'";
		// cmds[i++] = "awk {escquoteright}\'";
		// cmds[i++] = "awk \"{quotes}\"";
		// cmds[i++] = "awk \"{ quo\\\"tes}\"";
		// cmds[i++] = "awk \"{ quo \\\" tes}\"";
		// cmds[i++] = "awk \"{quoteleft}";
		// cmds[i++] = "awk \"{escq\"uotes}\"";
		// cmds[i++] = "awk \"{quoteleft}";
		// cmds[i++] = "awk \"{escquoteleft}";
		// cmds[i++] = "awk {quoteright}\"";
		// cmds[i++] = "awk {escquoteright}\\\"";
		//////////////////////
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
