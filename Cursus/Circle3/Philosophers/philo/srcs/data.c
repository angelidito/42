/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 21:48:28 by angmarti          #+#    #+#             */
/*   Updated: 2023/07/20 16:36:40 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philosophers.h"

/**
 * Sets the values of the t_args pointer passed as parameter, 
 * returning 1 if there is an error.
 * 
 * @param args The pointer to the t_args struct to be filled.
 * @param argc The number of command-line arguments passed to the program
 * @param argv Arguments passed to the program.
 * 
 * @return Returns 1 if there is an error. Otherwise, it returns 0.
 */
int	set_args(t_args *args, int argc, char const *argv[])
{
	if (argc < 5 || argc > 6)
		return (wrong_args());
	args->n_philos = ft_atoi(argv[1]);
	if (args->n_philos < 1)
	{
		printf(ERROR_PHILO_NBR);
		return (1);
	}
	args->time_to_die = ft_atoi(argv[2]);
	args->time_to_eat = ft_atoi(argv[3]);
	args->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		args->n_times_must_eat = ft_atoi(argv[5]);
	else
		args->n_times_must_eat = 2147483647;
	if (args->time_to_die < 0 || args->time_to_eat < 0
		|| args->time_to_sleep < 0 || args->n_times_must_eat < 0)
	{
		printf(ERROR_NEGATIVE_ARG);
		return (1);
	}
	return (0);
}

/**
 * The function initializes the data structure by setting the arguments, 
 * allocating memory for forks,
 * initializing mutexes, and returning 0 if successful.
 * 
 * @param data A pointer to a struct of type t_data.
 * @param argc The number of command-line arguments passed to the program
 * @param argv Arguments passed to the program.
 * 
 * @return If the initialization of data is successful, it returns 0. 
 * If there is an error, it returns 1.
 */
int	init_data(t_data *data, int argc, char const *argv[])
{
	int	i;

	if (set_args(&data->args, argc, argv))
		return (1);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->args.n_philos);
	if (!data->forks)
	{
		printf(ERROR_MALLOC);
		return (1);
	}
	i = -1;
	while (++i < data->args.n_philos)
	{
		pthread_mutex_init(&data->forks[i], NULL);
	}
	pthread_mutex_init(&data->print_mutex, NULL);
	data->somebody_is_dead = 0;
	pthread_mutex_init(&data->somebody_is_dead_mutex, NULL);
	return (0);
}

/**
 * TInitializes the properties of each philosopher.
 * 
 * @param philos An array of philosophers.
 * @param data Data of the program, shared by all the philosophers.
 */
void	init_philos(t_philo *philos, t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->args.n_philos)
	{
		philos[i].id = i + 1;
		philos[i].is_eating = 0;
		philos[i].times_eaten = 0;
		philos[i].args = &data->args;
		philos[i].left_fork = &data->forks[i];
		philos[i].right_fork = &data->forks[(i + 1) % data->args.n_philos];
		philos[i].print_mutex = &data->print_mutex;
		philos[i].data = data;
		pthread_mutex_init(&philos[i].eating_mutex, NULL);
	}
}
