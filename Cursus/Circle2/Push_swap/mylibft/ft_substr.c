/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 17:08:44 by angmarti          #+#    #+#             */
/*   Updated: 2022/10/28 14:18:11 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

/**
 * If the string is too short, return an empty string, otherwise return a 
 * substring of the given string.
 * 
 * @param s The string to be split.
 * @param start the index of the first character to include in the substring.
 * @param len the length of the substring to be returned
 * 
 * @return A pointer to a new string.
 */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < (size_t)start)
	{
		sub = malloc(sizeof (char));
		if (!sub)
			return (NULL);
		*sub = '\0';
		return (sub);
	}
	if (ft_strlen(s) - start - 1 < len)
		len = ft_strlen(s) - start;
	sub = malloc((len + 1) * sizeof (char));
	if (!sub)
		return (NULL);
	ft_strlcpy(sub, s + start, len + 1);
	sub[len] = '\0';
	return (sub);
}
