/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 14:24:56 by angmarti          #+#    #+#             */
/*   Updated: 2022/12/19 16:44:15 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

// void	write_list(void *content)
// {
// 	t_number	*elem;

// 	elem = (t_number *)content;
// 	printf("%d ", elem->value);
// }

/**
 * This function frees the memory allocated for the array of strings,
 * the linked list, and the trimmed string
 * 
 * @param chararr the array of strings that was created from the file
 * @param lst a list of strings, each string is a line of the file
 * @param trimmed the string that was trimmed
 */
void	free_case_two_args(char **chararr, t_list **lst, char *trimmed)
{
	free_chararr(chararr);
	ft_lstclear(lst, *free);
	free(lst);
	free(trimmed);
}

/**
 * It replaces all the whitespace characters in a string with spaces,
 * and then splits the string on spaces
 * 
 * @param p the string to be split
 * 
 * @return a pointer to the the array of strings.
 */
char	**repalce_split(char *p)
{
	int		i;

	if (!ft_strlen(p))
		exit(0);
	i = -1;
	while (p[++i])
	{
		if (p[i] == '\t' || p[i] == '\n' || p[i] == '\v' || p[i] == '\r'
			|| p[i] == '\f')
			p[i] = ' ';
	}
	return (ft_split(p, ' '));
}

// ft_lstiter(*lst, *write_list);

int	case_two_args(char const *argv[])
{
	int		i;
	t_list	**lst;
	char	**chararr;
	char	*trimmed;

	trimmed = ft_strtrim(argv[1], " \t\n\v\r\f");
	chararr = repalce_split(trimmed);
	check_errors_chararr(chararr);
	lst = ft_calloc(1, sizeof(t_list **));
	if (!lst)
	{
		free_chararr(chararr);
		exit(0);
	}
	i = 0;
	*lst = ft_lstnew(new_number(ft_atoi(chararr[i]), -1));
	while (chararr[++i])
		if (ft_strlen(chararr[i]))
			ft_lstadd_front(lst, ft_lstnew(new_number(ft_atoi(chararr[i]),
						-1)));
	order(lst);
	free_case_two_args(chararr, lst, trimmed);
	return (0);
}

int	case_multiple_args(int argc, char const *argv[])
{
	int		i;
	t_list	**lst;

	check_errors_argv(argc, argv);
	lst = ft_calloc(1, sizeof(t_list **));
	if (!lst)
		exit(1);
	i = 1;
	*lst = ft_lstnew(new_number(ft_atoi(argv[i]), -1));
	if (!lst)
		exit(1);
	while (++i < argc)
		ft_lstadd_front(lst, ft_lstnew(new_number(ft_atoi(argv[i]), -1)));
	order(lst);
	ft_lstclear(lst, *free);
	free(lst);
	return (0);
}

int	main(int argc, char const *argv[])
{
	if (argc < 2)
		return (0);
	else if (argc == 2)
		case_two_args(argv);
	else
		case_multiple_args(argc, argv);
	system("leaks push_swap");
	return (0);
}
