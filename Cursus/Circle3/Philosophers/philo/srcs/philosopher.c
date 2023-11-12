/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 21:48:28 by angmarti          #+#    #+#             */
/*   Updated: 2023/11/12 16:30:12 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philosophers.h"

int	wait4turn(t_philo *philo)
{
	int	everybody_alive;
	int	myturn;

	myturn = 0;
	everybody_alive = 1;
	while (everybody_alive && !myturn)
	{
		pthread_mutex_lock(&philo->data->turn_mutex);
		if (philo->id % 2 == philo->data->turn)
			myturn = 1;
		pthread_mutex_unlock(&philo->data->turn_mutex);
		if (!myturn)
			usleep(500);
		pthread_mutex_lock(&philo->data->somebody_is_dead_mutex);
		if (is_somebody_dead(philo))
			everybody_alive = 0;
		pthread_mutex_unlock(&philo->data->somebody_is_dead_mutex);
	}
	return (everybody_alive);
}

void	next_turn(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->turn_mutex);
	if (philo->id % 2)
		philo->data->pairs++;
	else
		philo->data->odds++;
	if (philo->data->pairs == philo->data->args.n_philos / 2)
	{
		can_i_print(philo);
		philo->data->turn = (philo->data->turn + 1) % 2;
		philo->data->pairs = 0;
		pthread_mutex_unlock(philo->print_mutex);
	}
	if (philo->data->odds == (philo->data->args.n_philos / 2)
		+ (philo->data->args.n_philos % 2))
	{
		can_i_print(philo);
		philo->data->turn = (philo->data->turn + 1) % 2;
		philo->data->odds = 0;
		pthread_mutex_unlock(philo->print_mutex);
	}
	pthread_mutex_unlock(&philo->data->turn_mutex);
}

void	*start(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	pthread_mutex_lock(&philo->eating_mutex);
	philo->last_eat = get_time();
	pthread_mutex_unlock(&philo->eating_mutex);
	death_checker_init(philo);
	pthread_mutex_lock(&philo->data->somebody_is_dead_mutex);
	while (!philo_is_full(philo) && !philo->data->somebody_is_dead)
	{
		pthread_mutex_unlock(&philo->data->somebody_is_dead_mutex);
		if (!philo_sleep(philo))
			break ;
		if (!philo_think(philo))
			break ;
		if (!philo_eat(philo))
			break ;
		pthread_mutex_lock(&philo->data->somebody_is_dead_mutex);
	}
	leave_forks(philo);
	pthread_mutex_unlock(&philo->data->somebody_is_dead_mutex);
	return (NULL);
}
