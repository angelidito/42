/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 20:05:18 by angmarti          #+#    #+#             */
/*   Updated: 2023/07/19 21:18:07 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philosophers.h"

/**
 * Takes a fork of a philosopher and prints it.
 * 
 * @param philo A philosopher.
 * @param fork His fork to take.
 */
void	take_fork(t_philo *philo, pthread_mutex_t *fork)
{
	pthread_mutex_lock(fork);
	wanna_print(philo);
	printf("%ld %d has taken a fork\n", get_time(), philo->id);
	pthread_mutex_unlock(philo->print_mutex);
}
/**
 * The function takes the forks of a philosopher.
 * 
 * @param philo A philosopher.
 */
void	take_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		take_fork(philo, philo->left_fork);
		take_fork(philo, philo->right_fork);
	}
	else
	{
		take_fork(philo, philo->left_fork);
		take_fork(philo, philo->right_fork);
	}
}

/**
 * The function leaves the forks of a philosopher.
 * 
 * @param philo A philosopher. 
 */
void	leave_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	philo_eat(t_philo *philo)
{
	long	time_end;
	long	now;

	take_forks(philo);
	now = get_time();
	philo->last_eat = now;
	time_end = now + philo->args->time_to_eat;
	wanna_print(philo);
	printf("%ld %d is eating\n", now, philo->id);
	pthread_mutex_unlock(philo->print_mutex);
	while (get_time() < time_end)
	{
		if (is_philo_dead(philo))
			return ;
		usleep(100);
	}
	leave_forks(philo);
}
