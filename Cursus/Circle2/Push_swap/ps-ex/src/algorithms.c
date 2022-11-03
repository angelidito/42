/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danicn <danicn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 17:46:35 by danicn            #+#    #+#             */
/*   Updated: 2022/10/15 18:16:58 by danicn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	less_than_six(t_list **s1, t_list **s2, int argc)
{
	if (argc == 3)
	{
		if (*(int *)(*s1)->content < *(int *)(*s1)->next->content)
			swap_a(s1);
	}
	if (argc == 4)
		three_nums(s1);
	if (argc == 5)
		four_nums(s1, s2);
	if (argc == 6)
		five_nums(s1, s2);
}

void	three_nums(t_list **s1)
{
	if (*(int *)(*s1)->content > *(int *)(*s1)->next->content
	&& *(int *)(*s1)->next->content < *(int *)(*s1)->next->next->content
	&& *(int *)(*s1)->content > *(int *)(*s1)->next->next->content)
		swap_a(s1);
	else if (*(int *)(*s1)->content > *(int *)(*s1)->next->content
	&& *(int *)(*s1)->next->content < *(int *)(*s1)->next->next->content
	&& *(int *)(*s1)->content < *(int *)(*s1)->next->next->content)
		rotate_a(s1);
	else if (*(int *)(*s1)->content < *(int *)(*s1)->next->content
	&& *(int *)(*s1)->next->content < *(int *)(*s1)->next->next->content)
	{
		swap_a(s1);
		rrotate_a(s1);
	}
	else if (*(int *)(*s1)->content < *(int *)(*s1)->next->content
	&& *(int *)(*s1)->next->content > *(int *)(*s1)->next->next->content
	&& *(int *)(*s1)->content < *(int *)(*s1)->next->next->content)
		rrotate_a(s1);
	else if (*(int *)(*s1)->content < *(int *)(*s1)->next->content
	&& *(int *)(*s1)->next->content > *(int *)(*s1)->next->next->content
	&& *(int *)(*s1)->content > *(int *)(*s1)->next->next->content)
	{
		rrotate_a(s1);
		swap_a(s1);
	}
}

void	four_nums(t_list **s1, t_list **s2)
{
	push_b(s1, s2);
	three_nums(s1);
	if (*(int *)(*s1)->content < *(int *)ft_lstlast(*s2)->content)
	{
		push_a(s1, s2);
		rotate_a(s1);
	}
	else if (*(int *)(*s1)->next->content < *(int *)ft_lstlast(*s2)->content)
	{
		rrotate_a(s1);
		push_a(s1, s2);
		rotate_a(s1);
		rotate_a(s1);
	}
	else if (*(int *)(*s1)->next->next->content <
	*(int *)ft_lstlast(*s2)->content)
	{
		push_a(s1, s2);
		swap_a(s1);
	}
	else
		push_a(s1, s2);
}

int	largest(t_list *l)
{
	int	n;

	n = *(int *)l->content;
	while (l != NULL)
	{
		if (*(int *)l->content > n)
			n = *(int *)l->content;
		l = l->next;
	}
	return (n);
}

void	five_nums(t_list **s1, t_list **s2)
{
	int	l;
	int	i;

	push_b(s1, s2);
	push_b(s1, s2);
	if (*(int *)ft_lstlast(*s2)->content > *(int *)(*s2)->content)
		swap_b(s2);
	three_nums(s1);
	i = 3;
	while (*(int *)ft_lstlast(*s1)->content
		< *(int *)ft_lstlast(*s2)->content && i)
	{
		rotate_a(s1);
		i--;
	}
	push_a(s1, s2);
	while (*(int *)ft_lstlast(*s1)->content
		< *(int *)ft_lstlast(*s2)->content && i-- > -1)
		rotate_a(s1);
	l = 0;
	push_a(s1, s2);
	l = largest(*s1);
	while (*(int *)((*s1)->content) != l)
		rotate_a(s1);
}
