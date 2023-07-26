/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 20:05:18 by angmarti          #+#    #+#             */
/*   Updated: 2023/07/26 15:19:39 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philosophers.h"

/**
 * Takes a fork of a philosopher and prints it.
 * 
 * @param philo A philosopher.
 * @param fork His fork to take.
 * 
 * @return 1 if it can take it. Otherwise, it returns 0 because 
 * somebody is dead.
 */
int	take_fork(t_philo *philo, pthread_mutex_t *fork, char *right_or_left)
{
	long	now;

	if (is_somebody_dead(philo))
		return (0);
	pthread_mutex_lock(fork);
	now = get_time();
	if (!can_i_print(philo))
		return (0);
	printf("%ld %d %shas taken %s fork%s\n", now - philo->data->start_time,
			philo->id, TEXT_BLUE, right_or_left, TEXT_RESET);
	pthread_mutex_unlock(philo->print_mutex);
	return (1);
}

/**
 * The function takes the first fork of a philosopher.
 * 
 * @param philo A philosopher.
 * 
//  * @return 1 if it can take them. Otherwise, it returns 0 because 
//  * somebody is dead.
 */
void	take_forks(t_philo *philo)
{
	if (philo->left_fork == philo->right_fork)
	{
		take_fork(philo, philo->left_fork, "the only");
		while (can_i_print(philo))
		{
			printf("Solo hay un filosofo y un tenedor,"); // Comentable
			printf("no puede comer y va a morir.\n");     // Comentable
			pthread_mutex_unlock(philo->print_mutex);
			usleep(100);
		}
		return ;
	}
	if (philo->id % 2 == 0)
	{
		take_fork(philo, philo->left_fork, "the left");
		take_fork(philo, philo->right_fork, "the right");
	}
	else
	{
		take_fork(philo, philo->right_fork, "the right");
		take_fork(philo, philo->left_fork, "the left");
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

int	philo_is_full(t_philo *philo)
{
	int	is_full;

	pthread_mutex_lock(&philo->eating);
	is_full = philo->times_eaten >= philo->args->n_times_must_eat;
	pthread_mutex_unlock(&philo->eating);
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
	// printf("Philo %d: foks taken.\n", philo->id);
	if (!can_i_print(philo))
	{
		return (0);
	}
	// printf("Philo %d: about to lock print mutex.\n", philo->id);
	pthread_mutex_lock(&philo->eating);
	// printf("Philo %d: print mutex locked.\n", philo->id);
	now = get_time();
	pthread_mutex_lock(&philo->data->somebody_is_dead_mutex); // necesario?
	printf("%ld %d %sis eating%s\n", now - philo->data->start_time, philo->id,
			TEXT_GREEN, TEXT_RESET);
	philo->last_eat = now;
	philo->times_eaten++;
	pthread_mutex_unlock(&philo->eating);
	pthread_mutex_unlock(philo->print_mutex);
	pthread_mutex_unlock(&philo->data->somebody_is_dead_mutex); // necesario?
	time_end = now + philo->args->time_to_eat;
	while (get_time() < time_end)
	{
		usleep(100);
	}
	leave_forks(philo);
	return (1);
}
