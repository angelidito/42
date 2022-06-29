/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 14:37:17 by angmarti          #+#    #+#             */
/*   Updated: 2022/06/29 14:43:44 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while(i < n)
	{
		if ((unsigned char) *(s1 + i) != (unsigned char) *(s2 + i))
			return ((unsigned char) *(s1 + i) - (unsigned char) *(s2 + i));
		else
			i++;
	}
	return (0);
}
