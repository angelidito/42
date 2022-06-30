/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 17:01:59 by angmarti          #+#    #+#             */
/*   Updated: 2022/06/29 12:51:42 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
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