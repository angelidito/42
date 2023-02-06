/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 11:27:30 by angmarti          #+#    #+#             */
/*   Updated: 2022/12/16 13:59:01 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

/**
 * It copies the string src to the end of dst, but never more than dstsize - 1 
 * bytes, and then NUL-terminates the result
 * 
 * @param dst The destination string.
 * @param src The string to be appended.
 * @param dstsize The size of the destination buffer.
 * 
 * @return The length of the string that would have been created if there was 
 * enough space.
 */
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dst_len;

	dst_len = ft_strlen(dst);
	if (dstsize < dst_len)
		dst_len = dstsize;
	i = 0;
	while (src[i] && i + dst_len + 1 < dstsize)
	{
		*(dst + dst_len + i) = src[i];
		i++;
	}
	if (i != 0)
		*(dst + dst_len + i) = '\0';
	return (dst_len + ft_strlen(src));
}
