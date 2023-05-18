/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 18:23:10 by angmarti          #+#    #+#             */
/*   Updated: 2023/05/17 17:43:51 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/pipex.h"

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

// if (*len == 0) // ! CON COMILLAS----------------
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
// if (*len == 0) // ! SIN COMILLAS-------------
// {
// 	if (cmd[*i] == '\'')
// 		*search = "\'";
// 	else if (cmd[*i] == '\"')
// 		*search = "\"";
// 	*i += 1;
// 	*len = -1;
// 	return ;
// } // SIN COMILLAS--------------------------

int	search_word(char const *cmd, int *i, int *len, char **search)
{
	if (ft_strchr(*search, cmd[*i + *len]) && !is_escaped_quote(cmd, *i + *len))
	{
		if (*len == 0)
		{
			if (cmd[*i] == '\'')
				*search = "\'";
			else if (cmd[*i] == '\"')
				*search = "\"";
			*i += 1;
			*len = -1;
			return (0);
		}
		return (1);
	}
	return (0);
}

void	set_arg_lst(char const *cmd, t_list **arg_lst)
{
	int		i;
	int		len;
	char	*search;
	t_list	*node;

	i = 0;
	len = -1;
	search = " '\"";
	while (cmd && (i + ++len) < (int)ft_strlen(cmd))
	{
		if (search_word(cmd, &i, &len, &search))
		{
			node = ft_lstnew(ft_substr(cmd, i, len));
			ft_lstadd_back(arg_lst, node);
			i += len + 1;
			len = -1;
			search = " '\"";
		}
	}
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
		return (ft_split_not_escaped(cmd, ' '));
	arg_lst = ft_calloc(sizeof(t_list *), 1);
	if (!arg_lst)
		return (NULL);
	set_arg_lst(cmd, arg_lst);
	remove_escapes(arg_lst);
	arg_arr = lst_to_arr(arg_lst);
	return (arg_arr);
}
