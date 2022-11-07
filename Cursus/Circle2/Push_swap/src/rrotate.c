/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:58:54 by angmarti          #+#    #+#             */
/*   Updated: 2022/11/07 16:10:39 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"


//	rra : reverse rotate a - desplaza hacia abajo todos los elementos del stack
//		a una posición, de forma que el último elemento se convierte en 
//		el primero.
//	rrb : reverse rotate b - desplaza hacia abajo todos los elementos del stack
//		b una posición, de forma que el último elemento se convierte en 
//		el primero.
//	rrr : reverse rotate a y reverse rotate b - desplaza al mismo tiempo todos 
//		los elementos del stack a y del stack b una posición hacia abajo, 
//		de forma que el último elemento se convierte en el primero.

void	rrotate(t_list **stack)
{
	t_list	*bottom;

	bottom = *stack;
	*stack = bottom->next;
	bottom->next = NULL;
	ft_lstadd_back(stack, bottom);
}

