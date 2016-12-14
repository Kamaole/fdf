/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xy_keys.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 17:03:17 by rmatos            #+#    #+#             */
/*   Updated: 2016/12/10 17:04:21 by rmatos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	xkey(t_prog *prog)
{
	void	*mlx;
	void	*win;
	t_grid	*grid;

	mlx = prog->mlx_struct->mlx;
	win = prog->mlx_struct->win;
	grid = prog->grid;
	mlx_clear_window(mlx, win);
	apply_xrot(grid, ROT_SPEED);
	draw_grid(grid, prog->mlx_struct);
}

void	neg_xkey(t_prog *prog)
{
	void	*mlx;
	void	*win;
	t_grid	*grid;

	mlx = prog->mlx_struct->mlx;
	win = prog->mlx_struct->win;
	grid = prog->grid;
	mlx_clear_window(mlx, win);
	apply_xrot(grid, -ROT_SPEED);
	draw_grid(grid, prog->mlx_struct);
}

void	ykey(t_prog *prog)
{
	void	*mlx;
	void	*win;
	t_grid	*grid;

	mlx = prog->mlx_struct->mlx;
	win = prog->mlx_struct->win;
	grid = prog->grid;
	mlx_clear_window(mlx, win);
	apply_yrot(grid, ROT_SPEED);
	draw_grid(grid, prog->mlx_struct);
}

void	neg_ykey(t_prog *prog)
{
	void	*mlx;
	void	*win;
	t_grid	*grid;

	mlx = prog->mlx_struct->mlx;
	win = prog->mlx_struct->win;
	grid = prog->grid;
	mlx_clear_window(mlx, win);
	apply_yrot(grid, -ROT_SPEED);
	draw_grid(grid, prog->mlx_struct);
}
