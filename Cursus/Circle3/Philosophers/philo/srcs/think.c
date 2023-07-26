/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 20:05:18 by angmarti          #+#    #+#             */
/*   Updated: 2023/07/26 15:14:07 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philosophers.h"

int	philo_think(t_philo *philo)
{
	long	now;

	now = get_time();
	if (!can_i_print(philo))
		return (0);
	printf("%ld %d is thinking\n", now - philo->data->start_time, philo->id);
	pthread_mutex_unlock(philo->print_mutex);
	return (1);
}
