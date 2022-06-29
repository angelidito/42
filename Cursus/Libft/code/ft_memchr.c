/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 14:27:54 by angmarti          #+#    #+#             */
/*   Updated: 2022/06/29 14:36:29 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	void	*p;

	p = NULL;
	i = 0;
	while (p == NULL && i < n)
	{
		if((unsigned char) *(s + i) == (unsigned char) c)
			p = s + i;
	}
	return (p);
}
