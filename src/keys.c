#include "fdf.h"

int 	handle_keys(int keycode, t_env *env)
{
	if (keycode == 13)
		rotate_x(env->grid, .05);
	if (keycode == 1)
		rotate_x(env->grid, -.05);
	if (keycode == 2)
		rotate_y(env->grid, -.05);
	if (keycode == 0)
		rotate_y(env->grid, .05);
	if (keycode == 12)
		rotate_z(env->grid, -.05);
	if (keycode == 14)
		rotate_z(env->grid, .05);
	env->img_data = make_img(env->mlx, env->w, env->h);
	draw_points(env);
	mlx_put_image_to_window(env->mlx, env->win, env->img_data.img, 0, 0);
	return (keycode);
}
