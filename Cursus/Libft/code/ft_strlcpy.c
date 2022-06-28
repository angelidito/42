/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 18:37:27 by angmarti          #+#    #+#             */
/*   Updated: 2022/06/28 19:18:10 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	strlcpy(char *dst, const char *src, size_t dstsize)
{
	unsigned long	i;
	size_t			src_length;

	i = 0;
	while (*(src + src_length) != '\0')
		src_lenght++;
	if (0 < dstsize)
	{
		while (i < dstsize - 1)
		{
			*(dst + i) = *(src + i);
			i++;
		}
		*(dst + i) = '\0';
	}
	return (src_length);
}
