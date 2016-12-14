/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_center.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 19:00:24 by rmatos            #+#    #+#             */
/*   Updated: 2016/12/09 19:02:04 by rmatos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		get_xoffset(t_grid *grid)
{
	int		x;
	int		y;
	t_point	*point;

	x = grid->xlen / 2;
	y = grid->ylen / 2;
	point = grid->center;
	return (960 - point->scaled_x);
}

int		get_yoffset(t_grid *grid)
{
	int		x;
	int		y;
	t_point	*point;

	x = grid->xlen / 2;
	y = grid->ylen / 2;
	point = grid->center;
	return (540 - point->scaled_y);
}

void	apply_center(t_grid *grid)
{
	int i;
	int x;
	int y;

	i = 0;
	x = get_xoffset(grid);
	y = get_yoffset(grid);
	{
		grid->points[i]->scaled_x += x;
		grid->points[i]->scaled_y += y;
		i++;
	}
}
