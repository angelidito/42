/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 20:06:18 by angmarti          #+#    #+#             */
/*   Updated: 2023/07/26 14:49:24 by angmarti         ###   ########.fr       */
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
	printf("%ld Checker %d: somebody died.\n", get_time() - philo->data->start_time, philo->id);
	pthread_mutex_lock(&philo->data->somebody_is_dead_mutex);
	pthread_mutex_unlock(&philo->eating);
	// printf("Checker %d: somebody_is_dead_mutex locked.\n", philo->id);
	philo->data->somebody_is_dead = 1;
	pthread_mutex_lock(philo->print_mutex);
	printf("%ld %d %sdied%s\n", get_time() - philo->data->start_time, philo->id,
			TEXT_RED, TEXT_RESET);
	pthread_mutex_unlock(&philo->data->somebody_is_dead_mutex);
	pthread_mutex_unlock(philo->print_mutex);
}

int	is_somebody_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->somebody_is_dead_mutex);
	if (philo->data->somebody_is_dead)
	{
		pthread_mutex_unlock(&philo->data->somebody_is_dead_mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->somebody_is_dead_mutex);
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
	// printf("somebody_is_dead: %d\n", philo->data->somebody_is_dead);
	while (!philo_is_full(philo) && !death)
	{
		// printf("Death checker: %d is alive.\n", philo->id);
		usleep(100);
		// printf("About to lock eating mutex.\n");
		pthread_mutex_lock(&philo->eating);
		death = get_time() - philo->last_eat > philo->args->time_to_die;
		// printf("About to unlock eating mutex.\n");
		if (death && !philo->data->somebody_is_dead)
		{
			somebody_died(philo);
			printf("%sDeath info \n", TEXT_YELLOW);
			printf("     philo->id: %d\n", philo->id);
			printf("   time_to_die: %d\n", philo->args->time_to_die);
			printf("      last_eat: %ld\n", philo->last_eat
					- philo->data->start_time);
			printf("    get_time(): %ld\n", get_time()
					- philo->data->start_time);
			printf("  elapsed time: %ld%s\n", get_time() - philo->last_eat,
					TEXT_RESET);
			pthread_mutex_unlock(&philo->eating);
			break ;
		}
		else
			pthread_mutex_unlock(&philo->eating);
	}
	// exit(0);
	// can_i_print(philo);
	printf("Death checker %d: finished.\n", philo->id);
	// pthread_mutex_unlock(philo->print_mutex);
	return (NULL);
}

void	death_checker_init(t_philo *philo)
{
	pthread_create(&philo->death_checker, NULL, check_death, philo);
}
