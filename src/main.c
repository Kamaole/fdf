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
	put_line(env, make_line(0, 0, 30, 30));
	mlx_put_image_to_window(env->mlx, env->win, env->img_data.img, 0, 0);
	mlx_loop(env->mlx);
	return (1);
}
