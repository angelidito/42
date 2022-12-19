/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 15:32:00 by angmarti          #+#    #+#             */
/*   Updated: 2022/12/19 16:44:22 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

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

	elem = ft_calloc(1, sizeof(t_number));
	if (!elem)
		return (NULL);
	elem->value = value;
	elem->weight = weight;
	return (elem);
}

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
	}
	return (weight);
}
