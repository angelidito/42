/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 13:13:25 by angmarti          #+#    #+#             */
/*   Updated: 2022/10/26 11:32:27 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"
#include <stdlib.h>

	// printf("%s", get_next_line(1000));
	// printf("%s", get_next_line(-1));
	// close(fd);
	// printf("%s", get_next_line(fd));

int	main(int argc, char const *argv[])
{
	int		fd;
	int		i;
	int		j;

	if (argc > 1)
	{
		j = atoi(argv[1]);
		if (argc > 2)
			fd = open(argv[2], O_RDONLY);
	}
	else
	{
		fd = open("prueba", O_RDONLY);
		j = 5;
	}
	i = 0;
	while (++i <= j)
		printf("%s", get_next_line(fd));
	return (0);
}
