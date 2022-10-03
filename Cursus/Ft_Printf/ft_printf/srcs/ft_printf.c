/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 19:30:40 by angmarti          #+#    #+#             */
/*   Updated: 2022/10/03 15:28:17 by angmarti         ###   ########.fr       */
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
		printed = ft_putchar_fd_ss(37, 1);
	else if (c == 'c')
		printed = ft_putchar_fd_ss(va_arg(args, int), 1);
	else if (c == 'd' || c == 'i')
		printed = ft_putnbr_fd_ss(va_arg(args, int), 1);
	else if (c == 'p')
		printed = ft_putptr_fd(va_arg(args, void *), 1);
	else if (c == 's')
		printed = ft_putstr_fd_ss(va_arg(args, char *), 1);
	else if (c == 'u')
		printed = ft_putnbr_base_fd_simple(va_arg(args, unsigned int),
				"0123456789", 1);
	else if (c == 'x')
		printed = ft_putnbr_base_fd_simple(va_arg(args, int),
				"0123456789abcdef", 1);
	else if (c == 'X')
		printed = ft_putnbr_base_fd_simple(va_arg(args, int),
				"0123456789ABCDEF", 1);
	else
		printed = ft_putstr_fd_ss(va_arg(args, char *), 1);
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
		if (str[i] == '%')
		{
			n_aux = ft_pf_format(str[i + 1], args);
			i++;
		}
		else
			n_aux = write(1, str + i, sizeof(char));
		i++;
		if (n_aux == -1)
			return (-1);
		chr_printed += n_aux;
	}
	return (chr_printed);
}
