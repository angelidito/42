/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 19:30:40 by angmarti          #+#    #+#             */
/*   Updated: 2022/09/02 12:38:12 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"

//	External functions: 
//		malloc
//		free
//		write
//		va_start
//		va_arg
//		va_copy
//		va_end

//	Libft authorized: yes

ssize_t	ft_pf_format(char *ptr, va_list args)
{
	ssize_t printed;

	printed = 0;
	printf("%c", va_arg(args, char));
	if (*ptr == 'c')
	;
		// printed = write(1, *va_arg(args, char), sizeof(char));
		// printed = ft_putchar_fd_ss(va_arg(args, char), 1);
	if (*ptr == 'd' || *ptr == 'i')
		printed = ft_putstr_fd_ss(ft_itoa(va_arg(args, int)), 1);
	// if (*str == 'p')
	// 	printed = ft_putptr_fd(va_arg(args, void *), 1);
	if (*ptr == 's')
		printed = ft_putstr_fd_ss(va_arg(args, char *), 1);
	if (*ptr == 'u')
		printed = ft_putnbr_base_fd(va_arg(args, int), "01234567", 1);
	if (*ptr == 'x')
		printed = ft_putnbr_base_fd(va_arg(args, int), "0123456789abcdef", 1);
	if (*ptr == 'X')
		printed = ft_putnbr_base_fd(va_arg(args, int), "0123456789ABCDEF", 1);
	return (printed);
}

int	ft_printf(char const *str, ...)
{
	size_t	i;
	ssize_t	chr_printed;
	ssize_t	n_aux;
	va_list	args;

	i = 0;
	chr_printed = 0;
	va_start(args, str); // va_start(args, str);
	while (str[i])
	{
		if (str[i] != '%' || str[i + 1] == '%')
			n_aux = write(1, str + i, sizeof(char));
		else
			n_aux = ft_pf_format((char *)(str + ++i), args);
		i++;
		if (n_aux == -1)
			return (-1);
		chr_printed += n_aux;
	}
	return (chr_printed);
}
