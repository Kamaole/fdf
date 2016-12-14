/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 19:37:28 by rmatos            #+#    #+#             */
/*   Updated: 2016/12/09 19:41:04 by rmatos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	apply_rot(t_grid *grid, double x, double y, double z)
{
	apply_xrot(grid, x);
	apply_yrot(grid, y);
	apply_zrot(grid, z);
	apply_center(grid);
}

void	apply_xrot(t_grid *grid, double radians)
{
	int			i;
	t_pointmath	*math;
	t_point		*cen;

	math = (t_pointmath *)ft_memalloc(sizeof(t_pointmath));
	i = 0;
	cen = get_center(grid);
	if (radians == 0.)
		return ;
	while (grid->points[i])
	{
		math->y = grid->points[i]->scaled_y - cen->y;
		math->z = grid->points[i]->scaled_z - cen->scaled_z;
		math->d = hypot(math->y, math->z);
		math->theta = atan2(math->y, math->z) + radians;
		grid->points[i]->scaled_z = cen->scaled_z + math->d * cos(math->theta);
		grid->points[i]->scaled_y = cen->y + math->d * sin(math->theta);
		i++;
	}
	math->y = grid->center->scaled_y - cen->y;
	math->z = grid->center->scaled_z - cen->scaled_z;
	math->d = hypot(math->y, math->z);
	math->theta = atan2(math->y, math->z) + radians;
	grid->center->scaled_z = cen->scaled_z + math->d * cos(math->theta);
	grid->center->scaled_y = cen->y + math->d * sin(math->theta);
}

void	apply_yrot(t_grid *grid, double radians)
{
	int			i;
	t_pointmath	*math;
	t_point		*cen;

	i = 0;
	math = (t_pointmath *)ft_memalloc(sizeof(t_pointmath));
	cen = get_center(grid);
	if (radians == 0.)
		return ;
	while (grid->points[i])
	{
		math->x = grid->points[i]->scaled_x - cen->x;
		math->z = grid->points[i]->scaled_z - cen->scaled_z;
		math->d = hypot(math->x, math->z);
		math->theta = atan2(math->x, math->z) + radians;
		grid->points[i]->scaled_z = cen->scaled_z + math->d * cos(math->theta);
		grid->points[i]->scaled_x = cen->x + math->d * sin(math->theta);
		i++;
	}
	math->x = grid->center->scaled_x - cen->x;
	math->z = grid->center->scaled_z - cen->scaled_z;
	math->d = hypot(math->x, math->z);
	math->theta = atan2(math->x, math->z) + radians;
	grid->center->scaled_z = cen->scaled_z + math->d * cos(math->theta);
	grid->center->scaled_x = cen->x + math->d * sin(math->theta);
}

void	apply_zrot(t_grid *grid, double radians)
{
	int			i;
	t_pointmath	*math;
	t_point		*center;

	i = 0;
	math = (t_pointmath *)ft_memalloc(sizeof(t_pointmath));
	center = get_center(grid);
	if (radians == 0.)
		return ;
	while (grid->points[i])
	{
		math->x = grid->points[i]->scaled_x - center->x;
		math->y = grid->points[i]->scaled_y - center->y;
		math->d = hypot(math->y, math->x);
		math->theta = atan2(math->y, math->x) + radians;
		grid->points[i]->scaled_x = center->x + math->d * cos(math->theta);
		grid->points[i]->scaled_y = center->y + math->d * sin(math->theta);
		i++;
	}
	math->x = grid->center->scaled_x - center->x;
	math->y = grid->center->scaled_y - center->y;
	math->d = hypot(math->y, math->x);
	math->theta = atan2(math->y, math->x) + radians;
	grid->center->scaled_x = center->x + math->d * cos(math->theta);
	grid->center->scaled_y = center->y + math->d * sin(math->theta);
}
