/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dragon_douady.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 04:04:54 by wahasni           #+#    #+#             */
/*   Updated: 2019/05/05 23:22:44 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		init_dragon_douady(t_args *args)
{
	args->x1 = -1.8;
	args->y1 = -1.5;
	args->zoom = 300;
	args->it_max = 50;
	args->pause = 0;
	args->var->c_r = -0.123;
	args->var->c_i = 0.745;
}

void		algo_dragon_douady(t_mlx *mlx, t_var *var, t_args *args)
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

int			print_dragon_douady(t_args *args)
{
	args->var->x = 0;
	bzero_tab(args->mlx->tab);
	while (args->var->x < WIDTH)
	{
		args->var->y = 0;
		while (args->var->y < WIDTH)
		{
			algo_dragon_douady(args->mlx, args->var, args);
			args->var->y++;
		}
		args->var->x++;
	}
	mlx_put_image_to_window(args->mlx->mlx_p, args->mlx->win_p,
			args->mlx->img_p, 0, 0);
	return (1);
}
