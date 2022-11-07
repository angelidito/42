/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:59:00 by angmarti          #+#    #+#             */
/*   Updated: 2022/11/07 16:08:27 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//	ra : rotate a - desplaza hacia arriba todos los elementos del stack a una
//		posición, de forma que el primer elemento se convierte en el último.
//	rb : rotate b - desplaza hacia arriba todos los elementos del stack b una
//		posición, de forma que el primer elemento se convierte en el último.
//	rr : rotate a y rotate b - desplaza al mismo tiempo todos los elementos del
//		stack a y del stack b una posición hacia arriba, de forma que el primer
//		elemento se convierte en el último.

#include "../incs/push_swap.h"

/**
 * It takes the last element of the list and puts it at the front
 * 
 * @param stack a pointer to a pointer to the first element of the list
 */
void	rotate(t_list **stack)
{
	t_list	*top;
	t_list	*aux;

	top = ft_lstlast(*stack);
	aux = *stack;
	while (aux->next != top)
		aux = aux->next;
	aux->next = NULL;
	ft_lstadd_front(stack, top);
}
