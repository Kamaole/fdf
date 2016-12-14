/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 19:03:03 by rmatos            #+#    #+#             */
/*   Updated: 2016/12/10 17:06:16 by rmatos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_line(t_mlx *group, t_line *line, int x, int y)
{
	t_linevars *vars;

	vars = (t_linevars *)ft_memalloc(sizeof(t_linevars));
	vars->dx = abs(line->x1 - line->x0);
	vars->dy = abs(line->y1 - line->y0);
	vars->sx = (line->x0 < line->x1) ? 1 : -1;
	vars->sy = (line->y0 < line->y1) ? 1 : -1;
	vars->err = (vars->dx > vars->dy ? vars->dx : -(vars->dy)) / 2;
	while (!(line->x0 == line->x1 && line->y0 == line->y1))
	{
		mlx_pixel_put(group->mlx, group->win, line->x0 + x,
			line->y0 + y, RGB_PURP);
		vars->err_tmp = vars->err;
		if (vars->err_tmp > -(vars->dx))
		{
			vars->err -= vars->dy;
			line->x0 += vars->sx;
		}
		if (vars->err_tmp < vars->dy)
		{
			vars->err += vars->dx;
			line->y0 += vars->sy;
		}
	}
	mlx_pixel_put(group->mlx, group->win, line->x0 + x, line->y0 + y, RGB_PURP);
}

int		draw_horiz(t_grid *grid, int x, int y)
{
	int z;

	z = get_point(grid, x, y)->orig_z;
	if (get_point(grid, x - 1, y) && get_point(grid, x - 1, y)->orig_z == z)
		return (0);
	return (1);
}

int		draw_vert(t_grid *grid, int x, int y)
{
	int z;

	z = get_point(grid, x, y)->orig_z;
	if (get_point(grid, x, y - 1) && get_point(grid, x, y - 1)->orig_z == z)
		return (0);
	return (1);
}

void	draw_grid(t_grid *grid, t_mlx *mlx_struct)
{
	int		x;
	int		y;
	t_point	*point;
	t_point	*right;
	t_point	*down;

	y = -1;
	while (++y < grid->ylen)
	{
		x = -1;
		while (++x < grid->xlen)
		{
			point = get_point(grid, x, y);
			right = get_rightpoint(grid, x, y);
			down = get_downpoint(grid, x, y);
			if (right)
				put_line(mlx_struct, get_line(point, right),
					get_xoffset(grid), get_yoffset(grid));
			if (down)
				put_line(mlx_struct, get_line(point, down),
					get_xoffset(grid), get_yoffset(grid));
		}
	}
}
