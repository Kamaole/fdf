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

t_grid	make_grid(int fd)
{
	char	*line;
	char	*buff;
	t_grid	grid;
	int		xlen;
	int		ylen;

	xlen = 0;
	ylen = 0;
	buff = "";
	while (get_next_line(fd, &line))
	{
		if (!xlen)
			xlen = get_count(line, ' ');
		if (get_count(line, ' ') != xlen)
			exit(0);
		buff = ft_strjoin(ft_strjoin(buff, " "), line);
		ylen++;
	}
	set_points(&grid, buff, xlen, ylen);
	ft_strdel(&buff);
	return (grid);
}

void	set_points(t_grid *grid, char *buff, int xlen, int ylen)
{
	int i;
	int x;
	int y;
	char **split;

	i = 0;
	y = 0;
	grid->xlen = xlen;
	grid->ylen = ylen;
	split = ft_strsplit(buff, ' ');
	grid->points = (t_point **)ft_memalloc(sizeof(t_point *) * ylen);
	while (y < ylen)
	{
		x = -1;
		grid->points[y] = (t_point *)ft_memalloc(sizeof(t_point) * xlen);
		while (++x < xlen)
			grid->points[y][x] = make_point(x, y, ft_atoi(split[i++]));
		y++;
	}
	ft_memdel((void **)split);
}

t_point	make_point(float x, float y, float z)
{
	t_point point;
	int		color;

	color = get_color(z);
	point.x = x;
	point.y = y;
	point.z = z;
	point.color.r = color & 0xFF;
	point.color.g = (color >> 8) & 0xFF;
	point.color.b = (color >> 16) & 0xFF;
	return (point);
}
