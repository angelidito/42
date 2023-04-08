/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 14:00:17 by angmarti          #+#    #+#             */
/*   Updated: 2023/04/06 19:10:13 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

/**
 * It finds the first or last position in a string that is not in a set of 
 * characters
 * 
 * @param s1 The string to be trimmed.
 * @param set the set of characters to trim
 * @param last 0 for the first trim, 1 for the last trim
 * 
 * @return The position of the first character that is not in the set.
 */
static size_t	ft_findtrimpos(char const *s1, char const *set, int last)
{
	size_t	i;
	size_t	j;
	size_t	match;

	i = 0;
	if (last != 0)
	{
		last = 1;
		i = ft_strlen(s1) - 1;
	}
	while ((s1[i] && !last) || (0 <= i && last))
	{
		match = 0;
		j = 0;
		while (set[j])
			if (s1[i] == set[j++])
				match++;
		if (!match)
			return (i);
		if (i || !last)
			i = i + 1 - 2 * last;
		else
			last = 0;
	}
	return (ft_strlen(s1));
}

/**
 * It returns a copy of the string s1, with all the characters in the string 
 * set removed from the beginning and end of s1
 * 
 * @param s1 the string to be trimmed
 * @param set the set of characters to trim
 * 
 * @return A pointer to a new string.
 */
char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s0;
	size_t	a;
	size_t	z;
	size_t	i;

	if (!s1)
		return (NULL);
	a = ft_findtrimpos(s1, set, 0);
	z = ft_findtrimpos(s1, set, 1);
	if (a >= ft_strlen(s1) || z >= ft_strlen(s1) || z < a)
	{
		s0 = (char *)malloc(1);
		if (!s0)
			return (NULL);
		s0[0] = '\0';
		return (s0);
	}
	s0 = malloc((z - a + 2) * sizeof (char));
	if (!s0)
		return (NULL);
	i = 0;
	while (a <= z)
		*(s0 + i++) = *(s1 + a++);
	s0[i] = '\0';
	return (s0);
}
