#include "fdf.h"

t_line 	line_from_points(t_point p1, t_point p2, int x_off, int y_off)
{
	t_line line;

	line.x0 = p1.x + x_off;
	line.y0 = p1.y + y_off;
	line.x1 = p2.x + x_off;
	line.y1 = p2.y + y_off;
	return (line);
}

void 	draw_points(t_env *env)
{
	int x;
	int y;
	int x_off;
	int y_off;

	y = 0;
	x_off = get_xoff(env);
	y_off = get_yoff(env);
	while (y < env->grid.ylen)
	{
		x = 0;
		while (x < env->grid.xlen)
		{
			if (y != env->grid.ylen - 1)
				put_line(env, line_from_points(env->grid.points[y][x], env->grid.points[y + 1][x], x_off, y_off));
			if (x != env->grid.xlen - 1)
				put_line(env, line_from_points(env->grid.points[y][x], env->grid.points[y][x + 1], x_off, y_off));
			x++;
		}
		y++;
	}
}
