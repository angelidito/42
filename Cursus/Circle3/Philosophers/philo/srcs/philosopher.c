/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 21:48:28 by angmarti          #+#    #+#             */
/*   Updated: 2023/07/19 20:01:47 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philosophers.h"

void	wanna_print(t_philo *philo)
{
	// pthread_mutex_lock(philo->somebody_died_mutex);
	// if (*(philo->somebody_died) == 1)
	// {
	// 	pthread_mutex_unlock(philo->somebody_died_mutex);
	// 	exit(0);
	// }
	// pthread_mutex_unlock(philo->somebody_died_mutex);
	// pthread_mutex_lock(philo->print_mutex);
	philo++;
}

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
		pthread_mutex_lock(philo->print_mutex);
		printf("%ld %d died\n", now, philo->id);
		philo->is_dead = 1;
		// pthread_mutex_lock(philo->somebody_died_mutex);
		// *(philo->somebody_died) = 1;
		// pthread_mutex_unlock(philo->somebody_died_mutex);
		return (1);
	}
	return (0);
}

void	philo_sleep(t_philo *philo)
{
	long	time_end;
	long	now;

	now = get_time();
	time_end = now + philo->args->time_to_sleep;
	wanna_print(philo);
	pthread_mutex_lock(philo->print_mutex);
	printf("[%ld] %d is sleeping\n", now, philo->id);
	pthread_mutex_unlock(philo->print_mutex);
	while (get_time() < time_end)
	{
		if (is_philo_dead(philo))
			return ;
		usleep(100);
	}
}

void	philo_think(t_philo *philo)
{
	long	now;

	now = get_time();
	wanna_print(philo);
	pthread_mutex_lock(philo->print_mutex);
	printf("[%ld] %d is thinking\n", now, philo->id);
	pthread_mutex_unlock(philo->print_mutex);
}

void	philo_eat(t_philo *philo)
{
	long	time_end;
	long	now;

	now = get_time();
	philo->last_eat = now;
	time_end = now + philo->args->time_to_eat;
	wanna_print(philo);
	pthread_mutex_lock(philo->print_mutex);
	printf("[%ld] %d is eating\n", now, philo->id);
	pthread_mutex_unlock(philo->print_mutex);
	while (get_time() < time_end)
	{
		if (is_philo_dead(philo))
			return ;
		usleep(100);
	}
}

void	*start(void *arg)
{
	t_philo	*philo;
	int		i;

	philo = (t_philo *)arg;
	i = -1;
	philo->last_eat = get_time();
	wanna_print(philo);
	printf("Philosopher %d is alive and ready to eat!\n", philo->id);
	pthread_mutex_unlock(philo->print_mutex);
	while (++i < philo->args->n_times_must_eat)
	{
		if (!is_philo_dead(philo))
			philo_sleep(philo);
		if (!is_philo_dead(philo))
			philo_think(philo);
		if (!is_philo_dead(philo))
			philo_eat(philo);
		if (is_philo_dead(philo))
			break ;
	}
	return (NULL);
}
