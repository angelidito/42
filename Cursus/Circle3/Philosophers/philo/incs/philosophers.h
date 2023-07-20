/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 20:04:28 by angmarti          #+#    #+#             */
/*   Updated: 2023/07/20 19:28:01 by angmarti         ###   ########.fr       */
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

void	*check_death(void *arg);
void		death_checker_init(t_philo *philo);

//	EAT

void	philo_eat(t_philo *philo);
void	take_fork1(t_philo *philo);
void	take_fork2(t_philo *philo);

//	SLEEP

void	philo_sleep(t_philo *philo);

//	LIBFT

char	*ft_itoa(int n);
int		ft_atoi(const char *str);

//	PHILOSOPHER

void	*start(void *arg);

//	TABLE

int		init_data(t_data *data, int argc, char const *argv[]);
void	init_philos(t_philo *philos, t_data *data);

//	TIME

long	get_time(void);

#endif