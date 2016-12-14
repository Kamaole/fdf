/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 19:31:43 by rmatos            #+#    #+#             */
/*   Updated: 2016/12/09 19:33:02 by rmatos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_grid	*make_grid(int fd, int xy_scale, int z_scale)
{
	char	*line;
	char	*buff;
	t_grid	*grid;
	int		xlen;
	int		ylen;

	xlen = 0;
	ylen = 0;
	buff = "";
	grid = (t_grid *)ft_memalloc(sizeof(t_grid));
	while (get_next_line(fd, &line))
	{
		if (xlen == 0)
			xlen = get_count(line, ' ');
		if (get_count(line, ' ') != xlen)
			return (NULL);
		buff = ft_strjoin(ft_strjoin(buff, " "), line);
		ylen++;
	}
	set_points(grid, ft_strsplit(buff, ' '), xlen, ylen);
	apply_scale(grid, xy_scale, z_scale);
	return (grid);
}

void	set_points(t_grid *grid, char **split, int xlen, int ylen)
{
	int i;
	int x;
	int y;

	i = 0;
	x = 0;
	y = 0;
	grid->xlen = xlen;
	grid->ylen = ylen;
	grid->points = (t_point **)ft_memalloc(sizeof(t_point *)
			* (xlen * ylen + 1));
	while (y < ylen)
	{
		grid->points[i] = make_point(x, y, ft_atoi(split[i]));
		x++;
		if (x == xlen)
		{
			x = 0;
			y++;
		}
		i++;
	}
	grid->points[i] = 0;
	grid->center = make_point(grid->xlen / 2, grid->ylen / 2, 0);
}

int		get_ylen(char **points)
{
	int i;
	int len;

	i = 0;
	len = 0;
	while (points[i])
	{
		if (points[i][0] == 'L')
			len++;
		i++;
	}
	return (len);
}

t_point	*make_point(double x, double y, double z)
{
	t_point *result;

	result = (t_point *)ft_memalloc(sizeof(t_point));
	result->x = x;
	result->y = y;
	result->scaled_z = (double)z;
	result->orig_z = result->scaled_z;
	return (result);
}
