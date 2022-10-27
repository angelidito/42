/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_puts_bases_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 15:55:04 by angmarti          #+#    #+#             */
/*   Updated: 2022/10/03 15:51:06 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"

/**
 * It prints the hexadecimal representation of a number to a file descriptor
 * 
 * @param nbr the number to be printed
 * @param fd file descriptor
 * 
 * @return The number of characters printed.
 */
ssize_t	ft_put_ex_fd(size_t nbr, int fd)
{
	char	*base;
	ssize_t	i;

	i = 0;
	base = "0123456789abcdef";
	if (nbr >= 16)
	{
		i += ft_put_ex_fd(nbr / 16, fd);
		nbr %= 16;
	}
	return (i + ft_putchar_fd_ss(base[nbr], fd));
}

/**
 * It writes an integer to a file descriptor
 * 
 * @param nbr the number to print
 * @param fd file descriptor
 * 
 * @return The number of characters printed.
 */
ssize_t	ft_putnbr_fd_ss(int nbr, int fd)
{
	ssize_t	i;

	i = 0;
	if (-2147483648 == nbr)
		return (ft_putstr_fd_ss("-2147483648", fd));
	if (nbr < 0)
	{
		nbr *= -1;
		i = ft_putchar_fd_ss('-', fd);
	}
	if (nbr < 10)
		return (i + ft_putchar_fd_ss('0' + nbr, fd));
	i += ft_putnbr_fd_ss(nbr / 10, fd);
	return (i + ft_putchar_fd_ss('0' + nbr % 10, fd));
}

/**
 * It prints an unsigned long in a given base to a given file descriptor
 * 
 * @param nbr The number to be converted.
 * @param base the base to convert to
 * @param fd file descriptor
 * 
 * @return The number of characters printed.
 */
ssize_t	ft_putnbr_base_fd_simple(unsigned long nbr, char *base, int fd)
{
	size_t			number;
	ssize_t			i;
	unsigned long	b_len;

	i = 0;
	number = (unsigned int)nbr;
	b_len = (unsigned long)ft_strlen(base);
	if (number >= b_len)
	{
		i += ft_putnbr_base_fd_simple(number / b_len, base, fd);
		number %= b_len;
	}
	return (i + ft_putchar_fd_ss(base[number], fd));
}
