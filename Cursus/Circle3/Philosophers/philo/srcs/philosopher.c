/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 21:48:28 by angmarti          #+#    #+#             */
/*   Updated: 2023/07/19 20:47:54 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philosophers.h"

void	*start(void *arg)
{
	t_philo	*philo;
	int		i;

	philo = (t_philo *)arg;
	i = -1;
	philo->last_eat = get_time();
	// wanna_print(philo);
	// printf("Philosopher %d is alive and ready to eat!\n", philo->id);
	// pthread_mutex_unlock(philo->print_mutex);
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
