/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 15:48:59 by angmarti          #+#    #+#             */
/*   Updated: 2022/09/08 15:02:57 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#define va_arg(ap, type)    __builtin_va_arg(ap, type);

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include "../libft/incs/libft.h"


int		ft_printf(char const *str, ...) __attribute__((format(printf, 1, 2)));
ssize_t	ft_pf_format(char c, va_list args);
ssize_t	ft_putchar_fd_ss(int c, int fd);
ssize_t	ft_putnbr_base_fd(int nbr, char *base, int fd);
ssize_t	ft_putptr_fd(void *ptr, int fd);
ssize_t	ft_putstr_fd_ss(char *s, int fd);

#endif
