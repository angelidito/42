/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 20:05:18 by angmarti          #+#    #+#             */
/*   Updated: 2023/07/26 19:11:04 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philosophers.h"

/**
 * Takes a fork of a philosopher, and prints it, if nobody is dead.
 * 
 * @param philo A philosopher.
 * @param fork His fork to take.
 * 
 * @return 1 if it can take it. Otherwise, it returns 0, because 
 * somebody is dead.
 */
int	take_fork(t_philo *philo, pthread_mutex_t *fork)
{
	long	now;

	if (is_somebody_dead(philo))
		return (0);
	pthread_mutex_lock(fork);
	now = get_time();
	if (!can_i_print(philo))
		return (0);
	print_fork_taking(philo, now);
	pthread_mutex_unlock(philo->print_mutex);
	return (1);
}

/**
 * The function takes the first fork of a philosopher.
 * 
 * @param philo A philosopher.
 * 
 */
void	take_forks(t_philo *philo)
{
	if (philo->left_fork == philo->right_fork)
	{
		take_fork(philo, philo->left_fork);
		while (can_i_print(philo))
		{
			pthread_mutex_unlock(philo->print_mutex);
			usleep(100);
		}
	}
	else if (philo->id % 2 == 0 || philo->data->args.n_philos == 3)
	{
		take_fork(philo, philo->right_fork);
		take_fork(philo, philo->left_fork);
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
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}

int	philo_is_full(t_philo *philo)
{
	int	is_full;

	pthread_mutex_lock(&philo->eating_mutex);
	is_full = philo->times_eaten >= philo->args->n_times_must_eat;
	pthread_mutex_unlock(&philo->eating_mutex);
	return (is_full);
}

/**
 * The function makes a philosopher eat.
 * 
 * @param philo A philosopher.
 */
int	philo_eat(t_philo *philo)
{
	long	time_end;
	long	now;

	take_forks(philo);
	if (!can_i_print(philo))
	{
		return (0);
	}
	pthread_mutex_lock(&philo->eating_mutex);
	now = get_time();
	pthread_mutex_lock(&philo->data->somebody_is_dead_mutex);
	print_eat(philo, now);
	philo->last_eat = now;
	philo->times_eaten++;
	pthread_mutex_unlock(&philo->eating_mutex);
	pthread_mutex_unlock(philo->print_mutex);
	pthread_mutex_unlock(&philo->data->somebody_is_dead_mutex);
	time_end = now + philo->args->time_to_eat;
	while (get_time() < time_end)
	{
		usleep(50);
	}
	leave_forks(philo);
	return (1);
}
