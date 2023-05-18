/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 14:43:05 by angmarti          #+#    #+#             */
/*   Updated: 2023/05/18 18:36:13 by angmarti         ###   ########.fr       */
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

	printf("%s", TEXT_RESET);
	args = get_cmd_args(argv[j]);
	if (!args[0])
		printf("No args\n");
	else
	{
		printf("%sComand[%d]: ", TEXT_RESET, j + 1);
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
	printf("%s\n\033[1;32m\n", get_cmd_file(argv[j], get_path(envp)));
}

// int	main(void)
// {
// 	char	**array;
// 	int		i;
// 	int		j;
// 	char	**split;

// 	array = ft_calloc(sizeof(char **), 800);
// 	i = 0;
// 	array[i++] = "\\hola\\que\\tal";
// 	array[i++] = "\\\\hola\\\\que\\\\tal";
// 	array[i++] = "\\hola\\ \\que\\\\tal\\\\\\";
// 	// array[i++] = "HOLA QUE TAL";
// 	// array[i++] = "HOLA QUE TAL   ";
// 	// array[i++] = " HOLA QUE TAL   ";
// 	// array[i++] = " HOLA  QUE  TAL   ";
// 	// array[i++] = "HOLA\\ QUE TAL";
// 	// array[i++] = "HOLA \\ QUE TAL";
// 	// array[i++] = "\\  \\  \\  HOLA \\  \\  \\  QUE TAL\\  \\  ";
// 	// array[i++] = "HOLA QUE TAL\\   ";
// 	// array[i++] = "HOLA\\ QUE TAL    ";
// 	// array[i++] = "    HOLA\\     \\ QUE\\   TAL    ";
// 	// array[i++] = "    HOLA\\ \\ QUE\\   TAL    ";
// 	// array[i++] = "\\ HOLA QUE TAL ";
// 	// array[i++] = "   \\ \\ HOLA QUE TAL ";
// 	i = 0;
// 	while (array[i])
// 	{
// 		ft_printf("%s%s%s\n", TEXT_BG_BLUE, array[i], TEXT_RESET);
// 		split = ft_split_not_escaped(array[i], '\\');
// 		j = 0;
// 		while (split[j])
// 		{
// 			printf("Palabra %d: %s%s%s\n", j, TEXT_BG_BRIGHT_YELLOW, split[j],
// TEXT_RESET);
// 			j++;
// 		}
// 		i++;
// 	}
// 	return (0);
// }

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

// int		count_escapes(char const *str);
// int		count_escaped_chars(char const *str, int start, int end, char c);
// void	_remove_escapes(t_list *elem);
// char	*str_remove_escapes(char *str);
// int	main(void)
// {
// 	char	*str;
// 	// t_list	*elem;
// 	char	*newstr;

// 	// atexit(leaks);
// 	for (size_t i = 0; i < 3; i++)
// 	{
// 		str = "\\\\\\\\\\H\\o\\l\\a\\ \\q\\u\\e\\ \\t\\a\\l\\";
// 		// elem = ft_lstnew(ft_strdup(str));
// 		ft_printf("       str: %s%s%s\n", TEXT_BG_BLUE, str, TEXT_RESET);
// 		newstr = str_remove_escapes(str);
// 		ft_printf("str no esc: %s%s%s\n", TEXT_BG_BLUE, newstr,
// 				TEXT_RESET);
// 		// free(elem);
// 		free(newstr);
// 	}
// 	atexit(leaks);
// 	return (0);
// }
