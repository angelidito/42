/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 12:01:34 by angmarti          #+#    #+#             */
/*   Updated: 2022/11/07 15:55:28 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../mylibft/incs/libft.h"
// * Included in libft:
// # include <unistd.h>
// # include <stdlib.h>
// # include <stdio.h>
// # include <string.h>

typedef struct s_number
{
	int		value;
	ssize_t	weight;
}			t_number;

// errors.c

void		check_errors(int argc, const char *argv[]);
void		error(void);

// elements.c

t_number	*new_elem_simple(int value);
t_number	*new_elem(int value, ssize_t weight);
t_number	*copy_elem(t_number *tnumber);

// order.c

void		order(t_list **lst);

// LIBFT A USAR

int			ft_lstsize(t_list *lst);

t_list		*ft_lstnew(void *content);
t_list		*ft_lstlast(t_list *lst);

void		ft_lstadd_front(t_list **lst, t_list *new);
void		ft_lstadd_back(t_list **lst, t_list *new);

#endif
