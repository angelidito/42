/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 16:57:00 by angmarti          #+#    #+#             */
/*   Updated: 2022/12/16 13:59:01 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

/**
 * It checks if the character is an ASCII character.
 * 
 * @param c The character to be checked.
 * 
 * @return the value of c + 1 if c is between 0 and 127, and 0 otherwise.
 */
int	ft_isascii(int c)
{
	if (0 <= c && c <= 127)
		return (c + 1);
	return (0);
}	
