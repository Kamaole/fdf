#include "fdf.h"

t_line	make_line(int x0, int y0, int x1, int y1)
{
	t_line line;

	line.x0 = x0;
	line.x1 = x1;
	line.y0 = y0;
	line.y1 = y1;
	return (line);
}

t_color	make_gradient(t_color c1, t_color c2, float percent)
{
	t_color result;

	result.r = (c1.r - c2.r) * percent + c1.r;
	result.g = (c1.g - c2.g) * percent + c1.g;
	result.b = (c1.b - c2.b) * percent + c1.b;
	return (result);
}

void	put_line(t_env *env, t_line line)
{
	t_linevars vars;
	t_line tmp;

	vars.dx = abs(line.x1 - line.x0);
	vars.dy = abs(line.y1 - line.y0);
	vars.sx = (line.x0 < line.x1) ? 1 : -1;
	vars.sy = (line.y0 < line.y1) ? 1 : -1;
	vars.err = (vars.dx > vars.dy ? vars.dx : -(vars.dy)) / 2;
	float dist = sqrt((line.x1 - line.x0) * (line.x1 - line.x0) + (line.y1 - line.y0) * (line.y1 - line.y0));
	tmp = line;
	while (!(line.x0 == line.x1 && line.y0 == line.y1))
	{
		float cur_dist= sqrt((tmp.x0 - line.x0) * (tmp.x0 - line.x0) + (tmp.y0 - line.y0) * (tmp.y0 - line.y0));
		float percent = cur_dist / dist;
		pixel_to_img(env->img_data, line.x0, line.y0, make_gradient(line.c0, line.c1, percent));
		vars.err_tmp = vars.err;
		if (vars.err_tmp > -(vars.dx))
		{
			vars.err -= vars.dy;
			line.x0 += vars.sx;
		}
		if (vars.err_tmp < vars.dy)
		{
			vars.err += vars.dx;
			line.y0 += vars.sy;
		}
	}
	pixel_to_img(env->img_data, line.x0, line.y0, make_gradient(line.c0, line.c1, 1));
}
