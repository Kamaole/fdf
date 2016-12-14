/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 19:28:44 by rmatos            #+#    #+#             */
/*   Updated: 2016/12/10 17:07:30 by rmatos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	handle_key(int keycode, void *param)
{
	t_prog	*pr;

	pr = (t_prog *)param;
	if (keycode == 53)
		exit(0);
	if (keycode == 123)
		ykey(pr);
	if (keycode == 124)
		neg_ykey(pr);
	if (keycode == 126)
		xkey(pr);
	if (keycode == 125)
		neg_xkey(pr);
	if (keycode == 0)
		neg_zkey(pr);
	if (keycode == 2)
		zkey(pr);
	return (0);
}

int	handle_expose(void *param)
{
	t_prog	*prog;
	void	*mlx;
	void	*win;
	t_grid	*grid;

	prog = (t_prog *)param;
	mlx = prog->mlx_struct->mlx;
	win = prog->mlx_struct->win;
	grid = prog->grid;
	mlx_clear_window(mlx, win);
	draw_grid(grid, prog->mlx_struct);
	return (0);
}
