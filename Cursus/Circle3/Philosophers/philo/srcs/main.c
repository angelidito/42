/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 19:52:51 by angmarti          #+#    #+#             */
/*   Updated: 2023/07/19 20:00:00 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philosophers.h"
#include <fcntl.h>

int	main(int argc, char const *argv[])
{
	t_table	table;
	int		i;

	if (0 && argc != 5 && argc != 6)
	{
		printf("Error: wrong number of arguments\n");
		return (1);
	}
	if (init_table(&table, argc, argv))
		return (1);
	printf("Table initialized.\n");
	printf("Philosophers: %d\n", table.args.n_philos);
	printf("Time to sleep: %d\n", table.args.time_to_sleep);
	printf("Time to eat: %d\n", table.args.time_to_eat);
	printf("Time to sleep + eat: %d\n", table.args.time_to_eat
			+ table.args.time_to_sleep);
	printf("Time to die: %d\n", table.args.time_to_die);
	printf("Times must eat: %d\n", table.args.n_times_must_eat);
	// table.fd_out = open("out.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	// dup2(table.fd_out, 1);
	i = -1;
	// Lanzamos filosofos
	printf("Launching philosophers.\n");
	while (++i < table.args.n_philos)
		pthread_create(&table.philos[i].thread, NULL, start, &table.philos[i]);
	i = -1;
	while (++i < table.args.n_philos)
		pthread_join(table.philos[i].thread, NULL);
	printf("Main end.\n");
	return (0);
}
