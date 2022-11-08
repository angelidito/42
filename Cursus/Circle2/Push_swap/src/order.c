/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:47:08 by angmarti          #+#    #+#             */
/*   Updated: 2022/11/08 16:05:14 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void	order3numbers(t_list **a)
{
	int	n2;
	int	n1;
	int	n0;

	n2 = ((t_number *)(*a)->content)->value;
	n1 = ((t_number *)(*a)->next->content)->value;
	n0 = ((t_number *)(*a)->next->next->content)->value;
	if (n0 < n1 && n1 < n2)
		return ;
	else if (n2 < n0 && n0 < n1)
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
	else
		write(1, "???????????????????????????????????????\n", 40);
}

void	order(t_list **stack)
{
	int	size;

	size = ft_lstsize(*stack);
	if (size == 2
		&& get_number(*stack)->value > get_number(ft_lstlast(*stack))->value)
		return ;
	else if (size == 2)
		ra(stack);
	else if (size == 3)
		order3numbers(stack);
}
