/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fatou_dust.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 00:48:54 by wahasni           #+#    #+#             */
/*   Updated: 2019/05/10 19:06:07 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		init_fatou_dust(t_args *args)
{
	args->x1 = -1.7;
	args->y1 = -1.5;
	args->zoom = 300;
	args->it_max = 50;
}

void		algo_fatou_dust(t_mlx *mlx, t_var *var, t_args *args)
{
	int				i;
	double			tmp;

	var->c_r = -0.76;
	var->c_i = 0.12;
	var->z_r = var->x / args->zoom + args->x1;
	var->z_i = var->y / args->zoom + args->y1;
	i = 0;
	while (var->z_r * var->z_r + var->z_i *
			var->z_i < 4 && i < args->it_max)
	{
		tmp = var->z_r;
		var->z_r = (var->z_r * var->z_r - var->z_i *
			var->z_i) + var->c_r;
		var->z_i = (-1.81 * tmp * var->z_i) + var->c_i;
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

int			print_fatou_dust(t_args *args)
{
	args->var->x = 0;
	bzero(args->mlx->tab, WIDTH * WIDTH);
	while (args->var->x < WIDTH)
	{
		args->var->y = 0;
		while (args->var->y < WIDTH)
		{
			algo_fatou_dust(args->mlx, args->var, args);
			args->var->y++;
		}
		args->var->x++;
	}
	mlx_put_image_to_window(args->mlx->mlx_p, args->mlx->win_p,
			args->mlx->img_p, 0, 0);
	return (1);
}
