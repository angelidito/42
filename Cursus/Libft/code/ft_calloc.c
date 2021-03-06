/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 18:58:20 by angmarti          #+#    #+#             */
/*   Updated: 2022/07/15 13:23:08 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
	ptr = malloc(len);
	if (!ptr || ptr == NULL)
		return (NULL);
	ft_bzero(ptr, len);
	return (ptr);
}
