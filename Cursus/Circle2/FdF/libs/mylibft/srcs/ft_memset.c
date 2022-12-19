/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 17:09:31 by angmarti          #+#    #+#             */
/*   Updated: 2022/12/16 13:59:01 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

/**
 * Ft_memset() takes a pointer to a memory area, a byte value, and a size, and 
 * fills the memory area with the given byte value
 * 
 * @param b This is the pointer to the memory area to be filled.
 * @param c the character to fill the memory with
 * @param len the number of bytes to fill
 * 
 * @return The address of the first byte of the memory area b.
 */
void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*s;

	s = (unsigned char *) b;
	i = 0;
	while (i < len)
		*(s + i++) = c;
	return (b);
}
