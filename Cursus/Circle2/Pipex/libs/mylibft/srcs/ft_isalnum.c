/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 16:48:55 by angmarti          #+#    #+#             */
/*   Updated: 2022/12/16 13:59:01 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

/**
 * If the character is a number or a letter, return the character
 * 
 * @param c The character to be checked.
 * 
 * @return The character that is being checked.
 */
int	ft_isalnum(int c)
{
	if ('0' <= c && c <= '9')
		return (c);
	if ('A' <= c && c <= 'Z')
		return (c);
	if ('a' <= c && c <= 'z')
		return (c);
	return (0);
}
