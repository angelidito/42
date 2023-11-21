/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_case_3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 21:48:28 by angmarti          #+#    #+#             */
/*   Updated: 2023/11/21 15:00:57 by angmarti         ###   ########.fr       */
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
		my_pthread_mutex_lock(&philo->data->case_3_mutex, "case_3", philo);
		if (philo->id == philo->data->case_3_order + 1)
			myturn = 1;
		my_pthread_mutex_unlock(&philo->data->case_3_mutex, "case_3", philo);
		if (!myturn)
			usleep(50);
		my_pthread_mutex_lock(&philo->data->somebody_is_dead_mutex,
				"somebody_is_dead", philo);
		if (is_somebody_dead(philo))
			everybody_alive = 0;
		my_pthread_mutex_unlock(&philo->data->somebody_is_dead_mutex,
				"somebody_is_dead", philo);
	}
	return (everybody_alive);
}

void	next_turn_case_3(t_philo *philo)
{
	my_pthread_mutex_lock(&philo->data->case_3_mutex, "case_3", philo);
	philo->data->case_3_order = (philo->data->case_3_order + 1) % 3;
	my_pthread_mutex_unlock(&philo->data->case_3_mutex, "case_3", philo);
}

void	*start_case_3(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	my_pthread_mutex_lock(&philo->eating_mutex, "eating", philo);
	philo->last_eat = get_time();
	my_pthread_mutex_unlock(&philo->eating_mutex, "eating", philo);
	death_checker_init(philo);
	my_pthread_mutex_lock(&philo->data->somebody_is_dead_mutex,
			"somebody_is_dead", philo);
	while (!philo_is_full(philo) && !philo->data->somebody_is_dead)
	{
		my_pthread_mutex_unlock(&philo->data->somebody_is_dead_mutex,
				"somebody_is_dead", philo);
		if (!philo_sleep(philo))
			break ;
		if (!philo_think(philo))
			break ;
		if (!wait4turn_case_3(philo))
			break ;
		if (!philo_eat(philo))
			break ;
		next_turn_case_3(philo);
		my_pthread_mutex_lock(&philo->data->somebody_is_dead_mutex,
				"somebody_is_dead", philo);
	}
	my_pthread_mutex_unlock(&philo->data->somebody_is_dead_mutex,
			"somebody_is_dead", philo);
	// leave_forks(philo);
	return (NULL);
}
