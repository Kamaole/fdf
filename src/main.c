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

int		main(int argc, char **argv)
{
	int			fd;
	t_prog		*pr;

	fd = open(argv[1], O_RDWR);
	pr = (t_prog *)ft_memalloc(sizeof(t_prog));
	if (usage(argc, fd))
		return (-1);
	pr->grid = make_grid(fd, atoi(argv[2]), atoi(argv[3]));
	if (pr->grid != NULL)
	{
		pr->mlx_struct = make_mlx(1920, 1080, "fdf");
		draw_grid(pr->grid, pr->mlx_struct);
		mlx_hook(pr->mlx_struct->win, 2, 0, handle_key, pr);
		mlx_expose_hook(pr->mlx_struct->win, handle_expose, pr);
		mlx_loop(pr->mlx_struct->mlx);
	}
	else
		ft_putstr("error! not rectangle!\n");
	return (1);
}
