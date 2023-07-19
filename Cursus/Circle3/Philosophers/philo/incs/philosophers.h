/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 20:04:28 by angmarti          #+#    #+#             */
/*   Updated: 2023/07/19 20:12:26 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include "colors.h"
# include "libs.h"
# include "structs.h"
// # include "functions.h"

//	PRINT

void	wanna_print(t_philo *philo);

//	THINK

void	philo_think(t_philo *philo);

//	DEATH

int		is_philo_dead(t_philo *philo);

//	EAT

void	philo_eat(t_philo *philo);

//	SLEEP

void	philo_sleep(t_philo *philo);

//	LIBFT

char	*ft_itoa(int n);
int		ft_atoi(const char *str);

//	PHILOSOPHER

void	*start(void *arg);

//	TABLE

int		init_table(t_table *table, int argc, char const *argv[]);

//	TIME

long	get_time(void);

#endif