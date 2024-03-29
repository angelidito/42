/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 12:01:34 by angmarti          #+#    #+#             */
/*   Updated: 2022/11/16 11:25:32 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../mylibft/incs/libft.h"
// * Includes in libft:
// # include <unistd.h>
// # include <stdlib.h>
// # include <stdio.h>
// # include <string.h>

// Type t_number, which is a struct
typedef struct s_number
{
	int		value;
	ssize_t	weight;
}			t_number;

// errors_check.c

void		check_errors_chararr(char **chararr);
void		check_errors_argv(int argc, const char *argv[]);

// errors_exit.c

void		error_free(char **chararr);
void		error(void);
void		free_chararr(char **chararr);

// lists.c

t_list		*lstremovefirst(t_list **lst);
t_list		*lstremovelast(t_list **lst);

// numbers.c

int			numvalue(t_list *lst);
ssize_t		numweight(t_list *lst);
t_number	*new_number(int value, ssize_t weight);
void		setweight(t_list *lst, ssize_t weight);
ssize_t		setweights(t_list **lst);

// order.c

void		order(t_list **lst);
int			isordered(t_list **a, t_list **b);

// order_algorithm.c

void		start_algorithim(t_list **a, t_list **b, ssize_t maxweight);

// push.c

void		pa(t_list **a, t_list **b);
void		pb(t_list **a, t_list **b);

// rotate.c

void		ra(t_list **a);
void		rb(t_list **b);
void		rr(t_list **a, t_list **b);

// rrotate.c

void		rra(t_list **a);
void		rrb(t_list **b);
void		rrr(t_list **a, t_list **b);

// swap.c

void		sa(t_list **a);
void		sb(t_list **b);
void		ss(t_list **a, t_list **b);

#endif
