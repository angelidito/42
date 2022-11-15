/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:59:00 by angmarti          #+#    #+#             */
/*   Updated: 2022/11/15 12:06:19 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

/**
 * It takes the last element of the list and moves it to the front.
 * It won't rotate if the list if empty or has one only element.
 * 
 * @param stack A pointer to the stack to be rotated.
 * 
 * @return 1 if the rotation was successful, 0 otherwise.
 */
int	rotate(t_list **stack)
{
	t_list	*top;

	if (ft_lstsize(*stack) < 2)
		return (0);
	top = lstremovelast(stack);
	ft_lstadd_front(stack, top);
	return (1);
}

/**
 * It rotates the stack to the right, and prints "ra\n" to the 
 * standard output if the rotation was successful.
 * 
 * @param stack the stack to rotate
 */
void	ra(t_list **stack)
{
	if (rotate(stack))
		ft_putstr_fd("ra\n", 1);
}

/**
 * It rotates the stack to the right, and prints "rb\n" to the
 * standard output if the rotation was successful.
 * 
 * @param stack the stack to rotate
 */
void	rb(t_list **stack)
{
	if (rotate(stack))
		ft_putstr_fd("rb\n", 1);
}

/**
 * It rotates both stacks to the right, and prints "rr\n" to the 
 * standard output if the rotation was successful.
 * 
 * @param a a stack to rotate
 * @param b another stack to rotate
 */
void	rr(t_list **a, t_list **b)
{
	if (a == b)
		ft_putstr_fd("THAT'S CHEATING\n", 1);
	if (rotate(a) || rotate(b))
		ft_putstr_fd("rr\n", 1);
}
