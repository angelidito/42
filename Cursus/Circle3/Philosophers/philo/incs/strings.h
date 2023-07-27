/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 20:04:28 by angmarti          #+#    #+#             */
/*   Updated: 2023/07/27 19:44:48 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRINGS_H
# define STRINGS_H

//	PHILOSOPHERS

# define SLEEPING "%6ld %d %sis sleeping%s\n"
# define THINKING "%6ld %d %sis thinking%s\n"
# define EATING "%6ld %d %sis eating%s\n"
# define FORK_TAKING "%6ld %d %shas taken a fork%s\n"
# define DEATH "%6ld %d %sis dead%s\n"

//	ERRORS

# define ERROR_MALLOC "Error: malloc failed\n"
# define ERROR_NEGATIVE_ARG "Error: negative argument(s).\n"
# define ERROR_PHILO_NBR "Error: number of philosophers lower than one.\n"

//	ERRORS -> USAGE

# define USAGE_1_3 "Usage: ./philo number_of_philosophers time_to_die"
# define USAGE_2_3 " time_to_eat time_to_sleep"
# define USAGE_3_3 " [number_of_times_each_philosopher_must_eat]\n"

#endif
