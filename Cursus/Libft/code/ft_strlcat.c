/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 11:27:30 by angmarti          #+#    #+#             */
/*   Updated: 2022/07/04 11:33:25 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned long	i;
	size_t			src_len;
	size_t			dst_len;

	//printf("\ndstize: %zu\ndst: %s\nsrc: %s\n", dstsize, dst, src);
	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	if (0 < dstsize && dst_len < dstsize)
	{
		i = 0;
		while (i < dstsize - dst_len - 1 && i < src_len)
		{
			*(dst + dst_len + i) = *(src + i);
			i++;
		}
		*(dst + dst_len + i) = '\0';
	}
	//printf("Obtained: %zu + %zu = %zu\ndst: %s\n\n", dst_len, src_len, src_len + dst_len, dst);
	return (src_len + dst_len);
}
