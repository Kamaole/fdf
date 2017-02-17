/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 19:44:29 by rmatos            #+#    #+#             */
/*   Updated: 2016/12/10 17:16:35 by rmatos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include "libft.h"
# include "get_next_line.h"
# include <math.h>
# include <stdio.h>

# define RGB_PURP 0xBE00FF
# define RGB_BLACK 0x000000
# define ROT_SPEED .05

typedef struct	s_point
{
	float		x;
	float		y;
	float		z;

}				t_point;

typedef struct	s_line
{
	int			x0;
	int			y0;
	int			x1;
	int			y1;
}				t_line;

typedef struct	s_grid
{
	int			xy_scale;
	int			z_scale;
	int			xlen;
	int			ylen;
	t_point		**points;
}				t_grid;

typedef struct	s_img
{
	void		*img;
	char		*data;
	int			bits;
	int			size_line;
	int			endian;
	int			height;
	int			width;
}				t_img;

typedef struct	s_env
{
	t_grid		grid;
	t_img		img_data;
	void 		*mlx;
	void 		*win;
	int			w;
	int			h;
	int			half_w;
	int			half_h;
}				t_env;

typedef	struct	s_rot
{
	double		x;
	double		y;
	double		z;
	double		d;
	double		theta;
}				t_rot;

typedef struct	s_linevars
{
	int			dx;
	int			dy;
	int			sx;
	int			sy;
	int			err;
	int			err_tmp;
}				t_linevars;

t_grid		*make_grid(int fd);
void		set_points(t_grid *grid, char **split, int xlen, int ylen);
t_point		make_point(float x, float y, float z);
void		pixel_to_img(t_img img_data, int x, int y, int color);
void		put_line(t_env *env, t_line line);
t_line		make_line(int x0, int y0, int x1, int y1);
t_img		make_img(void *mlx, int x, int y);
t_env		*make_env(char *filename, int w, int h);
t_img		make_img(void *mlx, int x, int y);
float		mean_x(t_grid grid);
float		mean_y(t_grid grid);
float		mean_z(t_grid grid);
void 		scale_xy(t_grid grid, int scale);
void 		scale_z(t_grid grid, int scale);
t_point		get_center(t_grid grid);
t_line 		line_from_points(t_point p1, t_point p2, int x_off, int y_off);
void 		draw_points(t_env *env);
void 		rotate_x(t_grid grid, float radians);
void 		rotate_y(t_grid grid, float radians);
void 		rotate_z(t_grid grid, float radians);
int			get_xoff(t_env *env);
int			get_yoff(t_env *env);
int 		handle_keys(int keycode, t_env *env);

#endif
