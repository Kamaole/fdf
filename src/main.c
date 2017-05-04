/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 19:29:33 by rmatos            #+#    #+#             */
/*   Updated: 2016/12/14 13:19:54 by rmatos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int		fdf_loop(t_env *env)
{
	draw_points(env);
	mlx_put_image_to_window(env->mlx, env->win, env->img_data.img, 0, 0);
	mlx_destroy_image(env->mlx, env->img_data.img);
	env->img_data = make_img(env->mlx, env->w, env->h);
	return (0);
}

int		main(int argc, char **argv)
{
	t_env *env;

	env = make_env(argv[1], 1000, 1000);
	scale_xy(env->grid, 10);
	scale_z(env->grid, ft_atoi(argv[2]));
	draw_points(env);
	mlx_hook(env->win, 2, 0, key_press, env);
	mlx_hook(env->win, 3, 0, key_release, env);
	mlx_loop_hook(env->mlx, fdf_loop, env);
	mlx_mouse_hook(env->win, handle_mouse, env);
	mlx_put_image_to_window(env->mlx, env->win, env->img_data.img, 0, 0);
	mlx_loop(env->mlx);
	return (1);
}
