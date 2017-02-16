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

int		main(int argc, char **argv)
{
	t_env *env = make_env(argv[1]);
	pixel_to_img(env->img_data, 10, 10, RGB_PURP);
	scale_xy(env->grid, 10);
	scale_z(env->grid, 10);
	int x = 0;
	int y = 0;
	printf("main1\n");
	rotate_x(env->grid, 1);
	printf("main2\n");
	rotate_y(env->grid, 1);
	printf("main3\n");
	draw_points(env);
	printf("main4\n");
	mlx_put_image_to_window(env->mlx, env->win, env->img_data.img, 0, 0);
	mlx_loop(env->mlx);
	return (1);
}
