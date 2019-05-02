/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 08:56:13 by pvandamm          #+#    #+#             */
/*   Updated: 2019/05/01 23:19:29 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	destroy_window(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx_p, mlx->win_p);
	free(mlx->tab);
	exit(0);
}

void	move(int key, t_args *args)
{
	if (key == 123)
		args->x1 += 30 / args->zoom;
	if (key == 124)
		args->x1 -= 30 / args->zoom;
	if (key == 125)
		args->y1 -= 30 / args->zoom;
	if (key == 126)
		args->y1 += 30 / args->zoom;
}

void	zoom(int x, int y, t_args *args)
{
	args->x1 = (x / args->zoom + args->x1) - (x / (args->zoom * 1.3));
	args->y1 = (y / args->zoom + args->y1) - (y / (args->zoom * 1.3));
	args->zoom *= 1.3;
	args->it_max++;
}

void	dezoom(int x, int y, t_args *args)
{
	args->x1 = (x / args->zoom + args->x1) - (x / (args->zoom / 1.3));
	args->y1 = (y / args->zoom + args->y1) - (y / (args->zoom / 1.3));
	args->zoom /= 1.3;
	args->it_max--;
}

int		mouse_hook(int key, int x, int y, void *args)
{
	if (key == 4 || key == 1)
		zoom(x, y, ((t_args *)args));
	if (key == 5 || key == 2)
		dezoom(x, y, ((t_args *)args));
	// print_fract(args);
	print_mandelbrot(args);
	return (0);
}
