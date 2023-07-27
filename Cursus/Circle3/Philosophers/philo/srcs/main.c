/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 19:52:51 by angmarti          #+#    #+#             */
/*   Updated: 2023/07/27 19:55:36 by angmarti         ###   ########.fr       */
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
	late_free(philos, data);
}

int	main(int argc, char const *argv[])
{
	t_data	data;
	int		i;
	t_philo	*philos;

	if (init_data(&data, argc, argv))
		return (1);
	philos = malloc(sizeof(t_philo) * data.args.n_philos);
	if (!philos)
		return (error_return_early_free(&data));
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
