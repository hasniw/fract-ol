/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 03:40:18 by wahasni           #+#    #+#             */
/*   Updated: 2019/05/02 06:36:11 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/libft.h"
# include "math.h"
# include <stdio.h>
# include "mlx.h"

# define WIDTH 1000

/*
** MACRO : KEY CODES
*/

# define KEY_ESCAPE 53
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define NUMBER_1 18
# define NUMBER_2 19
# define NUMBER_3 20
# define NUMBER_4 21
# define NUMBER_5 23

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
	// int         pause;
	int         color;
	int         color_value;
	double      zoom;
	double      x1;
	double      y1;
}               t_args;

/*
** PRINT FRACTAL
*/

int		print_fract(t_args *args);
void	init_fract(char *str, t_args *args);

/*
** ACTIONS
*/

void	move(int key, t_args *args);
void	zoom(int x, int y, t_args *args);
void	dezoom(int x, int y, t_args *args);


/*
** COLORS
*/

void	color_input(int key, t_args *args);
void	color(t_mlx *mlx, t_var *var, t_args *args, int i);
void	color_split(t_mlx *mlx, t_var *var, int i);


/*
** MLX - EVENT
*/

int		mouse_hook(int key, int x, int y, void *args);
void	destroy_window(t_mlx *mlx);
int		key_hook(int key, void *args);


/*
** MANDELBROT
*/

int		print_mandelbrot(t_args *args);
void	calc_mandelbrot(t_mlx *mlx, t_var *var, t_args *args);
void	init_mandelbrot(t_args *args);

#endif