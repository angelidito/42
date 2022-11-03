/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libstack3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcruz-na <dcruz-na@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 19:04:15 by dcruz-na          #+#    #+#             */
/*   Updated: 2022/10/20 19:47:16 by dcruz-na         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_b(t_list **s1, t_list **s2)
{
	t_list	*last;
	t_list	*lst;

	last = ft_lstlast(*s1);
	if (!last)
		return ;
	if ((*s1)->next == NULL)
		*s1 = NULL;
	else
	{
		lst = *s1;
		while (lst->next->next != NULL)
			lst = lst->next;
		lst->next = NULL;
	}
	ft_lstadd_back(s2, last);
	write(1, "pb\n", 3);
}

void	rotate_a(t_list **s1)
{
	t_list	*lst;
	t_list	*last;

	if (ft_lstsize(*s1) < 2)
		return ;
	lst = *s1;
	while (lst->next->next != NULL)
		lst = lst->next;
	last = lst->next;
	lst->next = NULL;
	lst = *s1;
	*s1 = last;
	last->next = lst;
	write(1, "ra\n", 3);
}

void	rotate_b(t_list **s1)
{
	t_list	*lst;
	t_list	*last;

	if (ft_lstsize(*s1) < 2)
		return ;
	lst = *s1;
	while (lst->next->next != NULL)
		lst = lst->next;
	last = lst->next;
	lst->next = NULL;
	lst = *s1;
	*s1 = last;
	last->next = lst;
	write(1, "rb\n", 3);
}

void	rotate(t_list **s1)
{
	t_list	*lst;
	t_list	*last;

	if (ft_lstsize(*s1) < 2)
		return ;
	lst = *s1;
	while (lst->next->next != NULL)
		lst = lst->next;
	last = lst->next;
	lst->next = NULL;
	lst = *s1;
	*s1 = last;
	last->next = lst;
}

void	minibucle(t_list **lst, t_list **s2, int *j)
{
	while (ft_lstsize(*s2))
		push_a(lst, s2);
	*j = (*j) << 1;
}
