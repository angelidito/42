/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 14:44:03 by angmarti          #+#    #+#             */
/*   Updated: 2022/07/05 14:01:29 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
