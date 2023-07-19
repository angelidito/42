/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 20:04:28 by angmarti          #+#    #+#             */
/*   Updated: 2023/07/19 16:43:19 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include "colors.h"
# include "structs.h" 
# include "libs.h"
// # include "functions.h"


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