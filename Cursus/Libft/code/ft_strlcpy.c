/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 18:37:27 by angmarti          #+#    #+#             */
/*   Updated: 2022/07/01 15:42:19 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

#include <stdlib.h>
#include <stdio.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	//printf(" dstsize is '%zu'. ", dstsize);
	i = 0;
	if (0 != dstsize){
		while (i < dstsize - 1 && *(dst + i) != '\0')
		{
			*(dst + i) = *(src + i);
			i++;
		}
		*(dst + i) = '\0';
	}
	return (ft_strlen(src));
}
