/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 20:06:18 by angmarti          #+#    #+#             */
/*   Updated: 2023/07/19 20:35:36 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philosophers.h"

/**
 * The function checks if a philosopher has died 
 * based on the time since their last meal.
 * 
 * @param philo A philosopher.
 * 
 * @return 1 if the philosopher has died, 0 otherwise.	
 */
int	is_philo_dead(t_philo *philo)
{
	long	now;

	if (philo->is_dead == 1)
		return (1);
	now = get_time();
	if (now - philo->last_eat > philo->args->time_to_die)
	{
		wanna_print(philo);
		printf("%ld %d died\n", now, philo->id);
		philo->is_dead = 1;
		// pthread_mutex_lock(philo->somebody_died_mutex);
		// *(philo->somebody_died) = 1;
		// pthread_mutex_unlock(philo->somebody_died_mutex);
		return (1);
	}
	return (0);
}
