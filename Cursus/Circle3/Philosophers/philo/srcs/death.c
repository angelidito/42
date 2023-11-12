/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 20:06:18 by angmarti          #+#    #+#             */
/*   Updated: 2023/11/12 16:30:28 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philosophers.h"

/**
 * Prints the death of a philosopher and announces it to the others.
 * 
 * @param philo 
 */
void	somebody_died(t_philo *philo)
{
	pthread_mutex_unlock(&philo->eating_mutex);
	philo->data->somebody_is_dead = 1;
	pthread_mutex_lock(philo->print_mutex);
	print_death(philo, get_time());
	pthread_mutex_unlock(philo->print_mutex);
}

int	is_somebody_dead(t_philo *philo)
{
	if (philo->data->somebody_is_dead)
	{
		return (1);
	}
	return (0);
}

/**
 * It's a thread function that continuously checks if a philosopher has exceeded
 * the time limit for eating and if so, prints the death of a philosopher and 
 * announces it to the others.
 * 
 * @param arg A `t_philo` pointer.
 * 
 * @return NULL.
 */
void	*check_death(void *arg)
{
	long	death;
	t_philo	*philo;

	philo = (t_philo *)arg;
	death = 0;
	while (!philo_is_full(philo) && !death)
	{
		usleep(100);
		pthread_mutex_lock(&philo->eating_mutex);
		death = get_time() - philo->last_eat > philo->args->time_to_die;
		if (death)
		{
			pthread_mutex_lock(&philo->data->somebody_is_dead_mutex);
			if (!philo->data->somebody_is_dead)
				somebody_died(philo);
			else
				pthread_mutex_unlock(&philo->eating_mutex);
			pthread_mutex_unlock(&philo->data->somebody_is_dead_mutex);
			break ;
		}
		else
			pthread_mutex_unlock(&philo->eating_mutex);
	}
	return (NULL);
}

/**
 * Initializes a death checker thread for a philosopher.
 * 
 * @param philo The philosopher to check.
 */
void	death_checker_init(t_philo *philo)
{
	pthread_create(&philo->death_checker, NULL, check_death, philo);
	pthread_detach(philo->death_checker);
}
