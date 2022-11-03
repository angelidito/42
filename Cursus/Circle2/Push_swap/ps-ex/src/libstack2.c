/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libstack2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcruz-na <dcruz-na@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 18:59:45 by dcruz-na          #+#    #+#             */
/*   Updated: 2022/10/20 19:51:19 by dcruz-na         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_rr(t_list **s1, t_list **s2)
{
	rotate(s1);
	rotate(s2);
	write(1, "rr\n", 3);
}

void	rrotate_a(t_list **s1)
{
	t_list	*last;
	t_list	*lst;

	if (ft_lstsize(*s1) < 2)
		return ;
	last = ft_lstlast(*s1);
	last->next = *s1;
	lst = (*s1)->next;
	(*s1)->next = NULL;
	*s1 = lst;
	write(1, "rra\n", 4);
}

void	rrotate_b(t_list **s1)
{
	t_list	*last;
	t_list	*lst;

	if (ft_lstsize(*s1) < 2)
		return ;
	last = ft_lstlast(*s1);
	last->next = *s1;
	lst = (*s1)->next;
	(*s1)->next = NULL;
	*s1 = lst;
	write(1, "rrb\n", 4);
}

void	rrotate(t_list **s1)
{
	t_list	*last;
	t_list	*lst;

	if (ft_lstsize(*s1) < 2)
		return ;
	last = ft_lstlast(*s1);
	last->next = *s1;
	lst = (*s1)->next;
	(*s1)->next = NULL;
	*s1 = lst;
}

void	rrotate_rr(t_list **s1, t_list **s2)
{
	rrotate(s1);
	rrotate(s2);
	write(1, "rrr\n", 4);
}
