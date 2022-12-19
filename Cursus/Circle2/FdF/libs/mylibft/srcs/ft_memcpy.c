/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 16:33:31 by angmarti          #+#    #+#             */
/*   Updated: 2022/12/16 13:59:01 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

/**
 * Copy n bytes from memory area src to memory area dst
 * 
 * @param dst The destination string where the content is to be copied.
 * @param src The source string.
 * @param n the number of bytes to copy
 * 
 * @return The address of the destination string.
 */
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*d;
	char	*s;

	if (!dst && !src)
		return (dst);
	d = (char *) dst;
	s = (char *) src;
	i = 0;
	while (i < n)
	{
		*(d + i) = *(s + i);
		i++;
	}
	return (dst);
}
