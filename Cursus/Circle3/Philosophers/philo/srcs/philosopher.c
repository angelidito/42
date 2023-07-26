/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 21:48:28 by angmarti          #+#    #+#             */
/*   Updated: 2023/07/26 15:30:09 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philosophers.h"

void	*start(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	philo->last_eat = get_time();
	death_checker_init(philo);
	while (!philo_is_full(philo) && !philo->data->somebody_is_dead)
	{
		// printf("Philosopher %d is alive.\n", philo->id);
		if (!philo_sleep(philo))
			break ;
		if (!philo_think(philo))
			break ;
		if (!philo_eat(philo))
			break ;
	}
	// printf("Philosopher %d finished.\n", philo->id);
	pthread_join(philo->death_checker, NULL);
	return (NULL);
}
