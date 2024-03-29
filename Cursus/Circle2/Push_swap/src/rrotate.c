/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:58:54 by angmarti          #+#    #+#             */
/*   Updated: 2022/11/14 17:10:51 by angmarti         ###   ########.fr       */
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
	bottom = lstremovefirst(stack);
	ft_lstadd_back(stack, bottom);
	return (1);
}

/**
 * It rotates the stack to the left, and prints "rra\n" to the 
 * standard output if the rotation was successful.
 * 
 * @param stack the stack to rotate
 */
void	rra(t_list **stack)
{
	if (rrotate(stack))
		ft_putstr_fd("rra\n", 1);
}

/**
 * It rotates the stack to the left, and prints "rrb\n" to the
 * standard output if the rotation was successful.
 * 
 * @param stack the stack to rotate
 */
void	rrb(t_list **stack)
{
	if (rrotate(stack))
		ft_putstr_fd("rrb\n", 1);
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
		ft_putstr_fd("THAT'S CHEATING SOAB\n", 1);
	if (rrotate(a) || rrotate(b))
		ft_putstr_fd("rrr\n", 1);
}
