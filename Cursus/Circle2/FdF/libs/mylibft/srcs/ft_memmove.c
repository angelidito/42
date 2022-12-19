/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 17:01:59 by angmarti          #+#    #+#             */
/*   Updated: 2022/12/16 13:59:01 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

/**
 * If the source and destination overlap, copy the source backwards
 * 
 * @param dst The destination string.
 * @param src The source string.
 * @param len The number of bytes to be moved.
 * 
 * @return A pointer to the destination string.
 */
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned long	i;
	char			*d;
	const char		*s;

	if (!len || (!dst && !src))
		return (dst);
	d = (char *) dst;
	s = (const char *) src;
	if (s < d)
		while (0 < len--)
			*(d + len) = *(s + len);
	else
	{
		i = 0;
		while (i < len)
		{
			*(d++) = *(s++);
			i++;
		}
	}
	return (dst);
}
