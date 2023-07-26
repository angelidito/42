/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 20:04:28 by angmarti          #+#    #+#             */
/*   Updated: 2023/07/26 15:15:25 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include "colors.h"
# include "libs.h"
# include "structs.h"
// # include "functions.h"

//	PRINT

int		can_i_print(t_philo *philo);

//	THINK

int	philo_think(t_philo *philo);

//	DEATH

void	death_checker_init(t_philo *philo);
int		is_somebody_dead(t_philo *philo);

//	EAT

int	philo_eat(t_philo *philo);
void	take_fork1(t_philo *philo);
void	take_fork2(t_philo *philo);
int		philo_is_full(t_philo *philo);

//	SLEEP

int	philo_sleep(t_philo *philo);

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