/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 03:40:18 by wahasni           #+#    #+#             */
/*   Updated: 2019/05/01 23:13:02 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/libft.h"
# include "math.h"
# include <stdio.h>
# include "mlx.h"

# define WIDTH 1000

typedef struct	s_var
{
	int			x;
    int			y;
    int			y_max;
    double		c_r;
    double		c_i;
    double		z_r;
    double		z_i;
}				t_var;

typedef struct      s_mlx
{
	int			    bpp;
	int			    sizeline;
	int			    endian;
	void		    *mlx_p;
	void		    *win_p;
	void		    *img_p;
	unsigned int	*tab;
}				    t_mlx;

typedef struct  s_args
{
    void        *mlx_ptr;
    void        *win_ptr;
    t_mlx       *mlx;
	t_var		*var;
    int			fract;
    int         it_max;
	int         pause;
	int         color;
	int         color_value;
	double      zoom;
	double      x1;
	double      y1;
}               t_args;

int     deal_mouse(int mouse, int x, int y, t_args *args);
int     deal_key(int key, t_args *args);
int		print_mandelbrot(t_args *args);
void	init_mandelbrot(t_args *args);
void	destroy_window(t_mlx *mlx);
void	move(int key, t_args *args);
void	color_input(int key, t_args *args);
int		print_fract(t_args *args);
int		mouse_hook(int key, int x, int y, void *args);

#endif