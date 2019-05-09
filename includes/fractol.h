/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 03:40:18 by wahasni           #+#    #+#             */
/*   Updated: 2019/05/09 20:42:56 by wahasni          ###   ########.fr       */
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
# define SPACE 49
# define LETTER_Q 12
# define LETTER_W 13
# define LETTER_E 14
# define LETTER_R 15
# define LETTER_T 17
# define LETTER_Y 16
# define LETTER_U 32
# define LETTER_I 34

/*
** MACRO : POW OF Z ==> MULTIBROT
*/

# define NB 3

typedef struct		s_var
{
	int				x;
	int				y;
	int				y_max;
	double			c_r;
	double			c_i;
	double			z_r;
	double			z_i;
}					t_var;

typedef struct		s_mlx
{
	int				bpp;
	int				sizeline;
	int				endian;
	void			*mlx_p;
	void			*win_p;
	void			*img_p;
	unsigned int	*tab;
}					t_mlx;

typedef struct		s_args
{
	void			*mlx_ptr;
	void			*win_ptr;
	t_mlx			*mlx;
	t_var			*var;
	int				fract;
	int				it_max;
	int				pause;
	int				color;
	int				color_value;
	double			zoom;
	double			x1;
	double			y1;
}					t_args;

t_args				*ft_init(void);

/*
** PRINT FRACTAL
*/

int					print_fract(t_args *args);
void				init_fract(char *str, t_args *args);
void				init_fract2(char *str, t_args *args);

/*
** ACTIONS
*/

void				move(int key, t_args *args);
void				zoom(int x, int y, t_args *args);
void				dezoom(int x, int y, t_args *args);

/*
** COLORS
*/

void				color_input(int key, t_args *args);
void				color(t_mlx *mlx, t_var *var, t_args *args, int i);
void				color2(t_mlx *mlx, t_var *var, int i);

/*
** MLX - EVENT
*/

int					mouse_hook(int key, int x, int y, void *args);
void				destroy_window(t_mlx *mlx);
int					key_hook(int key, void *args);
void				letter_hook(int key, void *args);
void				letter_hook2(int key, void *args);

/*
** MANDELBROT
*/

int					print_mandelbrot(t_args *args);
void				algo_mandelbrot(t_mlx *mlx, t_var *var, t_args *args);
void				init_mandelbrot(t_args *args);

/*
** JULIA
*/

int					print_julia(t_args *args);
void				algo_julia(t_mlx *mlx, t_var *var, t_args *args);
void				init_julia(t_args *args);
int					julia_hook(int x, int y, void *args);

/*
** BURNINGSHIP
*/

int					print_burningship(t_args *args);
void				algo_burningship(t_mlx *mlx, t_var *var, t_args *args);
void				init_burningship(t_args *args);

/*
** DENDRITE
*/

int					print_dendrite(t_args *args);
void				algo_dendrite(t_mlx *mlx, t_var *var, t_args *args);
void				init_dendrite(t_args *args);

/*
** DISQUE DE SIEGEL
*/

int					print_disque_siegel(t_args *args);
void				algo_disque_siegel(t_mlx *mlx, t_var *var, t_args *args);
void				init_disque_siegel(t_args *args);

/*
** DRAGON DE DOUADY
*/

int					print_dragon_douady(t_args *args);
void				algo_dragon_douady(t_mlx *mlx, t_var *var, t_args *args);
void				init_dragon_douady(t_args *args);

/*
** BASILIQUE
*/

int					print_basilique(t_args *args);
void				algo_basilique(t_mlx *mlx, t_var *var, t_args *args);
void				init_basilique(t_args *args);

/*
** MULTIBROT
*/

void				init_multibrot(t_args *args);
void				algo_multibrot(t_mlx *mlx, t_var *var, t_args *args);
int					print_multibrot(t_args *args);

#endif
