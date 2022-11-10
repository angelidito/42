/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:59:04 by angmarti          #+#    #+#             */
/*   Updated: 2022/11/09 16:17:55 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

/**
 * It removes the first element of the stack pointed to by sender and adds it to
 * the top of the stack pointed to by host if sender is not empty.
 * 
 * @param sender the stack from which we're taking the element
 * @param host the stack to push to
 * 
 * @return 1 if the operation was successful, 0 otherwise.
 */
int	push(t_list **sender, t_list **host)
{
	t_list	*elem;

	if (!ft_lstsize(*sender))
		return (0);
	elem = lstremovelast(sender);
	ft_lstadd_back(host, elem);
	return (1);
}

/**
 * It pushes the first element of the stack pointed to by `b` to 
 * the stack pointed to by `a`, if `b` is not empty. It will print
 * 'pa\n' if did it.
 * 
 * @param a The stack to push to 
 * @param b The stack that pushes
 */
void	pa(t_list **a, t_list **b)
{
	if (push(b, a))
		write(1, "pa\n", 3);
}

/**
 * It pushes the first element of the stack pointed to by `a` to 
 * the stack pointed to by `b` if `a` is not empty. It will print
 * 'pb\n' if did it.
 * 
 * @param a The stack that pushes
 * @param b The stack to push to
 */
void	pb(t_list **a, t_list **b)
{
	if (push(a, b))
		write(1, "pb\n", 3);
}
