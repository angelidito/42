/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 20:06:18 by angmarti          #+#    #+#             */
/*   Updated: 2023/11/22 15:57:26 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philosophers.h"

/**
 * Prints the death of a philosopher and announces it to the others.
 * 
 * @param philo 
 */
void	somebody_died(t_philo *philo)
{
	my_pthread_mutex_unlock(&philo->eating_mutex, "eating", philo);
				philo->data->somebody_is_dead = 1;
				my_pthread_mutex_lock(philo->print_mutex, "print", philo);
				print_death(philo, get_time());
				my_pthread_mutex_unlock(philo->print_mutex, "print", philo);
}

int	is_somebody_dead(t_philo *philo)
{
	if (philo->data->somebody_is_dead)
	{
		return (1);
	}
	return (0);
}

/**
 * It's a thread function that continuously checks if a philosopher has exceeded
 * the time limit for eating and if so, prints the death of a philosopher and 
 * announces it to the others.
 * 
 * @param arg A `t_philo` pointer.
 * 
 * @return NULL.
 */
void	*check_death(void *arg)
{
	long	death;
	t_philo	*philo;

	philo = (t_philo *)arg;
	death = 0;
	while (!philo_is_full(philo) && !death)
	{
		ft_usleep(400);
		printf(CP, "1");
		my_pthread_mutex_lock(&philo->eating_mutex, "eating", philo);
		printf(CP, "2");
		death = get_time() - philo->last_eat > philo->args->time_to_die;
		if (death)
		{
			printf(CP, "3");
			my_pthread_mutex_lock(&philo->data->somebody_is_dead_mutex,
									"somebody_is_dead",
									philo);
			// pthread_mutex_lock(&philo->data->somebody_is_dead_mutex);
			printf(CP, "4");
			if (!philo->data->somebody_is_dead)
			{
				my_pthread_mutex_unlock(&philo->eating_mutex, "eating", philo);
				philo->data->somebody_is_dead = 1;
				my_pthread_mutex_lock(philo->print_mutex, "print", philo);
				print_death(philo, get_time());
				my_pthread_mutex_unlock(philo->print_mutex, "print", philo);
			}
			else
				my_pthread_mutex_unlock(&philo->eating_mutex, "eating", philo);
			pthread_mutex_unlock(&philo->data->somebody_is_dead_mutex);
			break ;
		}
		my_pthread_mutex_unlock(&philo->eating_mutex, "eating", philo);
	}
	return (NULL);
}

/**
 * Initializes a death checker thread for a philosopher.
 * 
 * @param philo The philosopher to check.
 */
void	death_checker_init(t_philo *philo)
{
	pthread_create(&philo->death_checker, NULL, check_death, philo);
	pthread_detach(philo->death_checker);
}
