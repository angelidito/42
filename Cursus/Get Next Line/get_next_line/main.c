/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 13:13:25 by angmarti          #+#    #+#             */
/*   Updated: 2022/10/06 19:08:43 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
void check_leaks();

int	main(void)
{
	check_leaks();
	int	fd;
	int	i;

	// if (!argc)
	// 	fd = open(*argv, O_RDONLY);
	// else
		fd = open("prueba2", O_RDONLY);
	i = 0;
	// while (i++ <= 10)
		// printf("%s", get_next_line(1000));
		// printf("%s", get_next_line(-1));
		// close(fd);
		printf("%d", get_next_line(fd) ? 1 : 0);
		printf("%d", get_next_line(fd) ? 1 : 0);
		
		// printf("%s", get_next_line(fd));

	check_leaks();
	return (0);
}
