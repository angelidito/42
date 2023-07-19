/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 20:05:18 by angmarti          #+#    #+#             */
/*   Updated: 2023/07/19 20:07:10 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philosophers.h"

void	wanna_print(t_philo *philo)
{
	// pthread_mutex_lock(philo->somebody_died_mutex);
	// if (*(philo->somebody_died) == 1)
	// {
	// 	pthread_mutex_unlock(philo->somebody_died_mutex);
	// 	exit(0);
	// }
	// pthread_mutex_unlock(philo->somebody_died_mutex);
	pthread_mutex_lock(philo->print_mutex);
}
