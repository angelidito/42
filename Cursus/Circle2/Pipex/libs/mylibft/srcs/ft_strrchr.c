/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 13:34:46 by angmarti          #+#    #+#             */
/*   Updated: 2022/12/16 13:59:01 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

/**
 * It returns a pointer to the last occurrence of the character c in the 
 * string s.
 * 
 * @param s The string to search.
 * @param c The character to search for.
 * 
 * @return A pointer to the last occurrence of the character c in the string s.
 */
char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = ft_strlen(s);
	if (!c)
		return ((char *) s + i);
	while (i-- > 0)
	{
		if (s[i] == (unsigned char)c)
			return ((char *) s + i);
	}
	return (NULL);
}
