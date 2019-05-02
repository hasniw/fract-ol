/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 17:20:11 by wahasni           #+#    #+#             */
/*   Updated: 2019/05/02 06:39:20 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mouse_hook(int key, int x, int y, void *args)
{
	if (key == 4)
		zoom(x, y, ((t_args *)args));
	if (key == 5)
		dezoom(x, y, ((t_args *)args));
	print_fract(args);
	return (0);
}

void	destroy_window(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx_p, mlx->win_p);
	free(mlx->tab);
	exit(0);
}

int		key_hook(int key, void *args)
{
	if (key == KEY_ESCAPE)
		destroy_window(((t_args *)args)->mlx);
	if (key > 122 && key < 127)
		move(key, ((t_args *)args));
	// if (key == 69)
	// 	((t_args *)args)->it_max += 10;
	// if (key == 78)
	// 	((t_args *)args)->it_max -= 10;
	// if (key == 30)
	// 	((t_args *)args)->it_max += 1000;
	// if (key == 33)
	// 	if (((t_args *)args)->it_max - 500 > 0)
	// 		((t_args *)args)->it_max -= 500;
	// if (key == 35)
	// 	if (((t_args *)args)->pause == 1)
	// 		((t_args *)args)->pause = 0;
	// 	else
	// 		((t_args *)args)->pause = 1;
	if ((key > 17 && key < 22) || (key == 23))
		color_input(key, ((t_args *)args));
	print_fract(args);
	return (0);
}