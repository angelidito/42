/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 16:45:31 by angmarti          #+#    #+#             */
/*   Updated: 2022/12/16 13:59:01 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

/**
 * It checks if the character is a digit.
 * 
 * @param c The character to be checked.
 * 
 * @return The character that is being checked.
 */
int	ft_isdigit(int c)
{
	if ('0' <= c && c <= '9')
		return (c);
	return (0);
}
