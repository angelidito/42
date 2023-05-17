/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backslashes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 18:23:10 by angmarti          #+#    #+#             */
/*   Updated: 2023/05/16 18:03:55 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/pipex.h"

// void	remove_backslash(t_list **lst)
// {
// 	t_list	*node;
// 	char	*str;
// 	int		i;
// 	char	**chararr;

// 	node = *lst;
// 	while (node)
// 	{
// 		if (!ft_strchr(node->content, '\\'))
// 		{
// 			node = node->next;
// 			continue ;
// 		}
// 		i = -1;
// 		str = ft_strdup("");
// 		chararr = ft_split(node->content, '\\');
// 		while (chararr[++i])
// 			str = ft_strjoin_n_free_op(str, chararr[i], 1, 0);
// 		ft_freechararr(chararr);
// 		free(node->content);
// 		node->content = str;
// 		node = node->next;
// 	}
// }
// int	count_not_slashed_words(char const *s, char c)
// {
// 	// int	slashed;
// 	int	count;
// 	int	i;

// 	i = 0;
// 	count = 0;
// 	if (*s && *s != c)
// 		count++;
// 	while (s[++i])
// 		if (s[i - 1] == c && s[i] != c)
// 			count++;
// 	return (count);
// }

// // split_not_escaped(char const *s, char c);

// void	_remove_notescaped_backslash(char *str)
// {
// 	char	*slash;
// 	// int		words;

// 	slash = str;
// 	// words = ft_count_slashed_words(str);
// }
// void	remove_notescaped_backslash(t_list **lst)
// {
// 	t_list	*node;

// 	node = *lst;
// 	while (node)
// 	{
// 		_remove_notescaped_backslash(node->content);
// 		node = node->next;
// 	}
// }

/**
 * The function counts the number of escaped characters in a given string..
 * 
 * @param str String to check.
 * 
 * @return int Number of times a character is escaped.
 */
int	count_escapes(char const *str)
{
	int	count;

	count = 0;
	while (*str)
	{
		if (*str == '\\')
		{
			str++;
			count++;
		}
		if (*str)
			str++;
	}
	return (count);
}
// {
// 	int count;

// 	count = 0;
// 	while (*str)
// 	{
// 		if (*str == '\\')
// 		{
// 			if (*(str + 1) == '\\')
// 				str++;
// 			count++;
// 		}
// 		str++;
// 	}
// 	return (count);
// }

/**
 * This function removes escape characters from a string in node 
 * in a linked list.
 * 
 * @param elem Node in a linked list.
 */
char	*str_remove_escapes(char *str)
{
	char	*aux;
	char	*new_str;
	int		i;
	int		escapes;

	escapes = count_escapes(str);
	new_str = ft_calloc(ft_strlen(str) - escapes + 1, sizeof(char));
	if (!new_str)
		return (NULL);
	i = 0;
	aux = str;
	while (*aux)
	{
		if (*aux == '\\')
		{
			aux++;
		}
		new_str[i++] = *aux;
		aux++;
	}
	return (new_str);
}

/**
 * This function removes escape characters from a string in node 
 * in a linked list.
 * 
 * @param elem Node in a linked list.
 */
void	_remove_escapes(t_list *elem)
{
	int		escapes;
	char	*new_str;
	int		i;
	char	*str;

	escapes = count_escapes(elem->content);
	new_str = ft_calloc(ft_strlen(elem->content) - escapes + 1, sizeof(char));
	if (!new_str)
		return ;
	i = 0;
	str = elem->content;
	while (*str)
	{
		if (*str == '\\')
		{
			str++;
		}
		new_str[i++] = *str;
		str++;
	}
	free(elem->content);
	elem->content = new_str;
}

/**
 * Removes escape characters from the content of the elems in a linked list.
 * 
 * @param lst Linked list
 */
void	remove_escapes(t_list **lst)
{
	t_list	*node;
	char	*new_content;

	node = *lst;
	while (node)
	{
		new_content = str_remove_escapes(node->content);
		free(node->content);
		node->content = new_content;
		node = node->next;
	}
}
