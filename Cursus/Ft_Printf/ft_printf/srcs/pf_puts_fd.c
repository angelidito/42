/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putcharstr_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 15:55:04 by angmarti          #+#    #+#             */
/*   Updated: 2022/09/08 14:00:59 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"

/**
 * It writes a string to a file descriptor.
 * 
 * @param s The string to be printed.
 * @param fd file descriptor
 * 
 * @return The number of bytes written.
 */
ssize_t	ft_putstr_fd_ss(char *s, int fd)
{
	if (!s)
		return (0);
	return (write(fd, s, ft_strlen(s) * sizeof(char)));
}

/**
 * Write a single character to a file descriptor
 * 
 * @param c the character to print
 * @param fd file descriptor
 * 
 * @return The number of bytes written.
 */
ssize_t	ft_putchar_fd_ss(int c, int fd)
{
	return (write(fd, &c, sizeof(char)));
}

// TODO
ssize_t	ft_putptr_fd(void *ptr, int fd)
{
	size_t	nbr;
	ssize_t	len;

	nbr = (size_t)ptr;
	len = write(1, "0x", 2 * sizeof(char));
	if (len == -1)
		return (-1);
	len += ft_putnbr_base_fd(nbr, "0123456789abcdef", fd);
	return (len);
}
