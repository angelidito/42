/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 16:12:22 by angmarti          #+#    #+#             */
/*   Updated: 2022/12/16 13:59:01 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

/**
 * Ft_bzero() takes a pointer to a memory area and a size, and sets all bytes 
 * to zero
 * 
 * @param s This is the pointer to the memory area to be filled.
 * @param n The number of bytes to be set to zero.
 */
void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;

	p = (unsigned char *) s;
	while (0 < n--)
		*p++ = 0;
}
