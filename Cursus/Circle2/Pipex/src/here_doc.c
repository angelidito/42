/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 19:44:51 by angmarti          #+#    #+#             */
/*   Updated: 2023/05/18 20:17:47 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/pipex.h"

int	heredoc(char *limiter)
{
	int fd;
	char *line;

	fd = open(TEMP_HERE_DOC, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (fd == -1)
		pf_exit("Error opening file", 1);
	line = get_next_line(STDIN_FILENO);
	while (ft_strncmp(line, limiter, ft_strlen(limiter)))
	{
		ft_putstr_fd(line, fd);
		free(line);
		line = get_next_line(STDIN_FILENO);
	}
	close(fd);
	return (0);
}
