/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_julia.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 05:52:07 by wahasni           #+#    #+#             */
/*   Updated: 2019/05/09 20:44:16 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			julia_hook(int x, int y, void *args)
{
	if (((t_args *)args)->pause == 0 && ((t_args *)args)->fract == 2)
	{
		((t_args *)args)->var->c_r = (double)x / 500 - 1.3;
		((t_args *)args)->var->c_i = (double)y / 500 - 1.3;
		print_julia(args);
	}
	return (0);
}

void		init_julia(t_args *args)
{
	args->x1 = -1.9;
	args->y1 = -1.5;
	args->zoom = 300;
	args->it_max = 50;
	if (args->pause == 0)
		args->pause = 0;
	else
		args->pause = 1;
	args->var->c_r = 0.285;
	args->var->c_i = 0.01;
}

void		algo_julia(t_mlx *mlx, t_var *var, t_args *args)
{
	int		i;
	double	tmp;

	i = 0;
	var->z_r = var->x / args->zoom + args->x1;
	var->z_i = var->y / args->zoom + args->y1;
	while (var->z_r * var->z_r + var->z_i *
			var->z_i < 4 && i++ < args->it_max)
	{
		tmp = var->z_r;
		var->z_r = var->z_r * var->z_r - var->z_i * var->z_i + var->c_r;
		var->z_i = 2 * var->z_i * tmp + var->c_i;
	}
	if (args->color != 1)
		if (i == args->it_max)
			mlx->tab[var->y * WIDTH + var->x] = 0;
		else
			mlx->tab[var->y * WIDTH + var->x] = i * args->color_value;
	else
		color(mlx, var, args, i);
}

int			print_julia(t_args *args)
{
	args->var->x = 0;
	bzero(args->mlx->tab, WIDTH * WIDTH);
	while (args->var->x < WIDTH)
	{
		args->var->y = 0;
		while (args->var->y < WIDTH)
		{
			algo_julia(args->mlx, args->var, args);
			args->var->y++;
		}
		args->var->x++;
	}
	mlx_put_image_to_window(args->mlx->mlx_p, args->mlx->win_p,
			args->mlx->img_p, 0, 0);
	return (1);
}
