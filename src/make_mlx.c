/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 19:34:33 by rmatos            #+#    #+#             */
/*   Updated: 2016/12/09 19:34:52 by rmatos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_mlx	*make_mlx(int x, int y, char *str)
{
	void	*mlx;
	void	*win;
	t_mlx	*result;

	mlx = mlx_init();
	win = mlx_new_window(mlx, x, y, str);
	result = (t_mlx *)ft_memalloc(sizeof(t_mlx));
	result->mlx = mlx;
	result->win = win;
	return (result);
}
