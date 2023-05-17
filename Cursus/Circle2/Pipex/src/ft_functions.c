/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 17:03:40 by angmarti          #+#    #+#             */
/*   Updated: 2023/05/16 18:14:41 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/pipex.h"

/**
 * It frees an array of strings.
 * 
 * @param chararr The array of strings to be freed.
 */
void	ft_freechararr(char **chararr)
{
	int	i;

	i = -1;
	while (chararr[++i])
		free(chararr[i]);
	free(chararr);
}

/**
 * It joins two strings and frees the memory of the two strings.
 * 
 * @param s1 The first string to be joined.
 * @param s2 the string to be appended to s1
 * 
 * @return A pointer to the newly allocated string.
 */
char	*ft_strjoin_n_free(const char *s1, const char *s2)
{
	char	*result;

	if (!s1)
		return (NULL);
	if (!s2)
	{
		result = ft_strjoin(s1, "");
		free((char *)s1);
		return (result);
	}
	result = ft_strjoin(s1, s2);
	free((char *)s1);
	free((char *)s2);
	return (result);
}

/**
 * It joins two strings and frees the memory of the strings if the flag is set.
 * 
 * @param s1 The first string to join.
 * @param s2 The string to be appended to s1.
 * @param f1 if not 0, free s1
 * @param f2 if not 0, free s2
 * 
 * @return A pointer to a string, NULL if it fails.
 */
char	*ft_strjoin_n_free_op(const char *s1, const char *s2, int f1, int f2)
{
	char	*result;

	if (!s1)
		return (NULL);
	if (!s2)
	{
		result = ft_strjoin(s1, "");
		free((char *)s1);
		return (result);
	}
	result = ft_strjoin(s1, s2);
	if (f1)
		free((char *)s1);
	if (f2)
		free((char *)s2);
	return (result);
}
