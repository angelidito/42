/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 21:48:28 by angmarti          #+#    #+#             */
/*   Updated: 2023/11/21 15:27:26 by angmarti         ###   ########.fr       */
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
		my_pthread_mutex_lock(&philo->data->turn_mutex, "turn", philo);
		if (philo->id % 2 == philo->data->turn)
			myturn = 1;
		my_pthread_mutex_unlock(&philo->data->turn_mutex, "turn", philo);
		if (!myturn)
			usleep(500);
		my_pthread_mutex_lock(&philo->data->somebody_is_dead_mutex, "somebody_is_dead", philo);
		if (is_somebody_dead(philo))
			everybody_alive = 0;
		my_pthread_mutex_unlock(&philo->data->somebody_is_dead_mutex, "somebody_is_dead", philo);
	}
	return (everybody_alive);
}

void	next_turn(t_philo *philo)
{
	my_pthread_mutex_lock(&philo->data->turn_mutex, "turn", philo);
	if (philo->id % 2)
		philo->data->pairs++;
	else
		philo->data->odds++;
	if (philo->data->pairs == philo->data->args.n_philos / 2)
	{
		can_i_print(philo);
		philo->data->turn = (philo->data->turn + 1) % 2;
		philo->data->pairs = 0;
		my_pthread_mutex_unlock(philo->print_mutex, "print", philo);
	}
	if (philo->data->odds == (philo->data->args.n_philos / 2)
		+ (philo->data->args.n_philos % 2))
	{
		can_i_print(philo);
		philo->data->turn = (philo->data->turn + 1) % 2;
		philo->data->odds = 0;
		my_pthread_mutex_unlock(philo->print_mutex, "print", philo);
	}
	my_pthread_mutex_unlock(&philo->data->turn_mutex, "turn", philo);
}

void	*start(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	my_pthread_mutex_lock(&philo->eating_mutex, "eating", philo);
	philo->last_eat = get_time();
	my_pthread_mutex_unlock(&philo->eating_mutex, "eating", philo);
	death_checker_init(philo);
	my_pthread_mutex_lock(&philo->data->somebody_is_dead_mutex, "somebody_is_dead", philo);
	while (!philo_is_full(philo) && !philo->data->somebody_is_dead)
	{
		my_pthread_mutex_unlock(&philo->data->somebody_is_dead_mutex, "somebody_is_dead", philo);
		if (!philo_sleep(philo))
			break ;
		if (!philo_think(philo))
			break ;
		if (!philo_eat(philo))
			break ;
		my_pthread_mutex_lock(&philo->data->somebody_is_dead_mutex, "somebody_is_dead", philo);
	}
	leave_forks(philo);
	my_pthread_mutex_unlock(&philo->data->somebody_is_dead_mutex, "somebody_is_dead", philo);
	return (NULL);
}
