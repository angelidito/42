/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 20:04:28 by angmarti          #+#    #+#             */
/*   Updated: 2023/07/19 19:47:50 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "libs.h"

typedef struct s_args
{
	int				n_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				n_times_must_eat;
}					t_args;

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	int				is_dead;
	int				is_eating;
	int				times_eaten;
	long			last_eat;
	int				*somebody_died;
	pthread_mutex_t	*somebody_died_mutex;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*print_mutex;
	t_args			*args;
}					t_philo;

typedef struct s_table
{
	t_args			args;
	int				*philo_is_dead;
	pthread_mutex_t	philo_is_dead_mutex;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_mutex;
	t_philo			*philos;
	int				fd_out;
}					t_table;

#endif