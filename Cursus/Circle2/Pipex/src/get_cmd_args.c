/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 18:23:10 by angmarti          #+#    #+#             */
/*   Updated: 2023/05/05 16:17:46 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/pipex.h"

//0                         1                     2                    3      _
// awk  sdfdf dfg dfsgsgfg  '{print $1} {print $1}' sdfdf dfg dfsgsgfg '{t $1}'
// 1 3

//0                 1                     2 3      4  5      _
// awk  sdfdf dfg   '{print $1} {print $1}' '{t $1}'  '{t $1}'
// 1 3 5

// 0  3  6    11             5                     2           3      4         _
// awk   sdfdf dfg dfsgsgfg  '{print $1} {print $1}' "{t $1}"  '{t $1}'  "{t $1}"
// 1 3
// Re do to the rest: 2 4

int	is_escaped_quote(char const *cmd, int i)
{
	if (cmd[i] == '\'' || cmd[i] == '\"')
	{
		if (i == 0)
			return (0);
		if (cmd[i - 1] == '\\')
			return (1);
	}
	return (0);
}

// int	set_search(char const *cmd, int i, char **search)
// {
// 	if (cmd[i] == ' ')
// 		return (0);
// 	if (cmd[i] == '\'')
// 		*search = "\'";
// 	else if (cmd[i] == '\"')
// 		*search = "\"";
// 	return (1);
// }

// ! CON COMILLAS
// if (*len == 0) // CON COMILLAS
// {
// 	if (cmd[*i + *len] == ' ')
// 	{
// 		*i += 1;
// 		*len = -1;
// 	}
// 	else if (cmd[*i] == '\'')
// 		*search = "\'";
// 	else if (cmd[*i] == '\"')
// 		*search = "\"";
// 	return ;
// }
// if (cmd[*i + *len] != ' ')
// 	*len += 1; // CON COMILLAS

// ! SIN COMILLAS
// if (*len == 0) // SIN COMILLAS
// {
// 	if (cmd[*i] == '\'')
// 		*search = "\'";
// 	else if (cmd[*i] == '\"')
// 		*search = "\"";
// 	*i += 1;
// 	*len = -1;
// 	return ;
// } // SIN COMILLAS

void	w_logic(char const *cmd, t_list **lst, int *i, int *len, char **search)
{
	t_list	*node;

	if (ft_strchr(*search, cmd[*i + *len]) && !is_escaped_quote(cmd, *i + *len))
	{
		// if (*len == 0) // CON COMILLAS----------------
		// {
		// 	if (cmd[*i + *len] == ' ')
		// 	{
		// 		*i += 1;
		// 		*len = -1;
		// 	}
		// 	else if (cmd[*i] == '\'')
		// 		*search = "\'";
		// 	else if (cmd[*i] == '\"')
		// 		*search = "\"";
		// 	return ;
		// }
		// if (cmd[*i + *len] != ' ')
		// 	*len += 1; // CON COMILLAS----------------
		if (*len == 0) // SIN COMILLAS-------------
		{
			if (cmd[*i] == '\'')
				*search = "\'";
			else if (cmd[*i] == '\"')
				*search = "\"";
			*i += 1;
			*len = -1;
			return ;
		} // SIN COMILLAS--------------------------
		// ft_printf("Adding: %s%s%s\n", TEXT_BG_MAGENTA, ft_substr(cmd, *i, *len),
		// 		TEXT_RESET);
		node = ft_lstnew(ft_substr(cmd, *i, *len));
		// ft_printf("node created|\n");
		ft_lstadd_back(lst, node);
		// checkpoint();
		// ft_lstadd_back(lst, ft_lstnew(ft_substr(cmd, *i, *len)));
		*i += *len + 1;
		// printf("i reslut: %d\n", *i);
		*len = -1;
		*search = " '\"";
	}
}

void	set_arg_lst(char const *cmd, t_list **arg_lst)
{
	int		i;
	int		len;
	char	*search;

	i = 0;
	search = " '\"";
	len = -1;
	// if (cmd)
	// 	ft_printf("cmd: %s%s%s\n", TEXT_BG_CYAN, cmd, TEXT_RESET);
	// else
	// 	ft_printf("cmd: %sNULL%s\n", TEXT_BG_BRIGHT_RED, cmd, TEXT_RESET);
	while (cmd && (i + ++len) < (int)ft_strlen(cmd))
		w_logic(cmd, arg_lst, &i, &len, &search);
	if (len > 0)
		ft_lstadd_back(arg_lst, ft_lstnew(ft_substr(cmd, i, len)));
}

char	**lst_to_arr(t_list **lst)
{
	char	**arr;
	t_list	*node;
	int		i;
	int		size;

	size = ft_lstsize(*lst);
	arr = ft_calloc(size + 1, sizeof(char *));
	if (!arr)
		return (NULL);
	node = *lst;
	i = 0;
	while (i < size)
	{
		arr[i] = ft_strtrim((char *)node->content, " \t\n\v\r\f");
		node = node->next;
		i++;
	}
	return (arr);
}

/**
 * Takes a command string and returns an array of its arguments, 
 * splitting them by spaces and/or quotes.
 * 
 * @param cmd A command.
 * 
 * @return An array of strings, each one being an argument of the command.
 */
char	**get_cmd_args(char const *cmd)
{
	t_list	**arg_lst;
	char	**arg_arr;

	if (!ft_strchr(cmd, '\'') && !ft_strchr(cmd, '\"'))
		return (ft_split(cmd, ' '));
	arg_lst = ft_calloc(sizeof(t_list *), 1);
	if (!arg_lst)
		return (NULL);
	set_arg_lst(cmd, arg_lst);
	arg_arr = lst_to_arr(arg_lst);
	return (arg_arr);
}
