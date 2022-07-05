/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 14:27:54 by angmarti          #+#    #+#             */
/*   Updated: 2022/07/05 14:07:04 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*data;

	i = 0;
	data = (unsigned char *)s;
	while (i < n)
	{
		if (*(data + i) == (unsigned char) c)
			return ((void *)(data + i));
		i++;
	}
	return (NULL);
}
