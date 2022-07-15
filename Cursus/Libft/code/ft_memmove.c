/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 17:01:59 by angmarti          #+#    #+#             */
/*   Updated: 2022/07/14 17:04:17 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
