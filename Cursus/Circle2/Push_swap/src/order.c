/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:47:08 by angmarti          #+#    #+#             */
/*   Updated: 2022/11/07 16:10:28 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void	rrotate(t_list **stack);

void	order(t_list **lst)
{
	if (ft_lstsize(*lst) == 2)
		rrotate(lst);
	else
		rrotate(lst);
}
