/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 14:44:03 by angmarti          #+#    #+#             */
/*   Updated: 2022/06/29 15:23:44 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned long	i;
	size_t			matches;
	char			*p;

	p = NULL;
	i = 0;
	matches = 0;
	while ( *(haystack + i) && *(needle + matches) && matches < len)
	{
		if (*(haystack + i) == *(needle + matches))
		{
			if (p == NULL)
				p = (haystack + i);
			matches++;
		}
		else
		{
			matches = 0;
			p = NULL;
		}
		i++;
	}
	if (matches < len && *(needle + matches) != '\0')
			p = NULL;
	return (p);
}
