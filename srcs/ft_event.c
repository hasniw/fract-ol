/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 17:20:11 by wahasni           #+#    #+#             */
/*   Updated: 2019/05/10 18:46:54 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	letter_hook2(int key, void *args)
{
	if (key == LETTER_T)
	{
		((t_args *)args)->fract = 5;
		init_dendrite((t_args *)args);
	}
	if (key == LETTER_Y)
	{
		((t_args *)args)->fract = 6;
		init_disque_siegel((t_args *)args);
	}
	if (key == LETTER_U)
	{
		((t_args *)args)->fract = 7;
		init_dragon_douady((t_args *)args);
	}
	if (key == LETTER_I)
	{
		((t_args *)args)->fract = 8;
		init_multibrot((t_args *)args);
	}
	if (key == LETTER_O)
	{
		((t_args *)args)->fract = 9;
		init_fatou_dust((t_args *)args);
	}
}

void	letter_hook(int key, void *args)
{
	if (key == LETTER_Q)
	{
		((t_args *)args)->fract = 1;
		init_mandelbrot((t_args *)args);
	}
	if (key == LETTER_W)
	{
		((t_args *)args)->fract = 2;
		init_julia((t_args *)args);
	}
	if (key == LETTER_E)
	{
		((t_args *)args)->fract = 3;
		init_burningship((t_args *)args);
	}
	if (key == LETTER_R)
	{
		((t_args *)args)->fract = 4;
		init_basilique((t_args *)args);
	}
	letter_hook2(key, args);
}

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
	if (key == SPACE)
	{
		if (((t_args *)args)->pause == 1)
			((t_args *)args)->pause = 0;
		else
			((t_args *)args)->pause = 1;
	}
	if ((key > 17 && key < 22) || (key == 23))
		color_input(key, ((t_args *)args));
	letter_hook(key, (t_args *)args);
	if (key == PLUS)
		((t_args *)args)->it_max += 20;
	if (key == MINUS)
		((t_args *)args)->it_max -= 20;
	print_fract(args);
	return (0);
}
