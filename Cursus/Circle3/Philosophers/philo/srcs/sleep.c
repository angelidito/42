/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 20:05:18 by angmarti          #+#    #+#             */
/*   Updated: 2023/07/19 21:33:17 by angmarti         ###   ########.fr       */
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
	printf("%ld %d is sleeping\n", now, philo->id);
	pthread_mutex_unlock(philo->print_mutex);
	while (get_time() < time_end)
	{
		if (is_philo_dead(philo))
			return ;
		usleep(100);
	}
}

// TODO: hacer que el tiempo del usleep sea como mucho 10 ms ( o se dividir por la cantidad de philosophers)
void ft_usleep(int mcs)
{

}