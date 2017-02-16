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

void	put_line(t_env *env, t_line line)
{
	t_linevars vars;

	vars.dx = abs(line.x1 - line.x0);
	vars.dy = abs(line.y1 - line.y0);
	vars.sx = (line.x0 < line.x1) ? 1 : -1;
	vars.sy = (line.y0 < line.y1) ? 1 : -1;
	vars.err = (vars.dx > vars.dy ? vars.dx : -(vars.dy)) / 2;
	while (!(line.x0 == line.x1 && line.y0 == line.y1))
	{
		pixel_to_img(env->img_data, line.x0, line.y0, RGB_PURP);
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
	pixel_to_img(env->img_data, line.x0, line.y0, RGB_PURP);
}
