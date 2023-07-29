/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 19:52:51 by angmarti          #+#    #+#             */
/*   Updated: 2023/07/29 18:05:20 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philosophers.h"

void	finish(t_philo *philos, t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->args.n_philos)
	{
		pthread_join(philos[i].thread, NULL);
		pthread_mutex_destroy(&philos[i].eating_mutex);
	}
	if (data->args.n_philos == 3)
		pthread_mutex_destroy(data->case_3_mutex);
	else
		pthread_mutex_destroy(data->turn_mutex);
	late_free(philos, data);
}

void	launch_philos(t_philo *philos, t_data *data)
{
	int	i;

	if (data->args.n_philos == 3)
	{
		pthread_mutex_init(data->case_3_mutex, NULL);
		data->case_3_order = 0;
	}
	else
	{
		pthread_mutex_init(data->turn_mutex, NULL);
		data->turn = 1;
		data->pairs = 0;
		data->odds = 0;
	}
	i = -1;
	while (++i < data->args.n_philos)
	{
		if (data->args.n_philos == 3)
		{
			pthread_create(&philos[i].thread, NULL, start_case_3, &philos[i]);
		}
		else
		{
			if (!(i % 2))
			pthread_create(&philos[i].thread, NULL, start, &philos[i]);
		}
	}
			usleep(data->args.time_to_sleep * 1000);

	i = -1;
	while (data->args.n_philos != 3 && ++i < data->args.n_philos)
	{
		if ((i % 2))
			pthread_create(&philos[i].thread, NULL, start, &philos[i]);
	}
}

int	main(int argc, char const *argv[])
{
	t_data	data;
	t_philo	*philos;

	if (init_data(&data, argc, argv))
		return (1);
	philos = malloc(sizeof(t_philo) * data.args.n_philos);
	if (!philos)
		return (error_return_early_free(&data));
	init_philos(philos, &data);
	data.start_time = get_time();
	launch_philos(philos, &data);
	finish(philos, &data);
	return (0);
}
