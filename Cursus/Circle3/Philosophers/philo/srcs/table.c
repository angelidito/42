/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 21:48:28 by angmarti          #+#    #+#             */
/*   Updated: 2023/07/15 21:53:05 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philosophers.h"

int	init_table(t_table *table, int argc, char const *argv[])
{
	int	i;

	if (argc < 5 || argc > 6)
	{
		printf("Error: wrong number of arguments: %d.\n", argc - 1);
		return (-1);
	}
	table->args.n_philos = ft_atoi(argv[1]);
	if (table->args.n_philos < 1)
	{
		printf("Error: wrong number of philosophers: %d\n.", table->args.n_philos);
		return (-1);
	}
	table->args.time_to_die = ft_atoi(argv[2]);
	table->args.time_to_eat = ft_atoi(argv[3]);
	table->args.time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		table->args.n_times_must_eat = ft_atoi(argv[5]);
	table->forks = malloc(sizeof(pthread_mutex_t) * table->args.n_philos);
	if (!table->forks)
	{
		printf("Error: malloc failed\n");
		return (-1);
	}
	i = -1;
	while (++i < table->args.n_philos)
		pthread_mutex_init(&table->forks[i], NULL);
	pthread_mutex_init(&table->print_mutex, NULL);
	table->philos = malloc(sizeof(t_philo) * table->args.n_philos);
	if (!table->philos)
	{
		printf("Error: malloc failed\n");
		return (-1);
	}
	i = -1;
	while (++i < table->args.n_philos)
	{
		table->philos[i].id = i + 1;
		table->philos[i].is_eating = 0;
		table->philos[i].times_eaten = 0;
		table->philos[i].left_fork = &table->forks[i];
		table->philos[i].right_fork = &table->forks[(i + 1) % table->args.n_philos];
		table->philos[i].print_mutex = &table->print_mutex;
		table->philos[i].args = &table->args;
	}
	return (0);
}
