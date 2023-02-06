/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 13:38:12 by angmarti          #+#    #+#             */
/*   Updated: 2022/12/16 13:59:01 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

/**
 * It takes a pointer to a pointer to a linked list, and a pointer to a 
 * function that takes a pointer to a void and returns nothing. It then 
 * iterates through the linked list, calling the function on each element, 
 * and then frees the element
 * 
 * @param lst A pointer to the first element of a linked list.
 * @param del pointer to a function that frees the memory of the element's 
 * content.
 * 
 * @return A pointer to the first element of the new list.
 */
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*aux;

	if (!(*lst) || !del)
		return ;
	while (*lst)
	{
		aux = *lst;
		*lst = (*lst)->next;
		ft_lstdelone(aux, del);
	}
}
