#include "fdf.h"

int 	key_press(int keycode, t_env *env)
{
	printf("key_press: %i\n", keycode);
	if (keycode == 13)
		env->keys.w = 1;
	if (keycode == 1)
		env->keys.s = 1;
	if (keycode == 0)
		env->keys.a = 1;
	if (keycode == 2)
		env->keys.d = 1;
	if (keycode == 12)
		env->keys.q = 1;
	if (keycode == 14)
		env->keys.e = 1;
	if (keycode == 69)
		env->keys.plus = 1;
	if (keycode == 78)
		env->keys.minus = 1;
	return (keycode);
}

int 	key_release(int keycode, t_env *env)
{
	printf("key_release: %i\n", keycode);
	if (keycode == 13)
		env->keys.w = 0;
	if (keycode == 1)
		env->keys.s = 0;
	if (keycode == 0)
		env->keys.a = 0;
	if (keycode == 2)
		env->keys.d = 0;
	if (keycode == 12)
		env->keys.q = 0;
	if (keycode == 14)
		env->keys.e = 0;
	if (keycode == 69)
		env->keys.plus = 0;
	if (keycode == 78)
		env->keys.minus = 0;
	return (keycode);
}

int		handle_mouse(int button, int x, int y, t_env *env)
{
	printf("button: %i\n", button);
	if (button == 5)
	{
		scale_xy(env->grid, 1.1);
		scale_z(env->grid, 1.1);
	}
	if (button == 4)
	{
		scale_xy(env->grid, .9);
		scale_z(env->grid, .9);
	}
	mlx_destroy_image(env->mlx, env->img_data.img);
	env->img_data = make_img(env->mlx, env->w, env->h);
	draw_points(env);
	mlx_put_image_to_window(env->mlx, env->win, env->img_data.img, 0, 0);
	return (button);
}
