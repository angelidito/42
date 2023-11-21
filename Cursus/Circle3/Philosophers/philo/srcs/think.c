/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 20:05:18 by angmarti          #+#    #+#             */
/*   Updated: 2023/11/21 13:42:20 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philosophers.h"

int	philo_think(t_philo *philo)
{
	long	now;

	now = get_time();
	if (!can_i_print(philo))
		return (0);
	print_think(philo, now);
	my_pthread_mutex_unlock(philo->print_mutex, "print", philo);
	return (1);
}
