#include "fdf.h"

t_env	*make_env(char *filename)
{
	t_env *env;
	int fd;

	printf("make_env1\n");
	env = (t_env *)ft_memalloc(sizeof(t_env));
	fd = open(filename, O_RDWR);
	env->grid = *make_grid(fd);
	printf("make_env2\n");
	env->mlx = mlx_init();
	env->img_data = make_img(env->mlx, 1000, 1000);
	env->win = mlx_new_window(env->mlx, 1000, 1000, "fdf");
	return (env);
}

t_img	make_img(void *mlx, int x, int y)
{
	t_img result;

	printf("make_img1\n");
	result.img = mlx_new_image(mlx, x, y);
	printf("make_img2\n");
	result.data = mlx_get_data_addr(result.img, &result.bits,
		&result.size_line, &result.endian);
	result.width = x;
	result.height = y;
	return (result);
}
