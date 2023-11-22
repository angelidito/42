/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_pthread_mutex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:21:19 by angmarti          #+#    #+#             */
/*   Updated: 2023/11/22 15:48:05 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philosophers.h"

/**
 * Locks a mutex and prints a debug message if enabled.
 * 
 * @param mutex Mutex that needs to be locked.
 * @param name Name of the mutex.
 * @param philo A philosopher.
 */
void	my_pthread_mutex_lock(pthread_mutex_t *mutex, char *name,
		t_philo *philo)
{
	int		ret;
	long	time;

	time = get_time() - philo->data->start_time;
	printf("%lu trying to lock %s\n", time, name);
	ret = pthread_mutex_lock(mutex);
	if (ret)
	{
		// printf("Error: %s\n", strerror(ret));
		// exit(1);
	}
	if (DEBUG)
		printf(LOCK, time, philo->id, TEXT_RED, name, TEXT_RESET);
}

/**
 * Unlocks a mutex and prints a debug message if enabled.
 * 
 * @param mutex Mutex that needs to be unlocked.
 * @param name Name of the mutex.
 * @param philo A philosopher.
 */
void	my_pthread_mutex_unlock(pthread_mutex_t *mutex, char *name,
		t_philo *philo)
{
	int		ret;
	long	time;

	time = get_time() - philo->data->start_time;
	ret = pthread_mutex_unlock(mutex);
	if (ret)
	{
		// printf("Error: %s\n", strerror(ret));
		// exit(1);
	}
	if (DEBUG)
		printf(UNLOCK, time, philo->id, TEXT_RED, name, TEXT_RESET);
}
