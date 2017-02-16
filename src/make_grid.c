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

t_grid	*make_grid(int fd)
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
	printf("make_grid1\n");
	set_points(grid, ft_strsplit(buff, ' '), xlen, ylen);
	printf("make_grid2\n");
	return (grid);
}

void	set_points(t_grid *grid, char **split, int xlen, int ylen)
{
	int i;
	int x;
	int y;

	i = 0;
	y = 0;
	grid->xlen = xlen;
	grid->ylen = ylen;
	grid->points = (t_point **)ft_memalloc(sizeof(t_point *) * ylen);
	printf("xlen:%i\n", xlen);
	printf("ylen:%i\n", ylen);
	while (y < ylen)
	{
		x = -1;
		grid->points[y] = (t_point *)ft_memalloc(sizeof(t_point) * xlen);
		while (++x < xlen)
		{
			grid->points[y][x] = make_point(x, y, ft_atoi(split[i++]));
			printf("%f:%f:%f\n", grid->points[y][x].x, grid->points[y][x].y, grid->points[y][x].z);
		}
		y++;
	}
}

t_point	make_point(float x, float y, float z)
{
	t_point point;

	point.x = x;
	point.y = y;
	point.z = z;
	return (point);
}
