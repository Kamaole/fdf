/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   z_keys.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 17:07:59 by rmatos            #+#    #+#             */
/*   Updated: 2016/12/10 17:08:25 by rmatos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	zkey(t_prog *prog)
{
	void	*mlx;
	void	*win;
	t_grid	*grid;

	mlx = prog->mlx_struct->mlx;
	win = prog->mlx_struct->win;
	grid = prog->grid;
	mlx_clear_window(mlx, win);
	apply_zrot(grid, ROT_SPEED);
	draw_grid(grid, prog->mlx_struct);
}

void	neg_zkey(t_prog *prog)
{
	void	*mlx;
	void	*win;
	t_grid	*grid;

	mlx = prog->mlx_struct->mlx;
	win = prog->mlx_struct->win;
	grid = prog->grid;
	mlx_clear_window(mlx, win);
	apply_zrot(grid, -ROT_SPEED);
	draw_grid(grid, prog->mlx_struct);
}
