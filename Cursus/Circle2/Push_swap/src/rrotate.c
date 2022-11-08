/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:58:54 by angmarti          #+#    #+#             */
/*   Updated: 2022/11/08 15:32:59 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

/**
 * It takes the bottom element of the stack and moves it to the top.
 * It won't rotate if the list if empty or has one only element.
 * 
 * @param stack A pointer to the stack to be rotated.
 * 
 * @return 1 if the rotation was successful, 0 otherwise.
 */
int	rrotate(t_list **stack)
{
	t_list	*bottom;

	if (ft_lstsize(*stack) < 2)
		return (0);
	// bottom = *stack;
	// *stack = bottom->next;
	// bottom->next = NULL;
	bottom = lstremovefirst(stack);
	ft_lstadd_back(stack, bottom);
	return (1);
}

/**
 * It rotates the stack to the left, and prints "rra\n" to the 
 * standard output if the rotation was successful.
 * 
 * @param a the stack to rotate
 */
void	rra(t_list **a)
{
	if (rrotate(a))
		write(1, "rra\n", 4);
}

/**
 * It rotates the stack to the left, and prints "rrb\n" to the
 * standard output if the rotation was successful.
 * 
 * @param b the stack to rotate
 */
void	rrb(t_list **b)
{
	if (rrotate(b))
		write(1, "rrb\n", 4);
}

/**
 * It rotates both stacks to the left, and prints "rrr\n" to the 
 * standard output if the rotation was successful.
 * 
 * @param a a stack to rotate
 * @param b another stack to rotate
 */
void	rrr(t_list **a, t_list **b)
{
	if (a == b)
		write(1, "THAT'S CHEATING SOAB\n", 18);
	if (rrotate(a) || rrotate(b))
		write(1, "rrr\n", 4);
}
