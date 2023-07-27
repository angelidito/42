/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 20:04:28 by angmarti          #+#    #+#             */
/*   Updated: 2023/07/27 19:06:17 by angmarti         ###   ########.fr       */
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

typedef struct s_death_checker
{
	pthread_t		thread;
	int				*somebody_is_dead;
	pthread_mutex_t	*somebody_is_dead_mutex;
	pthread_mutex_t	*print_mutex;
}					t_death_checker;

typedef struct s_data
{
	long			start_time;
	t_args			args;
	int				somebody_is_dead;
	pthread_mutex_t	somebody_is_dead_mutex;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_mutex;
	int				fd_out;
}					t_data;

typedef struct s_philo
{
	pthread_t		thread;
	pthread_t		death_checker;
	int				id;
	int				is_eating;
	int				times_eaten;
	long			last_eat;
	pthread_mutex_t	eating_mutex;
	int				i_am_dead;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*print_mutex;
	t_args			*args;
	t_data			*data;
}					t_philo;

#endif
