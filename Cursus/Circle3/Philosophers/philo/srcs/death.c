/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 20:06:18 by angmarti          #+#    #+#             */
/*   Updated: 2023/07/20 20:54:36 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philosophers.h"

void	*check_death(void *arg)
{
	long	death;
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (philo->times_eaten < philo->args->n_times_must_eat)
	{
		usleep(1000);
		pthread_mutex_lock(&philo->eating);
		death = get_time() - philo->last_eat > philo->args->time_to_die;
		pthread_mutex_unlock(&philo->eating);
		if (death)
		{
			pthread_mutex_lock(&philo->data->somebody_is_dead_mutex);
			philo->data->somebody_is_dead = 1;
			pthread_mutex_lock(philo->print_mutex);
			printf("%ld %d died\n", get_time() - philo->data->start_time,
					philo->id);
			pthread_mutex_unlock(&philo->data->somebody_is_dead_mutex);
			pthread_mutex_unlock(philo->print_mutex);
			break ;
		}
	}
	return (NULL);
}

void	death_checker_init(t_philo *philo)
{
	pthread_create(&philo->death_checker, NULL, check_death, philo);
}
