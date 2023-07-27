/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 20:04:28 by angmarti          #+#    #+#             */
/*   Updated: 2023/07/27 19:17:35 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include "colors.h"
# include "libs.h"
# include "strings.h"
# include "structs.h"

# define SLEEPING "%6ld %d %sis sleeping%s\n"
# define THINKING "%6ld %d %sis thinking%s\n"
# define EATING "%6ld %d %sis eating%s\n"
# define FORK_TAKING "%6ld %d %shas taken a fork%s\n"
# define DEATH "%6ld %d %sis dead%s\n"

//	DATA

int		init_data(t_data *data, int argc, char const *argv[]);
void	init_philos(t_philo *philos, t_data *data);

//	DEATH

int		is_somebody_dead(t_philo *philo);
void	death_checker_init(t_philo *philo);

//	EAT

int		philo_eat(t_philo *philo);
int		philo_is_full(t_philo *philo);
void	leave_forks(t_philo *philo);

//	ERROR_FREE

int		error_return_early_free(t_data *data);
int		wrong_args(void);
void	late_free(t_philo *philos, t_data *data);
void	early_free(t_data *data);

//	LIBFT

int		ft_atoi(const char *str);

//	PHILOSOPHER

void	*start(void *arg);

//	PRINT

int		can_i_print(t_philo *philo);
void	print_sleep(t_philo *philo, long time);
void	print_think(t_philo *philo, long now);
void	print_eat(t_philo *philo, long now);
void	print_fork_taking(t_philo *philo, long now);
void	print_death(t_philo *philo, long now);

//	SLEEP

int		philo_sleep(t_philo *philo);

//	THINK

int		philo_think(t_philo *philo);

//	TIME

long	get_time(void);

#endif
