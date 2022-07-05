/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 11:27:30 by angmarti          #+#    #+#             */
/*   Updated: 2022/07/05 13:12:07 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
