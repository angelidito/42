/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 15:32:00 by angmarti          #+#    #+#             */
/*   Updated: 2022/11/08 11:11:44 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

/**
 * It creates a new t_number with the given value and set weight at -1
 * 
 * @param value the value of the node
 * 
 * @return A pointer to a new t_number struct.
 */
t_number	*new_elem_simple(int value)
{
	t_number	*elem;

	elem = calloc(1, sizeof(t_number));
	if (!elem)
		return (NULL);
	elem->value = value;
	elem->weight = -1;
	return (elem);
}

/**
 * It creates a new t_number with the given value and weight
 * 
 * @param value the value of the node
 * @param weight The weight of the edge.
 * 
 * @return A pointer to a new t_number struct.
 */
t_number	*new_elem(int value, ssize_t weight)
{
	t_number	*elem;

	elem = calloc(1, sizeof(t_number));
	if (!elem)
		return (NULL);
	elem->value = value;
	elem->weight = weight;
	return (elem);
}

/**
 * It copies a t_number struct to a new one
 * 
 * @param tnumber the number to be copied
 * 
 * @return A copy of the t_number struct.
 */
t_number	*copy_elem(t_number *tnumber)
{
	t_number	*elem;

	elem = calloc(1, sizeof(t_number));
	if (!elem)
		return (NULL);
	elem->value = tnumber->value;
	elem->weight = tnumber->weight;
	return (elem);
}


t_number	*get_number(t_list *lst)
{
	return ((t_number *)(lst)->content);
}