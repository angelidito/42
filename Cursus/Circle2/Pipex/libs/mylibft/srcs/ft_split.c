/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 13:30:02 by angmarti          #+#    #+#             */
/*   Updated: 2022/12/16 13:59:01 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

/**
 * Count the number of words in a string, where words are separated by a 
 * character
 * 
 * @param s The string to be split.
 * @param c the character to split the string by
 * 
 * @return The number of words in the string.
 */
static int	ft_countwords(char const *s, char c)
{
	size_t	count;
	size_t	i;

	i = 0;
	count = 0;
	if (*s && *s != c)
		count++;
	while (s[++i])
		if (s[i - 1] == c && s[i] != c)
			count++;
	return (count);
}

/**
 * It creates an empty array of strings.
 * 
 * @return A pointer to a pointer to a char.
 */
static char	**ft_emptyarray(void)
{
	char	**emptyarr;

	emptyarr = (char **)ft_calloc(1, sizeof(char *));
	if (!emptyarr)
		return (NULL);
	return (emptyarr);
}

/**
 * It saves a word from a string
 * 
 * @param pts pointer to the string
 * @param auxi a pointer to a pointer to a char.
 * @param c the delimiter
 */
static void	ft_saveword(char **pts, char **auxi, char c)
{
	char	*ptc;

	while (**pts == c)
		(*pts)++;
	ptc = ft_strchr(*pts, c);
	*auxi = ft_substr(*pts, 0, ptc - *pts);
	while (*pts < ptc)
		(*pts)++;
}

/**
 * It takes a string and a character, and returns an array of strings, 
 * each of which is a word from the original string, separated by the character
 * 
 * @param s The string to be split.
 * @param c the character to split on
 * 
 * @return An array of strings.
 */
char	**ft_split(char const *s, char c)
{
	char	**array;
	int		words;
	int		i;

	if (!s || ft_strlen(s) == 0)
		return (ft_emptyarray());
	words = ft_countwords(s, c);
	array = ft_calloc((words + 1), sizeof(char *));
	if (!array)
		return (0);
	i = 0;
	array[words] = NULL;
	while (i < words)
	{
		ft_saveword((char **)&s, &(array[i]), c);
		if (!array[i])
		{
			while (0 < i--)
				free(array[i]);
			free(array);
			return (NULL);
		}
		i++;
	}
	return (array);
}
