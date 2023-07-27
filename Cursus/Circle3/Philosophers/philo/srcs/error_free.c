/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 20:11:52 by angmarti          #+#    #+#             */
/*   Updated: 2023/07/27 19:48:52 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philosophers.h"

/**
 * Frees the mutexes and the forks
 * 
 * @param data A pointer to a struct of type t_data.
 */
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

/**
 * Frees the mutexes, the forks and the philos
 * 
 * @param philos A pointer to a struct of type t_philo.
 * @param data A pointer to a struct of type t_data.
 */
void	late_free(t_philo *philos, t_data *data)
{
	early_free(data);
	free(philos);
}

/**
 * Prints an error message and frees the mutexes, the forks and the philos
 * 
 * @param data A pointer to a struct of type t_data.
 * @return int 1
 */
int	error_return_early_free(t_data *data)
{
	early_free(data);
	printf(ERROR_MALLOC);
	return (1);
}

/**
 * Prints usage messages and returns 1.
 * 
 * @return the value 1.
 */
int	wrong_args(void)
{
	printf(USAGE_1_3);
	printf(USAGE_2_3);
	printf(USAGE_3_3);
	return (1);
}
