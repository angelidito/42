/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 12:56:37 by angmarti          #+#    #+#             */
/*   Updated: 2022/12/16 13:59:01 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

/**
 * If the character is uppercase, add 32 to it to make it lowercase
 * 
 * @param c The character to be converted.
 * 
 * @return the lowercase equivalent of the character passed as an argument, 
 * if the argument is a uppercase letter.
 */
int	ft_tolower(int c)
{
	if ('A' <= c && c <= 'Z')
		c = c + 32;
	return (c);
}
