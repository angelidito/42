/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 13:00:37 by angmarti          #+#    #+#             */
/*   Updated: 2022/12/16 13:59:01 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

/**
 * It returns a pointer to the first occurrence of the character c in the 
 * string s
 * 
 * @param s The string to search.
 * @param c The character to search for.
 * 
 * @return A pointer to the first occurrence of the character c in the 
 * string s.
 */
char	*ft_strchr(const char *s, int c)
{
	unsigned long	i;

	i = 0;
	while (*(s + i))
	{
		if ((c % 256) == *(s + i))
			break ;
		i++;
	}
	if ((c % 256) == *(s + i))
		return ((char *)(s + i));
	return (NULL);
}
