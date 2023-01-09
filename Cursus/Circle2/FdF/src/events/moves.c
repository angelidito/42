/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarti <angmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 17:42:17 by angmarti          #+#    #+#             */
/*   Updated: 2023/01/09 19:50:42 by angmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/fdf.h"

int	desviate(double variation, t_vars *vars)
{
	vars->map->desv += variation;
	if (vars->map->desv < -1)
	{
		vars->map->desv = -1;
		return (-1);
	}
	else if (vars->map->desv > 1)
	{
		vars->map->desv = 1;
		return (1);
	}
	if (vars->map->desv + 2 > 2)
		vars->map->scale = -0.41 * vars->map->desv + 1.41;
	else
		vars->map->scale = 0.41 * vars->map->desv + 1.41;
	// else
	// 	vars->map->scale -= variation * compensation;
	// else if (variation > 0 && vars->map->desv < variation)
	// 	vars->map->scale -= variation * compensation;
	// else if (variation > 0)
	// 	vars->map->scale += variation * compensation;

	if (vars->map->scale < 1)
	{
		vars->map->scale = 1;
		breakpoint();
	}
	printf("desv  : %f\n", vars->map->desv);
	printf("scale : %f\n", vars->map->scale);

	return (0);
}