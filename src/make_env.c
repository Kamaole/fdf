#include "fdf.h"

t_keys	make_keys(void)
{
	t_keys keys;

	keys.w = 0;
	keys.a = 0;
	keys.s = 0;
	keys.d = 0;
	keys.q = 0;
	keys.e = 0;
	keys.plus = 0;
	keys.minus = 0;

	return (keys);
}

t_env	*make_env(char *filename, int w, int h)
{
	t_env	*env;
	int		fd;

	env = (t_env *)ft_memalloc(sizeof(t_env));
	fd = open(filename, O_RDWR);
	env->grid = make_grid(fd);
	env->mlx = mlx_init();
	env->img_data = make_img(env->mlx, 1000, 1000);
	env->win = mlx_new_window(env->mlx, 1000, 1000, "fdf");
	env->w = w;
	env->h = h;
	env->half_w = w / 2;
	env->half_h = h / 2;
	env->keys = make_keys();
	return (env);
}

t_img	make_img(void *mlx, int x, int y)
{
	t_img result;

	result.img = mlx_new_image(mlx, x, y);
	result.data = mlx_get_data_addr(result.img, &result.bits,
		&result.size_line, &result.endian);
	result.width = x;
	result.height = y;
	return (result);
}
