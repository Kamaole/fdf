/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   relative_center.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 19:35:34 by rmatos            #+#    #+#             */
/*   Updated: 2016/12/09 19:35:48 by rmatos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double	mean_x(t_grid *grid)
{
	int i;
	int sum;

	i = 0;
	sum = 0;
	while (grid->points[i])
		sum += grid->points[i++]->orig_x;
	return (sum / i);
}

double	mean_y(t_grid *grid)
{
	int i;
	int sum;

	i = 0;
	sum = 0;
	while (grid->points[i])
		sum += grid->points[i++]->orig_y;
	return (sum / i);
}

double	mean_z(t_grid *grid)
{
	int i;
	int sum;

	i = 0;
	sum = 0;
	while (grid->points[i])
		sum += grid->points[i++]->orig_z;
	return (sum / i);
}

t_point	*get_center(t_grid *grid)
{
	return (make_point(mean_x(grid), mean_y(grid), mean_z(grid)));
}
