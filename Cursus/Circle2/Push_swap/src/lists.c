/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 12:02:37 by angmarti          #+#    #+#             */
/*   Updated: 2022/11/08 15:51:22 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

/**
 * It removes the last element of a list (AKA first/top of the stack)
 * and returns it
 * 
 * @param lst a list
 * 
 * @return The one who was the last element of the list.
 */
t_list	*lstremovelast(t_list **lst)
{
	t_list	*last;
	t_list	*aux;
	int		size;

	if (!lst)
		return (NULL);
	size = ft_lstsize(*lst);
	if (size == 0)
		return (NULL);
	last = ft_lstlast(*lst);
	if (size == 1)
	{
		*lst = NULL;
		return (last);
	}
	aux = *lst;
	while (aux->next != last)
		aux = aux->next;
	aux->next = NULL;
	return (last);
}

/**
 * It removes the first element of a list (AKA last/bottom of the stack)
 * and returns it
 * 
 * @param lst a list
 * 
 * @return The one who was the first element of the list.
 */
t_list	*lstremovefirst(t_list **lst)
{
	t_list	*first;
	int		size;

	if (!lst)
		return (NULL);
	size = ft_lstsize(*lst);
	if (size == 0)
		return (NULL);
	first = *lst;
	*lst = first->next;
	first->next = NULL;
	return (first);
}
