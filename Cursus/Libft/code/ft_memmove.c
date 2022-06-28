/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 17:01:59 by angmarti          #+#    #+#             */
/*   Updated: 2022/06/28 18:35:21 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*memmove(void *dst, const void *src, size_t len)
{
	unsigned long	i;
	char			*d;
	char			*s;

	if (dst == NULL && src == NULL)
		return (dst);
	d = (char *) dst;
	s = (char *) src;
	i = 0;
	if (s < d)
		while (0 < len--)
			*(d + len) = *(s + len);
	else
	{
		while (i < len)
		{
			*(d + i) = *(s + i);
			i++;
		}
	}
	return (dst);
}
