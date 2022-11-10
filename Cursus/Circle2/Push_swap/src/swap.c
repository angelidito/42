/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:59:03 by angmarti          #+#    #+#             */
/*   Updated: 2022/11/09 14:07:48 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

/**
 * It swaps the first two elements of the stack (AKA last of the list)
 * 
 * @param stack a pointer to the stack
 * 
 * @return 1 if the swap was successful, 0 if it was not.
 */
int	swap(t_list **stack)
{
	t_list	*top1;
	t_list	*top2;

	if (ft_lstsize(*stack) < 2)
		return (0);
	top1 = lstremovelast(stack);
	top2 = lstremovelast(stack);
	ft_lstadd_back(stack, top1);
	ft_lstadd_back(stack, top2);
	return (1);
}

/**
 * It swaps the first two elements of the stack (AKA last of the list).
 * Prints 'sa\n' to the standard output if did it.
 * 
 * @param stack a pointer to the stack/list
 */
void	sa(t_list **stack)
{
	if (swap(stack))
		write(1, "sa\n", 3);
}

/**
 * It swaps the first two elements of the stack (AKA last of the list).
 * Prints 'sb\n' to the standard output if did it.
 * 
 * @param stack a pointer to the stack/list
 */
void	sb(t_list **stack)
{
	if (swap(stack))
		write(1, "sb\n", 3);
}

/**
 * It swaps the first two elements of both stacks (AKA lasts of the lists)
 * Prints 'ss\n' to the standard output if did it.
 * 
 * @param a a pointer to a stack/list
 * @param b a pointer to another stack/list
 */
void	ss(t_list **a, t_list **b)
{
	if (swap(a) || swap(b))
		write(1, "ss\n", 3);
}
