/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 14:14:08 by angmarti          #+#    #+#             */
/*   Updated: 2022/08/31 15:44:44 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Write the character c to the file descriptor fd
 * 
 * @param c the character to print
 * @param fd file descriptor
 */
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, sizeof(char));
}
