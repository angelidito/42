/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 14:44:03 by angmarti          #+#    #+#             */
/*   Updated: 2022/12/16 13:59:01 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

/**
 * If the needle is empty, return the haystack. If the haystack is empty, 
 * return NULL. If the needle is found in the haystack, return the address of 
 * the first character of the needle in the haystack. If the needle is not 
 * found in the haystack, return NULL
 * 
 * @param haystack The string to search in
 * @param needle the string to find
 * @param len the maximum number of characters to search in haystack
 * 
 * @return A pointer to the first occurrence of the substring needle in the 
 * string haystack, or a null pointer if the substring is not found.
 */
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	matches;

	i = 0;
	matches = 0;
	if (!*needle)
		return ((char *)haystack);
	if (!len)
		return (NULL);
	while (*(haystack + i) && i < len)
	{
		matches = 0;
		while (*(needle + matches) && needle[matches] == haystack[i + matches]
			&& i + matches < len)
			matches++;
		if (!needle[matches])
			return ((char *)haystack + i);
		i++;
	}
	return (NULL);
}
