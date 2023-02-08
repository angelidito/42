/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 18:58:20 by angmarti          #+#    #+#             */
/*   Updated: 2023/02/08 15:03:58 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

/**
 * It allocates memory for a given size and sets it to zero.
 * 
 * @param count The number of elements to be allocated.
 * @param size The size of the memory block, in bytes.
 * 
 * @return A pointer to the allocated memory.
 */
void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	len;

	if (count == SIZE_MAX || size == SIZE_MAX)
		return (NULL);
	if (!count || !size)
		len = 1;
	else
		len = count * size;
	if (len < count && len < size)
		return (NULL);
	ptr = malloc(len);
	if (!ptr || ptr == NULL)
		return (NULL);
	ft_bzero(ptr, len);
	return (ptr);
}
