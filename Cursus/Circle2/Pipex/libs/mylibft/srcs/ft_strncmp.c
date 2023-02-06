/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 13:46:57 by angmarti          #+#    #+#             */
/*   Updated: 2022/12/16 13:59:01 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

/**
 * It compares two characters and returns the difference between them.
 * 
 * @param c1 The first character to compare.
 * @param c2 The character to search for.
 * 
 * @return The difference between the two characters.
 */
static int	ft_chrcmp(unsigned char c1, unsigned char c2)
{
	return (c1 - c2);
}

/**
 * It compares the first n characters of two strings, and returns the 
 * difference between the first two characters that differ
 * 
 * @param s1 The first string to be compared.
 * @param s2 The string to compare to.
 * @param n The maximum number of characters to compare.
 * 
 * @return The difference between the first two characters that differ in the 
 * strings being compared.
 */
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (ft_chrcmp(s1[i], s2[i]))
			return (ft_chrcmp(s1[i], s2[i]));
		else if (!*(s1 + i))
			return (0 - s2[i]);
		else if (!*(s2 + i))
			return (s1[i]);
		else
			i++;
	}
	return (0);
}
