/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libstack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danicn <danicn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 11:48:48 by danicn            #+#    #+#             */
/*   Updated: 2022/10/15 17:56:47 by danicn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **list)
{
	t_list	*iter;
	t_list	*aux;

	if (!list || (*list)->next == NULL)
		return ;
	if ((*list)->next->next == NULL)
	{
		aux = (*list);
		*list = (*list)->next;
		(*list)->next = aux;
		aux->next = NULL;
	}
	else
	{
		iter = *list;
		while (iter->next->next->next != NULL)
			iter = iter->next;
		aux = iter->next;
		iter->next = iter->next->next;
		iter->next->next = aux;
		aux->next = NULL;
	}
}

void	swap_a(t_list **list)
{
	t_list	*iter;
	t_list	*aux;

	if (!list || (*list)->next == NULL)
		return ;
	if ((*list)->next->next == NULL)
	{
		aux = (*list);
		*list = (*list)->next;
		(*list)->next = aux;
		aux->next = NULL;
	}
	else
	{
		iter = *list;
		while (iter->next->next->next != NULL)
			iter = iter->next;
		aux = iter->next;
		iter->next = iter->next->next;
		iter->next->next = aux;
		aux->next = NULL;
	}
	write(1, "sa\n", 3);
}

void	swap_b(t_list **list)
{
	t_list	*iter;
	t_list	*aux;

	if (!list || (*list)->next == NULL)
		return ;
	if ((*list)->next->next == NULL)
	{
		aux = (*list);
		*list = (*list)->next;
		(*list)->next = aux;
		aux->next = NULL;
	}
	else
	{
		iter = *list;
		while (iter->next->next->next != NULL)
			iter = iter->next;
		aux = iter->next;
		iter->next = iter->next->next;
		iter->next->next = aux;
		aux->next = NULL;
	}
	write(1, "sb\n", 3);
}

void	swap_ab(t_list **list, t_list **list2)
{
	swap(list);
	swap(list2);
	write(1, "ss\n", 3);
}

void	push_a(t_list **s1, t_list **s2)
{
	t_list	*last;
	t_list	*lst;

	last = ft_lstlast(*s2);
	if ((*s2)->next == NULL)
		*s2 = NULL;
	else
	{
		lst = *s2;
		while (lst->next->next != NULL)
			lst = lst->next;
		lst->next = NULL;
	}
	ft_lstadd_back(s1, last);
	write(1, "pa\n", 3);
}
