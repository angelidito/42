/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_not_escaped.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 13:30:02 by angmarti          #+#    #+#             */
/*   Updated: 2023/05/15 14:58:10 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/pipex.h"

/**
 * The function counts the number of escaped characters in a given string 
 * between two indices.
 * 
 * @param str String to check.
 * @param start Index of the first character to check.
 * @param end Index of the last character to check.
 * @param c Character to check.
 * 
 * @return int Number of times the character `c` is escaped.
 */
int	count_escaped_chars(char const *str, int start, int end, char c)
{
	int	count;

	count = 0;
	while (start < end)
	{
		if (str[start] == '\\' && str[start + 1] == c)
		{
			count++;
			start++;
		}
		else
			start++;
	}
	return (count);
}

/**
 * Returns a copy of a given string with removed escape characters 
 * for a specific character.
 * 
 * @param str String to be copied 
 * @param start Starting index
 * @param end Last index
 * @param c Character that is used to identify escape sequences in the string
 * 
 * @return A copy that not includes any escape sequences for the character `c`.
 */
char	*get_strcpy_no_c_escapes(char const *str, int start, int end, char c)
{
	char	*cpy;
	int		i;
	int		escaped_chars;

	if (start >= end)
		ft_printf("Error: start == end\n");
	i = -1;
	escaped_chars = count_escaped_chars(str, start, end, c);
	cpy = ft_calloc(sizeof(char), end - start + 1 - escaped_chars);
	if (!cpy)
		return (NULL);
	i = 0;
	while (start < end)
	{
		if (str[start] == '\\' && str[start + 1] == c)
			start++;
		cpy[i++] = str[start];
		start++;
	}
	return (cpy);
}

/**
 * Counts the number of words in a string that are not escaped by 
 * a given character.
 * 
 * @param s String we want to count words in.
 * @param c Character that separates the words in the string.
 * @param str_len The length of the string `s`.
 * 
 * @return The number of words in the string `s`.
 */
int	count_words_not_escaped(char const *s, char c, int str_len)
{
	int	start;
	int	end;
	int	words;

	words = 0;
	start = -1;
	while (++start < str_len)
	{
		end = start;
		while (end < str_len)
		{
			if (s[end] == '\\' && s[end + 1] == c)
				end++;
			else if (s[end] == c)
				break ;
			end++;
		}
		if (start < str_len)
			words++;
		start = end;
	}
	return (words);
}

/**
 * Splits a string into words based on a given delimiter and stores them in 
 * an array of strings.
 * 
 * @param words Array of strings to store the words.
 * @param s String to be splited.
 * @param c Delimiter character.
 * @param str_len The length of the string `s`.
 */
void	set_words(char **wordarr, char const *s, char c, int str_len)
{
	int	start;
	int	end;
	int	i;

	start = -1;
	i = 0;
	while (++start < str_len)
	{
		end = start;
		while (end < str_len)
		{
			if (s[end] == '\\' && s[end + 1] == c)
				end++;
			else if (s[end] == c)
				break ;
			end++;
		}
		if (start < str_len && start < end)
			wordarr[i++] = get_strcpy_no_c_escapes(s, start, end, c);
		start = end;
	}
}

/**
 * Splits a string into an array of substrings based on a delimiter character,
 * while ignoring escaped instances of the delimiter.
 * 
 * @param s String to be splite
 * @param c Delimiter character.
 * 
 * @return An array of strings
 */
char	**ft_split_not_escaped(char const *s, char c)
{
	char	**array;
	int		words;
	int		str_len;

	words = 0;
	str_len = (int)ft_strlen(s);
	array = ft_calloc(sizeof(char *), 1);
	words = count_words_not_escaped(s, c, str_len);
	array = ft_calloc(sizeof(char *), words + 1);
	if (!array)
		return (NULL);
	set_words(array, s, c, str_len);
	return (array);
}
