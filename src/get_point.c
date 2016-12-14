/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_point.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 19:24:27 by rmatos            #+#    #+#             */
/*   Updated: 2016/12/09 19:27:29 by rmatos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	*get_point(t_grid *grid, int x, int y)
{
	int i;

	i = 0;
	while (grid->points[i] != 0)
	{
		if (grid->points[i]->x == x && grid->points[i]->y == y)
			return (grid->points[i]);
		i++;
	}
	return (NULL);
}

t_point	*get_rightpoint(t_grid *grid, int x, int y)
{
	int z;

	z = get_point(grid, x, y)->orig_z;
	if (get_point(grid, x + 1, y) && get_point(grid, x + 1, y)->orig_z != z)
		return (get_point(grid, x + 1, y));
	if (!draw_horiz(grid, x, y))
		return (NULL);
	x++;
	while (get_point(grid, x, y))
	{
		if (get_point(grid, x, y)->orig_z == z)
		{
			if (get_point(grid, x + 1, y)
					&& get_point(grid, x + 1, y)->orig_z != z)
				return (get_point(grid, x, y));
			if (!get_point(grid, x + 1, y))
				return (get_point(grid, x, y));
		}
		x++;
	}
	return (NULL);
}

t_point	*get_downpoint(t_grid *grid, int x, int y)
{
	int z;

	z = get_point(grid, x, y)->orig_z;
	if (get_point(grid, x, y + 1) && get_point(grid, x, y + 1)->orig_z != z)
		return (get_point(grid, x, y + 1));
	if (!draw_vert(grid, x, y))
		return (NULL);
	y++;
	while (get_point(grid, x, y))
	{
		if (get_point(grid, x, y)->orig_z == z)
		{
			if (get_point(grid, x, y + 1)
					&& get_point(grid, x, y + 1)->orig_z != z)
				return (get_point(grid, x, y));
			if (!get_point(grid, x, y + 1))
				return (get_point(grid, x, y));
		}
		y++;
	}
	return (NULL);
}
