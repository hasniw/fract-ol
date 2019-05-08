/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_multibrot_z5.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 22:24:17 by wahasni           #+#    #+#             */
/*   Updated: 2019/05/08 00:58:20 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		init_multibrot_z5(t_args *args)
{
	args->x1 = -1.9;
	args->y1 = -1.5;
	args->zoom = 300;
	args->it_max = 50;
}

void		algo_multibrot_z5(t_mlx *mlx, t_var *var, t_args *args)
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
		var->z_r = pow(var->z_r, 5) - 10 * pow(var->z_r, 3) * pow(var->z_i, 2) + 5 * var->z_r * pow(var->z_i, 4) + var->c_r;
		var->z_i = 5 * pow(tmp, 4) * var->z_i - 10 *  pow(tmp, 2) * pow(var->z_i, 3) + pow (var->z_i, 5) + var->c_i;
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

int			print_multibrot_z5(t_args *args)
{
	args->var->x = 0;
	bzero_tab(args->mlx->tab);
	while (args->var->x < WIDTH)
	{
		args->var->y = 0;
		while (args->var->y < WIDTH)
		{
			algo_multibrot_z5(args->mlx, args->var, args);
			args->var->y++;
		}
		args->var->x++;
	}
	mlx_put_image_to_window(args->mlx->mlx_p, args->mlx->win_p,
			args->mlx->img_p, 0, 0);
	return (1);
}
