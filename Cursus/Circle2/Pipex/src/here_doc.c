/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 19:44:51 by angmarti          #+#    #+#             */
/*   Updated: 2023/05/23 16:16:59 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/pipex.h"

void	print_heredoc(int n_comands)
{
	int	i;

	i = 0;
	while (i < n_comands)
	{
		ft_putstr_fd("pipe ", STDOUT_FILENO);
		i++;
	}
	ft_putstr_fd("heredoc> ", STDOUT_FILENO);
}

/**
 * Reads input from the user until a specified delimiter is reached and writes 
 * it to a temporary file.
 * 
 * @param limiterString that specifies the delimiter for the here document.
 * @param n_comands Number of commands passed to the program.
 * 
 */
void	heredoc(char *limiter, int n_comands)
{
	int		fd;
	int		lim_len;
	int		l_len;
	char	*l;

	fd = open(TEMP_HERE_DOC, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (fd == -1)
		pf_exit("Error opening file", 1);
	lim_len = ft_strlen(limiter);
	print_heredoc(n_comands);
	l = get_next_line(STDIN_FILENO);
	l_len = ft_strlen(l) - 1;
	while (l_len != lim_len || ft_strncmp(l, limiter, ft_strlen(limiter)))
	{
		ft_putstr_fd(l, fd);
		free(l);
		print_heredoc(n_comands);
		l = get_next_line(STDIN_FILENO);
		l_len = ft_strlen(l) - 1;
	}
	close(fd);
}
