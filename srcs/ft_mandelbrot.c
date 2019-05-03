/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 05:51:36 by wahasni           #+#    #+#             */
/*   Updated: 2019/05/03 04:03:06 by wahasni          ###   ########.fr       */
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

void		init_mandelbrot(t_args *args)
{
	args->x1 = -2;
	args->y1 = -1.5;
	args->zoom = 300;
	args->it_max = 50;
}

void	algo_mandelbrot(t_mlx *mlx, t_var *var, t_args *args)
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
	char	*i;

	args->var->x = 0;
	bzero_tab(args->mlx->tab);
	while (args->var->x < WIDTH)
	{
		args->var->y = 0;
		while (args->var->y < WIDTH)
		{
			algo_mandelbrot(args->mlx, args->var, args);
			args->var->y++;
		}
		args->var->x++;
	}
	mlx_put_image_to_window(args->mlx->mlx_p, args->mlx->win_p,
			args->mlx->img_p, 0, 0);
	mlx_string_put(args->mlx->mlx_p, args->mlx->win_p, 20, 20, 16777215,
			"ITERATION MAX : ");
	if (!(i = ft_itoa(args->it_max)))
		return (0);
	mlx_string_put(args->mlx->mlx_p, args->mlx->win_p, 180, 20, 16777215, i);
	return (1);
}