#include "fdf.h"

int		get_xoff(t_env *env)
{
	t_point center;

	center = get_center(env->grid);
	return (env->half_w - center.x);
}

int		get_yoff(t_env *env)
{
	t_point center;

	center = get_center(env->grid);
	return (env->half_h - center.y);
}
