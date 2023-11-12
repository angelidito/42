/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_case_3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 21:48:28 by angmarti          #+#    #+#             */
/*   Updated: 2023/11/12 16:29:24 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philosophers.h"

int	wait4turn_case_3(t_philo *philo)
{
	int	everybody_alive;
	int	myturn;

	myturn = 0;
	everybody_alive = 1;
	while (everybody_alive && !myturn)
	{
		pthread_mutex_lock(&philo->data->case_3_mutex);
		if (philo->id == philo->data->case_3_order + 1)
			myturn = 1;
		pthread_mutex_unlock(&philo->data->case_3_mutex);
		if (!myturn)
			usleep(50);
		pthread_mutex_lock(&philo->data->somebody_is_dead_mutex);
		if (is_somebody_dead(philo))
			everybody_alive = 0;
		pthread_mutex_unlock(&philo->data->somebody_is_dead_mutex);
	}
	return (everybody_alive);
}

void	next_turn_case_3(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->case_3_mutex);
	philo->data->case_3_order = (philo->data->case_3_order + 1) % 3;
	pthread_mutex_unlock(&philo->data->case_3_mutex);
}

void	*start_case_3(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	philo->last_eat = get_time();
	death_checker_init(philo);
	pthread_mutex_lock(&philo->data->somebody_is_dead_mutex);
	while (!philo_is_full(philo) && !philo->data->somebody_is_dead)
	{
		pthread_mutex_unlock(&philo->data->somebody_is_dead_mutex);
		if (!philo_sleep(philo))
			break ;
		if (!philo_think(philo))
			break ;
		if (!wait4turn_case_3(philo))
			break ;
		if (!philo_eat(philo))
			break ;
		next_turn_case_3(philo);
		pthread_mutex_lock(&philo->data->somebody_is_dead_mutex);
	}
	pthread_mutex_unlock(&philo->data->somebody_is_dead_mutex);
	leave_forks(philo);
	return (NULL);
}
