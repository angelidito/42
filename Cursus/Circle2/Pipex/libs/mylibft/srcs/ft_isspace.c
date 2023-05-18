/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 14:09:32 by angmarti          #+#    #+#             */
/*   Updated: 2023/04/08 21:20:17 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * It returns 1 if the character is a whitespace, and 0 otherwise.
 * Whitespace can be space, tab, newline, vertical tab, carriage return, or 
 * form feed (" \t\n\v\r\f", respectively).
 * 
 * @param c The character to be checked.
 * 
 * @return 1 if the character is a whitespace. Otherwise, it returns 0.
 */
int	ft_isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\r'
		|| c == '\f');
}
