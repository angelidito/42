/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 21:48:28 by angmarti          #+#    #+#             */
/*   Updated: 2023/07/15 21:51:06 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philosophers.h"

void	*start(void *arg)
{
	t_philo *philo;
	int i;

	philo = (t_philo *)arg;
	i = -1;
	philo->last_eat = get_time();
	pthread_mutex_lock(philo->print_mutex);
	printf("is alive Philosopher %d\n", philo->id);
	pthread_mutex_unlock(philo->print_mutex);
	return (NULL);
}