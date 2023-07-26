/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 20:05:18 by angmarti          #+#    #+#             */
/*   Updated: 2023/07/26 15:30:06 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philosophers.h"

int	philo_sleep(t_philo *philo)
{
	long	time_end;
	long	now;

	now = get_time();
	if (!can_i_print(philo))
		return (0);
	printf("%ld %d %sis sleeping%s\n", now - philo->data->start_time, philo->id,
			TEXT_BLACK, TEXT_RESET);
	pthread_mutex_unlock(philo->print_mutex);
	time_end = now + philo->args->time_to_sleep;
	while (get_time() < time_end)
	{
		usleep(100);
	}
	return (1);
}
