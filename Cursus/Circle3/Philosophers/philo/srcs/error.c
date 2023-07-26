/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 20:11:52 by angmarti          #+#    #+#             */
/*   Updated: 2023/07/26 18:20:15 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philosophers.h"

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
