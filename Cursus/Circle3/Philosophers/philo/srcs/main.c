/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 19:52:51 by angmarti          #+#    #+#             */
/*   Updated: 2023/07/26 18:21:02 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philosophers.h"

void	print_data(t_data *data)
{
	printf("Table initialized.\n");
	printf("Philosophers: %d\n", data->args.n_philos);
	printf("Time to die: %d\n", data->args.time_to_die);
	printf("Time to eat: %d\n", data->args.time_to_eat);
	printf("Time to sleep: %d\n", data->args.time_to_sleep);
	printf("Time to sleep: %d\n", data->args.n_times_must_eat);
	printf("Remaning time to think: %d\n\n\n", data->args.time_to_die
		- data->args.time_to_eat - data->args.time_to_sleep);
}

void	finish(t_philo *philos, t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->args.n_philos)
	{
		pthread_join(philos[i].thread, NULL);
		pthread_mutex_destroy(&philos[i].eating_mutex);
	}
	early_free(data);
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
	finish(philos, &data);
	return (0);
}
