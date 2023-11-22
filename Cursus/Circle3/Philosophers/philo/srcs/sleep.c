/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 20:05:18 by angmarti          #+#    #+#             */
/*   Updated: 2023/11/22 13:02:27 by angmarti         ###   ########.fr       */
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
	print_sleep(philo, now);
	my_pthread_mutex_unlock(philo->print_mutex, "print", philo);
	time_end = now + philo->args->time_to_sleep;
	while (get_time() < time_end)
	{
		ft_usleep(100);
	}
	return (1);
}
