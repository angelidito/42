/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 20:05:18 by angmarti          #+#    #+#             */
/*   Updated: 2023/07/26 18:42:44 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philosophers.h"

/**
 * Prints a message indicating that a philosopher is sleeping.
 * 
 * @param philo A philosopher.
 * @param now Current time in milliseconds.
 */
void	print_sleep(t_philo *philo, long now)
{
	long	time;

	time = now - philo->data->start_time;
	printf(SLEEPING, time, philo->id, TEXT_BLACK, TEXT_RESET);
}

/**
 * Prints a message indicating that a philosopher is thinking.
 * 
 * @param philo A philosopher.
 * @param now Current time in milliseconds.
 */
void	print_think(t_philo *philo, long now)
{
	long	time;

	time = now - philo->data->start_time;
	printf(THINKING, time, philo->id, TEXT_YELLOW, TEXT_RESET);
}

/**
 * Prints a message indicating that a philosopher is eating.
 * 
 * @param philo A philosopher.
 * @param now Current time in milliseconds.
 */
void	print_eat(t_philo *philo, long now)
{
	long	time;

	time = now - philo->data->start_time;
	printf(EATING, time, philo->id, TEXT_GREEN, TEXT_RESET);
}
