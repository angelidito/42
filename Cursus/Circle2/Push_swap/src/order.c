/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:47:08 by angmarti          #+#    #+#             */
/*   Updated: 2022/11/10 15:01:03 by angmarti         ###   ########.fr       */
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
		write(1, "???????????????????????????????????????\n", 40);
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
	// printf("maxweight: '%zd'  \n", maxweight);
	start_algorithim(a, b, maxweight);
	ft_lstclear(b, *free);
	free(b);
}
