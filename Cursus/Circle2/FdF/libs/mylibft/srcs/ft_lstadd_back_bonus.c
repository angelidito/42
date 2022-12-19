/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 13:03:29 by angmarti          #+#    #+#             */
/*   Updated: 2022/12/16 13:59:01 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

/**
 * Add a new node to the end of a linked list
 * 
 * @param lst A pointer to the first element of a linked list.
 * @param new the new element to add to the list
 * 
 * @return The address of the first element of the list.
 */
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*node;

	if (!new)
		return ;
	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	node = *lst;
	while (node->next)
		node = node->next;
	node->next = new;
}
