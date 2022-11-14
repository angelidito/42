/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 15:32:00 by angmarti          #+#    #+#             */
/*   Updated: 2022/11/09 17:24:07 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

// /**
//  * It creates a new t_number with the given value and set weight at -1
//  *
//  * @param value the value of the node
//  *
//  * @return A pointer to a new t_number struct.
//  */
// t_number	*new_number_weightless(int value)
// {
// 	t_number	*elem;

// 	elem = calloc(1, sizeof(t_number));
// 	if (!elem)
// 		return (NULL);
// 	elem->value = value;
// 	elem->weight = -1;
// 	return (elem);
// }

/**
 * It creates a new t_number with the given value and weight
 * 
 * @param value the value of the node
 * @param weight The weight of the edge.
 * 
 * @return A pointer to a new t_number struct.
 */
t_number	*new_number(int value, ssize_t weight)
{
	t_number	*elem;

	elem = calloc(1, sizeof(t_number));
	if (!elem)
		return (NULL);
	elem->value = value;
	elem->weight = weight;
	return (elem);
}

// /**
//  * It copies a t_number struct to a new one.
//  * 
//  * @param tnumber the number to be copied.
//  * 
//  * @return A copy of the t_number struct.
//  */
// t_number	*copy_number(t_number *tnumber)
// {
// 	t_number	*elem;

// 	elem = calloc(1, sizeof(t_number));
// 	if (!elem)
// 		return (NULL);
// 	elem->value = tnumber->value;
// 	elem->weight = tnumber->weight;
// 	return (elem);
// }

/**
 * It returns the value of the t_number pointed by the context t_list
 * 
 * @param lst The list elem to get the value from.
 * 
 * @return The value of the number in the list.
 */
int	numvalue(t_list *lst)
{
	return (((t_number *)(lst)->content)->value);
}

/**
 * It returns the weight of the t_number pointed by the context t_list
 * 
 * @param lst The list elem to get the weight from.
 * 
 * @return The weight of the number in the list.
 */
ssize_t	numweight(t_list *lst)
{
	return (((t_number *)(lst)->content)->weight);
}

/**
 * It sets the weight of the t_number pointed by the context t_list
 * 
 * @param lst The list elem to set the weight.
 * @param weight The weight to set.
 */
void	setweight(t_list *lst, ssize_t weight)
{
	((t_number *)(lst)->content)->weight = weight;
}

ssize_t	setweights(t_list **lst)
{
	int		i;
	ssize_t	weight;
	t_list	*min;
	t_list	*current;

	i = 0;
	weight = -1;
	while (i++ < ft_lstsize(*lst))
	{
		min = *lst;
		while (min && numweight(min) != -1)
			min = min->next;
		current = min->next;
		while (current)
		{
			if (numweight(current) == -1 && numvalue(min) > numvalue(current))
				min = current;
			current = current->next;
		}
		setweight(min, ++weight);
		// printf("%d tiene peso %zd\n", numvalue(min), weight);
	}
	return (weight);
}
