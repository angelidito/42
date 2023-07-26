/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 20:05:18 by angmarti          #+#    #+#             */
/*   Updated: 2023/07/26 18:42:36 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philosophers.h"

/**
 * Locks print_mutex if it is safe to print, that means that nobody is dead.
 * 
 * @param philo A philosopher.
 * 
 * @return If print_mutex is locked returns 1. Otherwise, it returns 0 and it
 * means sombebody is dead.
 */
int	can_i_print(t_philo *philo)
{
	if (is_somebody_dead(philo))
		return (0);
	pthread_mutex_lock(philo->print_mutex);
	return (1);
}

/**
 * Prints a message indicating that a philosopher is taking a fork.
 * 
 * @param philo A philosopher.
 * @param now Current time in milliseconds.
 */
void	print_fork_taking(t_philo *philo, long now)
{
	long	time;

	time = now - philo->data->start_time;
	printf(FORK_TAKING, time, philo->id, TEXT_BLUE, TEXT_RESET);
}

/**
 * Prints a message indicating that a philosopher has died.
 * 
 * @param philo A philosopher.
 * @param now Current time in milliseconds.
 */
void	print_death(t_philo *philo, long now)
{
	long	time;

	time = now - philo->data->start_time;
	printf(DEATH, time, philo->id, TEXT_RED, TEXT_RESET);
}
