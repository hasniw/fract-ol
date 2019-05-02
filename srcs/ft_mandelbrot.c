/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 05:51:36 by wahasni           #+#    #+#             */
/*   Updated: 2019/05/01 22:56:30 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	bzero_tab(unsigned int *tab)
{
	int	i;

	i = 0;
	while (i < WIDTH * WIDTH)
	{
		tab[i] = 0;
		i++;
	}
}

void	color_split(t_mlx *mlx, t_var *var, int i)
{
	if (i % 16 == 7)
		mlx->tab[var->y * WIDTH + var->x] = 3767761;
	else if (i % 16 == 8)
		mlx->tab[var->y * WIDTH + var->x] = 8828389;
	else if (i % 16 == 9)
		mlx->tab[var->y * WIDTH + var->x] = 13888760;
	else if (i % 16 == 10)
		mlx->tab[var->y * WIDTH + var->x] = 15854015;
	else if (i % 16 == 11)
		mlx->tab[var->y * WIDTH + var->x] = 16304479;
	else if (i % 16 == 12)
		mlx->tab[var->y * WIDTH + var->x] = 16755200;
	else if (i % 16 == 13)
		mlx->tab[var->y * WIDTH + var->x] = 13402112;
	else if (i % 16 == 14)
		mlx->tab[var->y * WIDTH + var->x] = 10049280;
	else if (i % 16 == 15)
		mlx->tab[var->y * WIDTH + var->x] = 6960131;
}

void	color(t_mlx *mlx, t_var *var, t_args *args, int i)
{
	if (i == args->it_max)
		mlx->tab[var->y * WIDTH + var->x] = 0;
	else if (i % 16 == 0)
		mlx->tab[var->y * WIDTH + var->x] = 4333071;
	else if (i % 16 == 1)
		mlx->tab[var->y * WIDTH + var->x] = 1640218;
	else if (i % 16 == 2)
		mlx->tab[var->y * WIDTH + var->x] = 590127;
	else if (i % 16 == 3)
		mlx->tab[var->y * WIDTH + var->x] = 263241;
	else if (i % 16 == 4)
		mlx->tab[var->y * WIDTH + var->x] = 1892;
	else if (i % 16 == 5)
		mlx->tab[var->y * WIDTH + var->x] = 797834;
	else if (i % 16 == 6)
		mlx->tab[var->y * WIDTH + var->x] = 1594033;
	else
		color_split(mlx, var, i);
}

void	color_input(int key, t_args *args)
{
	if (key == 18)
		args->color = 1;
	else
		args->color = 2;
	if (key == 19)
		args->color_value = 9999;
	if (key == 20)
		args->color_value = 333333;
	if (key == 21)
		args->color_value = 555555;
}


void		init_mandelbrot(t_args *args)
{
	args->x1 = -2;
	args->y1 = -1.5;
	args->zoom = 300;
	args->it_max = 50;
}

static void	calc_mandelbrot(t_mlx *mlx, t_var *var, t_args *args)
{
	int				i;
	double			tmp;

	var->c_r = var->x / args->zoom + args->x1;
	var->c_i = var->y / args->zoom + args->y1;
	var->z_r = 0;
	var->z_i = 0;
	i = 0;
	while (var->z_r * var->z_r + var->z_i *
			var->z_i < 4 && i < args->it_max)
	{
		tmp = var->z_r;
		var->z_r = var->z_r * var->z_r - var->z_i *
			var->z_i + var->c_r;
		var->z_i = 2 * tmp * var->z_i + var->c_i;
		i++;
	}
	if (args->color != 1)
		if (i == args->it_max)
			mlx->tab[var->y * WIDTH + var->x] = 0;
		else
			mlx->tab[var->y * WIDTH + var->x] = i * args->color_value;
	else
		color(mlx, var, args, i);
}

int			print_mandelbrot(t_args *args)
{
	// static int i = 0;
	char	*it;

	// printf("i : %d\n", i);
	// i++;
	args->var->x = 0;
	bzero_tab(args->mlx->tab);
	// printf("l\n");
	while (args->var->x < WIDTH)
	{
		args->var->y = 0;
		while (args->var->y < WIDTH)
		{
			calc_mandelbrot(args->mlx, args->var, args);
			args->var->y++;
		}
		args->var->x++;
		// printf("var->x : %d\n", args->var->x++);
	}
	// printf("blabla\n");
	mlx_put_image_to_window(args->mlx->mlx_p, args->mlx->win_p,
			args->mlx->img_p, 0, 0);
	// printf("Yeah\n");
	mlx_string_put(args->mlx->mlx_p, args->mlx->win_p, 20, 20, 16777215,
			"ITERATION MAX : ");
	// printf("flan\n");
	if (!(it = ft_itoa(args->it_max)))
		return (0);
	// printf("poke\n");
	// mlx_string_put(data->id->mlx_p, data->id->win_p, 180, 20, 16777215, it);
	// free(it);
	// printf("baba\n");
	// mlx_loop(args->mlx_ptr);
	return (1);
}