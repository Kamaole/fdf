/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 19:43:28 by rmatos            #+#    #+#             */
/*   Updated: 2016/12/14 13:19:42 by rmatos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	usage(int argc, int fd)
{
	if (argc != 4)
	{
		ft_putstr("Usage: ./fdf [map pat] [xy scale] [z scale]\n");
		return (-1);
	}
	if (fd < 0)
	{
		ft_putstr("Error! Not a valid file!\n");
		return (-2);
	}
	return (0);
}
