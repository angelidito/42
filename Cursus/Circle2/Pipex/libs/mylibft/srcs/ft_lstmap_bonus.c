/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 14:43:02 by angmarti          #+#    #+#             */
/*   Updated: 2022/12/16 13:59:01 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

/**
 * Iterate through the list, apply the function to each element, 
 * and return a new list
 * 
 * @param lst the list to iterate over
 * @param f a function that takes a pointer to a list element and returns 
 * a pointer to a new list element
 * @param del a function that takes a pointer to a single element of the list 
 * and frees the memory of that element.
 * 
 * @return A new list with the same content as the original list, but with 
 * the content of each element being the result of the function f.
 */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;

	if (!lst || !f)
		return (NULL);
	new = ft_lstnew(f(lst->content));
	if (!new)
	{
		del(&(new->content));
		new = ft_lstmap(lst->next, f, del);
	}
	else
		new->next = ft_lstmap(lst->next, f, del);
	return (new);
}
