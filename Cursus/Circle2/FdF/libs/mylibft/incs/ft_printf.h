/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 15:48:59 by angmarti          #+#    #+#             */
/*   Updated: 2022/12/16 14:15:55 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include "libft.h"

int		ft_printf(char const *str, ...);

ssize_t	ft_pf_format(char c, va_list args);
ssize_t	ft_putchar_fd_ss(int c, int fd);
ssize_t	ft_putnbr_fd_ss(int nbr, int fd);
ssize_t	ft_putnbr_base_fd_simple(unsigned long nbr, char *base, int fd);
ssize_t	ft_putptr_fd(void *ptr, int fd);
ssize_t	ft_putstr_fd_ss(char *s, int fd);
ssize_t	ft_put_ex_fd(size_t nbr, int fd);

#endif
