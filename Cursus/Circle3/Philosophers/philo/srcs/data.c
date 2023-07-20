/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 21:48:28 by angmarti          #+#    #+#             */
/*   Updated: 2023/07/20 16:36:40 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philosophers.h"

int	init_data(t_data *data, int argc, char const *argv[])
{
	int	i;

	// ARGUMENTS
	if (argc < 5 || argc > 6)
	{
		printf("Error: wrong number of arguments: %d.\n", argc - 1);
		return (-1);
	}
	data->args.n_philos = ft_atoi(argv[1]);
	if (data->args.n_philos < 1)
	{
		printf("Error: wrong number of philosophers: %d\n.",
				data->args.n_philos);
		return (-1);
	}
	data->args.time_to_die = ft_atoi(argv[2]);
	data->args.time_to_eat = ft_atoi(argv[3]);
	data->args.time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->args.n_times_must_eat = ft_atoi(argv[5]);
	else
		data->args.n_times_must_eat = 2147483647;
	if (data->args.time_to_die < 0 || data->args.time_to_eat < 0
		|| data->args.time_to_sleep < 0 || data->args.n_times_must_eat < 0)
	{
		printf("Error: negative argument.\n");
		return (-1);
	}
	// TABLE - FORKS
	data->forks = malloc(sizeof(pthread_mutex_t) * data->args.n_philos);
	if (!data->forks)
	{
		printf("Error: malloc failed\n");
		return (-1);
	}
	// TABLE - FORKS
	i = -1;
	while (++i < data->args.n_philos)
		pthread_mutex_init(&data->forks[i], NULL);
	// TABLE - PRINT_MUTEX
	pthread_mutex_init(&data->print_mutex, NULL);
	// TABLE - somebody_is_dead
	data->somebody_is_dead = 0;
	pthread_mutex_init(&data->somebody_is_dead_mutex, NULL);
	return (0);
}

void	init_philos(t_philo *philos, t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->args.n_philos)
	{
		philos[i].id = i + 1;
		philos[i].is_eating = 0;
		philos[i].times_eaten = 0;
		philos[i].args = &data->args;
		philos[i].left_fork = &data->forks[i];
		philos[i].right_fork = &data->forks[(i + 1) % data->args.n_philos];
		philos[i].print_mutex = &data->print_mutex;
		philos[i].data = data;
		pthread_mutex_init(&philos[i].eating, NULL);
		// data->philos[i].somebody_died = data->somebody_is_dead;
		// data->philos[i].somebody_died_mutex = &data->somebody_is_dead_mutex;
	}
}
