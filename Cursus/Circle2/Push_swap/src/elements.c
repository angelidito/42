/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 15:32:00 by angmarti          #+#    #+#             */
/*   Updated: 2022/11/05 15:58:34 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

t_elem	*newelem(int value)
{
	t_elem	*elem;

	elem = calloc(1, sizeof(t_elem));
	if (!elem)
		return (NULL);
	elem->value = value;
	elem->weight = -1;
	return (elem);
}
