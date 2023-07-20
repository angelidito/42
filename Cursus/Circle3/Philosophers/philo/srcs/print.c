/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 20:05:18 by angmarti          #+#    #+#             */
/*   Updated: 2023/07/20 20:21:23 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philosophers.h"

void	wanna_print(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->somebody_is_dead_mutex);
	if (philo->data->somebody_is_dead == 1)
	{
		pthread_mutex_unlock(&philo->data->somebody_is_dead_mutex);
		exit(0);
	}
	pthread_mutex_unlock(&philo->data->somebody_is_dead_mutex);
	pthread_mutex_lock(philo->print_mutex);
}
