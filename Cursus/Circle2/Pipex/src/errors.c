/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 16:42:37 by angmarti          #+#    #+#             */
/*   Updated: 2023/05/17 14:47:56 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/pipex.h"

/**
 * It prints the error message associated with the last system call, 
 * and then exits the program
 * 
 * @param s The string to print.
 */
void	my_perror(char *s)
{
	perror(s);
	exit(EXIT_FAILURE);
}

/**
 * The function prints a given string to the standard error output in red color.
 * 
 * @param str String that will be printed to the standard error output (stderr).
 */
void	print_stderr(char *str)
{
	ft_putstr_fd(TEXT_RED, STDERR_FILENO);
	ft_putstr_fd(str, STDERR_FILENO);
	ft_putstr_fd(TEXT_RESET, STDERR_FILENO);
}

/**
 * Prints a given string in red and exits the program with a failure status.
 * 
 * @param s the error message to be printed
 */
void	pf_exit(char *s, int fd)
{
	if (fd == STDERR_FILENO)
	{
		print_stderr(s);
		print_stderr("\n");
	}
	else
	{
		ft_putstr_fd(s, fd);
		ft_putstr_fd("\n", fd);
	}
	exit(EXIT_FAILURE);
}


