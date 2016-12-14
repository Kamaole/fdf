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

# define RGB_PURP 0xBE00FF
# define RGB_BLACK 0x000000
# define ROT_SPEED .05

typedef struct	s_point
{
	int			x;
	int			y;
	double		scaled_x;
	double		scaled_y;
	double		scaled_z;
	double		orig_x;
	double		orig_y;
	double		orig_z;

}				t_point;

typedef struct	s_grid
{
	int			xy_scale;
	int			z_scale;
	int			xlen;
	int			ylen;
	double		rotx;
	double		roty;
	double		rotz;
	t_point		**points;
	t_point		*center;
}				t_grid;

typedef	struct	s_mlx
{
	void		*mlx;
	void		*win;
}				t_mlx;

typedef	struct	s_pointmath
{
	double		x;
	double		y;
	double		z;
	double		d;
	double		theta;
}				t_pointmath;

typedef struct	s_linevars
{
	int			dx;
	int			dy;
	int			sx;
	int			sy;
	int			err;
	int			err_tmp;
}				t_linevars;

typedef struct	s_line
{
	int			x0;
	int			y0;
	int			x1;
	int			y1;
}				t_line;

typedef struct	s_prog
{
	t_grid		*grid;
	t_mlx		*mlx_struct;
}				t_prog;

t_mlx			*make_mlx(int x, int y, char *str);
t_grid			*make_grid(int fd, int xy_scale, int z_scale);
void			apply_rot(t_grid *grid, double x, double y, double z);
int				get_ylen(char **points);
void			set_points(t_grid *grid, char **split, int xlen, int ylen);
void			apply_xrot(t_grid *grid, double radians);
void			apply_yrot(t_grid *grid, double radians);
void			apply_zrot(t_grid *grid, double radians);
t_point			*get_point(t_grid *grid, int x, int y);
t_point			*get_rightpoint(t_grid *grid, int x, int y);
t_point			*get_downpoint(t_grid *grid, int x, int y);
t_point			*make_point(double x, double y, double z);
void			apply_zscale(t_grid *grid, int scale);
void			apply_scale(t_grid *grid, int scale, int z_scale);
double			mean_x(t_grid *grid);
double			mean_y(t_grid *grid);
double			mean_z(t_grid *grid);
t_point			*get_center(t_grid *grid);
int				get_xoffset(t_grid *grid);
int				get_yoffset(t_grid *grid);
void			apply_center(t_grid *grid);
void			put_line(t_mlx *mlx_struct, t_line *line, int x_off, int y_off);
int				draw_horiz(t_grid *grid, int x, int y);
int				draw_vert(t_grid *grid, int x, int y);
void			draw_grid(t_grid *grid, t_mlx *mlx_struct);
int				usage(int argc, int fd);
int				handle_key(int keycode, void *param);
int				handle_expose(void *param);
t_line			*get_line(t_point *point1, t_point *point2);
void			neg_xkey(t_prog *prog);
void			xkey(t_prog *prog);
void			neg_ykey(t_prog *prog);
void			ykey(t_prog *prog);
void			neg_zkey(t_prog *prog);
void			zkey(t_prog *prog);

#endif
