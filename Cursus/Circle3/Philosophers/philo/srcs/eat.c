/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 20:05:18 by angmarti          #+#    #+#             */
/*   Updated: 2023/11/21 15:26:14 by angmarti         ###   ########.fr       */
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

	my_pthread_mutex_lock(&philo->data->somebody_is_dead_mutex,
			"somebody_is_dead", philo);
	if (is_somebody_dead(philo))
	{
		my_pthread_mutex_unlock(&philo->data->somebody_is_dead_mutex,
				"somebody_is_dead", philo);
		return (0);
	}
	my_pthread_mutex_unlock(&philo->data->somebody_is_dead_mutex,
			"somebody_is_dead", philo);
	my_pthread_mutex_lock(fork, "fork", philo);
	now = get_time();
	if (!can_i_print(philo))
		return (0);
	print_fork_taking(philo, now);
	my_pthread_mutex_unlock(philo->print_mutex, "print", philo);
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
			my_pthread_mutex_unlock(philo->print_mutex, "print", philo);
			usleep(100);
		}
	}
	else if (1 || philo->id % 2 == 0 || philo->data->args.n_philos == 3)
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
 * Leaves the forks of a philosopher.
 * 
 * @param philo A philosopher. 
 */
void	leave_forks(t_philo *philo)
{
	my_pthread_mutex_unlock(philo->right_fork, "right fork", philo);
	my_pthread_mutex_unlock(philo->left_fork, "left fork", philo);
}

/**
 * Checks if a philosopher has eaten the required number of times.
 * 
 * @param philo A philosopher.
 * 
 * @return 1 if he has eaten the required number of times.
 * Otherwise, it returns 0.
 */
int	philo_is_full(t_philo *philo)
{
	int	is_full;

	my_pthread_mutex_lock(&philo->eating_mutex, "eating", philo);
	is_full = philo->times_eaten >= philo->args->n_times_must_eat;
	my_pthread_mutex_unlock(&philo->eating_mutex, "eating", philo);
	return (is_full);
}

// void	ps_access(t_philo *philo)
// {
// 	int	n_philos;

// 	n_philos = philo->data->args.n_philos;
// 	pthread_mutex_lock(&philo->data->ps_mutex[(philo->id + 1) % n_philos]);
// 	pthread_mutex_lock(&philo->data->ps_mutex[(philo->id) % n_philos]);
// }

// void ps_leave(t_philo *philo)
// {
// 	int	n_philos;

// 	n_philos = philo->data->args.n_philos;
// 	pthread_mutex_unlock(&philo->data->ps_mutex[(philo->id) % n_philos]);
// 	pthread_mutex_unlock(&philo->data->ps_mutex[(philo->id + 1) % n_philos]);
// }

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
		return (0);
	my_pthread_mutex_lock(&philo->eating_mutex, "eating", philo);
	now = get_time();
	my_pthread_mutex_lock(&philo->data->somebody_is_dead_mutex,
			"somebody_is_dead", philo);
	print_eat(philo, now);
	my_pthread_mutex_lock(&philo->eating_mutex2, "eating2", philo);
	philo->last_eat = now;
	philo->times_eaten++;
	my_pthread_mutex_unlock(&philo->eating_mutex2, "eating2", philo);
	my_pthread_mutex_unlock(&philo->eating_mutex, "eating", philo);
	my_pthread_mutex_unlock(philo->print_mutex, "print", philo);
	my_pthread_mutex_unlock(&philo->data->somebody_is_dead_mutex,
			"somebody_is_dead", philo);
	time_end = now + philo->args->time_to_eat;
	while (get_time() < time_end)
	{
		usleep(100);
	}
	leave_forks(philo);
	return (1);
}
