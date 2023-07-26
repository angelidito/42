/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 20:05:18 by angmarti          #+#    #+#             */
/*   Updated: 2023/07/26 14:57:35 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philosophers.h"

/**
 * Locks print_mutex if it is safe to print, that means that nobody is dead.
 * 
 * @param philo A philosopher.
 * 
 * @return If print_mutex is locked returns 1. Otherwise, it returns 0 and it
 * means sombebody is dead.
 */
int	can_i_print(t_philo *philo)
{
	if (is_somebody_dead(philo))
		return (0);
	pthread_mutex_lock(philo->print_mutex);
	return (1);
}
