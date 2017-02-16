#include "fdf.h"

t_line 	line_from_points(t_point p1, t_point p2)
{
	t_line line;

	line.x0 = p1.x;
	line.y0 = p1.y;
	line.x1 = p2.x;
	line.y1 = p2.y;
	return (line);
}

void 	draw_points(t_env *env)
{
	int x;
	int y;

	y = 0;
	printf("env->grid.xlen: %i\n", env->grid.xlen);
	printf("env->grid.ylen: %i\n", env->grid.ylen);
	while (y < env->grid.ylen)
	{
		x = 0;
		while (x < env->grid.xlen)
		{
			printf("x:y - %i:%i\n", x, y);
			if (y != env->grid.ylen - 1)
				put_line(env, line_from_points(env->grid.points[y][x], env->grid.points[y + 1][x]));
			if (x != env->grid.xlen - 1)
				put_line(env, line_from_points(env->grid.points[y][x], env->grid.points[y][x + 1]));
			x++;
		}
		y++;
	}
}
