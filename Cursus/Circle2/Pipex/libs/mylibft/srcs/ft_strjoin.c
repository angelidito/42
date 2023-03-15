/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 13:23:27 by angmarti          #+#    #+#             */
/*   Updated: 2023/03/15 18:27:57 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

/**
 * It takes two strings,
 * concatenates them, and returns the result
 * 
 * @param s1 The first string to be joined.
 * @param s2 The string to be appended to the end of s1.
 * 
 * @return A pointer to the first character of the string.
 */
char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*dst;
	size_t		dstsize;

	if (!s1)
		return (NULL);
	dstsize = ft_strlen(s1) + ft_strlen(s2) + 1;
	dst = malloc(dstsize * sizeof (char));
	if (!dst)
		return (NULL);
	ft_strlcpy(dst, s1, dstsize);
	ft_strlcat(dst, s2, dstsize);
	return (dst);
}
