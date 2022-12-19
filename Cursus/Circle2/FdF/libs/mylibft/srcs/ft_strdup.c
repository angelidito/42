/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 16:31:37 by angmarti          #+#    #+#             */
/*   Updated: 2022/12/16 13:59:01 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

/**
 * It allocates a new string, copies the contents of the string passed 
 * as argument into it, and returns a pointer to the new string
 * 
 * @param s1 The string to copy.
 * 
 * @return A pointer to a new string.
 */
char	*ft_strdup(const char *s1)
{
	char	*s;
	size_t	len;

	len = ft_strlen(s1) + 1;
	s = malloc(len * sizeof (char));
	if (!s)
		return (NULL);
	ft_strlcpy(s, s1, len);
	return (s);
}
