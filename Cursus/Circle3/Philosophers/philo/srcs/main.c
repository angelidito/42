/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 19:52:51 by angmarti          #+#    #+#             */
/*   Updated: 2023/07/26 18:01:27 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philosophers.h"
#include <fcntl.h>

void	early_free(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->args.n_philos)
		pthread_mutex_destroy(&data->forks[i]);
	pthread_mutex_destroy(&data->print_mutex);
	pthread_mutex_destroy(&data->somebody_is_dead_mutex);
	free(data->forks);
}

int	return_early_free(t_data *data)
{
	early_free(data);
	printf("Error: malloc failed\n");
	return (-1);
}

int	wrong_args(void)
{
	printf("Usage: ./philo number_of_philosophers time_to_die time_to_eat "
			"time_to_sleep [number_of_times_each_philosopher_must_eat]\n");
	return (-1);
}

int	main(int argc, char const *argv[])
{
	t_data	data;
	int		i;
	t_philo	*philos;

	if (0 && argc != 5 && argc != 6)
	{
		printf("Error: wrong number of arguments\n");
		return (wrong_args());
	}
	if (init_data(&data, argc, argv))
		return (1);
	// printf("Table initialized.\n");
	// printf("Philosophers: %d\n", data.args.n_philos);
	// printf("Time to die: %d\n", data.args.time_to_die);
	// printf("Time to eat: %d\n", data.args.time_to_eat);
	// printf("Time to sleep: %d\n", data.args.time_to_sleep);
	// printf("Times must eat: %d\n", data.args.n_times_must_eat);
	// printf("Remaning time to think: %d\n\n\n", data.args.time_to_die
	// 		- data.args.time_to_eat - data.args.time_to_sleep);
	philos = malloc(sizeof(t_philo) * data.args.n_philos);
	if (!philos)
		return (return_early_free(&data));
	init_philos(philos, &data);
	i = -1;
	data.start_time = get_time();
	while (++i < data.args.n_philos)
	{
		pthread_create(&philos[i].thread, NULL, start, &philos[i]);
		usleep(data.args.time_to_sleep * 1000);
	}
	i = -1;
	while (++i < data.args.n_philos)
	{
		pthread_join(philos[i].thread, NULL);
	}
	// printf("Main end.\n");
	return (0);
}
