/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_scale.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 19:02:21 by rmatos            #+#    #+#             */
/*   Updated: 2016/12/09 19:02:45 by rmatos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	apply_zscale(t_grid *grid, int scale)
{
	int i;

	i = 0;
	while (grid->points[i])
		grid->points[i++]->scaled_z *= scale;
	grid->z_scale = scale;
}

void	apply_scale(t_grid *grid, int scale, int z_scale)
{
	int i;

	i = 0;
	while (grid->points[i])
	{
		grid->points[i]->scaled_x = grid->points[i]->x * scale;
		grid->points[i]->scaled_y = grid->points[i]->y * scale;
		grid->points[i]->orig_x = grid->points[i]->scaled_x;
		grid->points[i]->orig_y = grid->points[i]->scaled_y;
		i++;
	}
	grid->center->scaled_x = grid->center->x * scale;
	grid->center->scaled_y = grid->center->y * scale;
	grid->center->orig_x = grid->center->scaled_x;
	grid->center->orig_y = grid->center->scaled_y;
	grid->xy_scale = scale;
	apply_zscale(grid, z_scale);
}
