/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_algorithm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:54:38 by angmarti          #+#    #+#             */
/*   Updated: 2022/11/10 13:17:21 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

// void	write_list(void *content);

/**
 * It checks if the lists are ordered
 * 
 * @param a the first list
 * @param b the second list
 * 
 * @return Returns 1 if the lists are ordered, 0 otherwise.
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

/**
 * It sorts a list of numbers by their binary representation.
 * 
 * @param radix the radix of the number system; must be a power of 2
 * @param a the stack to be sorted
 * @param b the auxiliar stack
 */
void	orderbyradix(ssize_t radix, t_list **a, t_list **b)
{
	int		i;
	int		size;
	ssize_t	weight;

	i = -1;
	size = ft_lstsize(*a);
	while (++i < size)
	{
		if (isordered(a, b))
			break ;
		weight = numweight(ft_lstlast(*a));
		// while (++j < radix)
		// 	weight /= 2;   // weight = weight > 1;
		if (!(weight / radix % 2)) // (!(weight & 1))
			pb(a, b);
		else
			ra(a);
	}
	while (ft_lstsize(*b))
		pa(a, b);
	// ft_lstiter(*a, *write_list);
	// printf("\n");
}

/**
 * It takes a list of numbers, and orders them by their binary representation.
 * 
 * @param a the list of numbers to be sorted
 * @param b the list of numbers that are not in order
 * @param maxweight the highest value in the list
 */
void	start_algorithim(t_list **a, t_list **b, ssize_t maxweight)
{
	ssize_t	radix;
	ssize_t	radix_max;

	radix = 1;
	radix_max = 8;
	while (radix <= maxweight)
	{
		// printf("init radix: %llu\nmaxweight: %zd\n", radix, maxweight);
		orderbyradix(radix, a, b);
		radix *= 2;
	}
}
