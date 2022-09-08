/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 19:30:40 by angmarti          #+#    #+#             */
/*   Updated: 2022/09/08 15:53:18 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"

/**
 * It takes a format character and a va_list, and returns the number of 
 * characters printed
 * 
 * @param c character
 * @param args the va_list that contains the arguments to be printed
 * 
 * @return The number of characters printed.
 */
ssize_t	ft_pf_format(char c, va_list args)
{
	ssize_t	printed;

	printed = 0;
	if (c == '%')
		printed = ft_putchar_fd_ss('%', 1);
	if (c == 'c')
		printed = ft_putchar_fd_ss(va_arg(args, int), 1);
	else if (c == 'd' || c == 'i')
		printed = ft_putstr_fd_ss(ft_itoa(va_arg(args, int)), 1);
	else if (c == 'p')
		printed = ft_putptr_fd(va_arg(args, void *), 1);
	else if (c == 's')
		printed = ft_putstr_fd_ss(va_arg(args, char *), 1);
	else if (c == 'u')
		printed = ft_putnbr_base_fd(va_arg(args, int), "01234567", 1);
	else if (c == 'x')
		printed = ft_putnbr_base_fd(va_arg(args, int), "0123456789abcdef", 1);
	else if (c == 'X')
		printed = ft_putnbr_base_fd(va_arg(args, int), "0123456789ABCDEF", 1);
	else
		printed += ft_putstr_fd_ss(va_arg(args, char *), 1);
	return (printed);
}

/**
 * It takes a string and a variable number of arguments, and prints the string 
 * with the arguments formatted in the string
 * 
 * @param str The format string.
 * 
 * @return The number of characters printed.
 */
int	ft_printf(char const *str, ...)
{
	va_list	args;
	ssize_t	chr_printed;
	size_t	i;
	ssize_t	n_aux;

	i = 0;
	chr_printed = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] != '%' || str[i + 1] == '%')
			n_aux = write(1, str + i, sizeof(char));
		else
			n_aux = ft_pf_format(str[++i], args);
		i++;
		if (n_aux == -1)
			return (-1);
		chr_printed += n_aux;
	}
	return (chr_printed);
}


// category: c OK 
// category: s
// 10.KO 
// category: p
// 1.KO 6.KO 7.KO 8.KO
// category: d
// LEAKS.KO 
// category: i
// LEAKS.KO 
// category: u
// 2.KO 4.KO 5.KO 6.KO 7.KO 8.KO 9.KO 10.KO 11.KO 12.KO 13.KO 14.KO 15.KO 16.KO 17.KO 18.KO 19.KO 20.KO 21.KO 22.KO 23.KO 24.KO 26.KO 27.KO 28.KO 29.KO 
// category: x
// 2.KO 13.KO 14.KO 15.KO 16.KO 17.KO 18.KO 19.KO 20.KO 21.KO 23.KO 24.KO 26.KO 27.KO 28.KO 29.KO 31.KO 
// category: X
// 2.KO 13.KO 14.KO 15.KO 16.KO 17.KO 18.KO 19.KO 20.KO 21.KO 23.KO 24.KO 26.KO 27.KO 28.KO 29.KO 31.KO 
// category: %
// 1.KO 2.KO 3.KO 4.KO 5.KO 6.KO 7.KO 
// category: mix 
// 1.KO LEAKS.KO 

