/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 17:05:23 by angmarti          #+#    #+#             */
/*   Updated: 2022/12/16 13:59:01 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

/**
 * If the character is between a space and a tilde, return the character. 
 * Otherwise, return 0
 * 
 * @param c The character to be checked.
 * 
 * @return The character if it is printable, otherwise 0.
 */
int	ft_isprint(int c)
{
	if (' ' <= c && c <= '~')
		return (c);
	return (0);
}
