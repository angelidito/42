/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:47:08 by angmarti          #+#    #+#             */
/*   Updated: 2022/11/15 16:41:57 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

/**
 * If the numbers are in the wrong order, rotate the stack or swap elemtents 
 * until they are in the right order
 * 
 * @param a the stack
 */
void	order3numbers(t_list **a)
{
	int	n2;
	int	n1;
	int	n0;

	n2 = numvalue((*a));
	n1 = numvalue((*a)->next);
	n0 = numvalue((*a)->next->next);
	if (n2 < n0 && n0 < n1)
		rra(a);
	else if (n1 < n2 && n2 < n0)
		ra(a);
	else if (n0 < n2 && n2 < n1)
	{
		rra(a);
		sa(a);
	}
	else if (n2 < n1 && n1 < n0)
	{
		ra(a);
		sa(a);
	}
	else if (n1 < n0 && n0 < n2)
		sa(a);
	else if (!(n0 < n1 && n1 < n2))
		ft_putstr_fd("???????????????????????????????????????\n", 1);
}

void	order4numbers(t_list **a, t_list **b)
{
	while (numweight(ft_lstlast(*a)))
		ra(a);
	pb(a, b);
	order3numbers(a);
	pa(a, b);
}

void	order_more_numbers(t_list **a, t_list **b, int size, ssize_t maxweight)
{
	if (size == 4)
	{
		while (numweight(ft_lstlast(*a)) != 0)
			ra(a);
		pb(a, b);
		order3numbers(a);
		pa(a, b);
	}
	else if (size == 5)
	{
		if (numweight(*a) == 0)
			rra(a);
		else
			while (numweight(ft_lstlast(*a)) != 0)
				ra(a);
		pb(a, b);
		while (numweight(ft_lstlast(*a)) != 1)
			ra(a);
		pb(a, b);
		order3numbers(a);
		pa(a, b);
		pa(a, b);
	}
	else
		start_algorithim(a, b, maxweight);
}

void	order(t_list **a)
{
	int		size;
	t_list	**b;
	ssize_t	maxweight;

	size = ft_lstsize(*a);
	if (size == 2 && numvalue(*a) > numvalue(ft_lstlast(*a)))
		return ;
	else if (size == 2)
		ra(a);
	else if (size == 3)
		order3numbers(a);
	if (size < 4)
		return ;
	b = calloc(1, sizeof(t_list **));
	if (!b)
	{
		ft_lstclear(a, *free);
		free(a);
		exit(1);
	}
	maxweight = setweights(a);
	if (!isordered(a, b))
		order_more_numbers(a, b, size, maxweight);
	ft_lstclear(b, *free);
	free(b);
}

/**
 * It checks if the lists are ordered.
 * Notice that b list does not have to be empty.
 * 
 * @param a the first list
 * @param b the second list
 * 
 * @return Returns 1 if both of the lists are ordered, 0 otherwise.
 */
int	isordered(t_list **a, t_list **b)
{
	t_list	*e;
	int		ordered;

	if (*a && *b)
		if (numweight(ft_lstlast(*a)) < numweight(ft_lstlast(*b)))
			return (0);
	ordered = 1;
	e = *a;
	while (ordered && e)
	{
		if (e->next && numweight(e) < numweight(e->next))
			ordered = 0;
		e = e->next;
	}
	e = *b;
	while (ordered && e)
	{
		if (e->next && numweight(e) > numweight(e->next))
			ordered = 0;
		e = e->next;
	}
	return (ordered);
}
