/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 20:05:18 by angmarti          #+#    #+#             */
/*   Updated: 2023/07/20 19:28:04 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philosophers.h"

void	philo_sleep(t_philo *philo)
{
	long	time_end;
	long	now;

	now = get_time();
	time_end = now + philo->args->time_to_sleep;
	wanna_print(philo);
	printf("%ld %d is sleeping\n", now - philo->data->start_time, philo->id);
	pthread_mutex_unlock(philo->print_mutex);
	while (get_time() < time_end)
	{
		usleep(200);
	}
}
