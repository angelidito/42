/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 13:00:37 by angmarti          #+#    #+#             */
/*   Updated: 2022/07/05 14:04:26 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strchr(const char *s, int c)
{
	unsigned long	i;

	i = 0;
	while (*(s + i))
	{
		if ((c % 256) == *(s + i))
			break ;
		i++;
	}
	if ((c % 256) == *(s + i))
		return ((char *)(s + i));
	return (NULL);
}
