/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 20:05:18 by angmarti          #+#    #+#             */
/*   Updated: 2023/07/20 19:28:20 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philosophers.h"

void	philo_think(t_philo *philo)
{
	long	now;

	now = get_time();
	wanna_print(philo);
	printf("%ld %d is thinking\n", now - philo->data->start_time, philo->id);
	pthread_mutex_unlock(philo->print_mutex);
	if (philo->left_fork == philo->right_fork)
	{
			usleep(200);
	}
}
