/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 13:19:39 by angmarti          #+#    #+#             */
/*   Updated: 2022/09/01 16:59:28 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Delete the content of a list and free the list
 * 
 * @param lst The address of a pointer to a link.
 * @param del a pointer to a function that takes a single argument and returns 
 * nothing.
 */
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	(*del)(lst->content);
	free(lst);
}
