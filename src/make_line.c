/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 19:33:51 by rmatos            #+#    #+#             */
/*   Updated: 2016/12/09 19:33:53 by rmatos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_line	*get_line(t_point *point1, t_point *point2)
{
	t_line *result;

	result = (t_line *)ft_memalloc(sizeof(t_line));
	result->x0 = point1->scaled_x;
	result->x1 = point2->scaled_x;
	result->y0 = point1->scaled_y;
	result->y1 = point2->scaled_y;
	return (result);
}
