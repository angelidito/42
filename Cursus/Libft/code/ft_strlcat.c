/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 11:27:30 by angmarti          #+#    #+#             */
/*   Updated: 2022/06/29 12:51:09 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned long	i;
	size_t			src_len;
	size_t			dst_len;

	src_len = 0;
	dst_len = 0;
	while (*(src + src_len) != '\0')
		src_len++;
	while (*(dst + dst_len) != '\0')
		dst_len++;
	if (0 < dstsize && dst_len < dstsize)
	{
		i = 0;
		while (i < dstsize - dst_len - 1)
		{
			*(dst + dst_len + i) = *(src + i);
			i++;
		}
		*(dst + dst_len + i) = '\0';
	}
	return (src_len + dst_len);
}
