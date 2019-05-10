/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 03:23:21 by wahasni           #+#    #+#             */
/*   Updated: 2019/05/10 18:54:52 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			print_fract2(t_args *args)
{
	if (args->fract == 6)
		if (!(print_disque_siegel(args)))
			return (0);
	if (args->fract == 7)
		if (!(print_dragon_douady(args)))
			return (0);
	if (args->fract == 8)
		if (!(print_multibrot(args)))
			return (0);
	if (args->fract == 9)
		if (!(print_fatou_dust(args)))
			return (0);
	return (1);
}

int			print_fract(t_args *args)
{
	if (args->fract == 1)
		if (!(print_mandelbrot(args)))
			return (0);
	if (args->fract == 2)
		if (!(print_julia(args)))
			return (0);
	if (args->fract == 3)
		if (!(print_burningship(args)))
			return (0);
	if (args->fract == 4)
		if (!(print_basilique(args)))
			return (0);
	if (args->fract == 5)
		if (!(print_dendrite(args)))
			return (0);
	return (print_fract2(args));
}

void		init_fract2(char *str, t_args *args)
{
	if (!ft_strcmp(str, "Dendrite"))
	{
		init_dendrite(args);
		args->fract = 5;
	}
	else if (!ft_strcmp(str, "Disque_siegel"))
	{
		init_disque_siegel(args);
		args->fract = 6;
	}
	else if (!ft_strcmp(str, "Dragon_douady"))
	{
		init_dragon_douady(args);
		args->fract = 7;
	}
	else if (!ft_strcmp(str, "Multibrot"))
	{
		init_multibrot(args);
		args->fract = 8;
	}
	else
	{
		init_fatou_dust(args);
		args->fract = 9;
	}
}

void		init_fract(char *str, t_args *args)
{
	if (!ft_strcmp(str, "Mandelbrot"))
	{
		init_mandelbrot(args);
		args->fract = 1;
	}
	else if (!ft_strcmp(str, "Julia"))
	{
		init_julia(args);
		args->fract = 2;
	}
	else if (!ft_strcmp(str, "Burningship"))
	{
		init_burningship(args);
		args->fract = 3;
	}
	else if (!ft_strcmp(str, "Basilique"))
	{
		init_basilique(args);
		args->fract = 4;
	}
	else
		init_fract2(str, args);
}

int			main(int ac, char **av)
{
	t_args	*args;

	if (ft_check_usage(ac, av) != 1)
		return (0);
	if (!(args = ft_init()))
		return (0);
	init_fract(av[1], args);
	if (!(print_fract(args)))
		return (0);
	mlx_mouse_hook(args->mlx->win_p, mouse_hook, args);
	mlx_hook(args->mlx->win_p, 2, 0, key_hook, args);
	mlx_hook(args->mlx->win_p, 6, 1L << 6, julia_hook, args);
	mlx_loop(args->mlx->mlx_p);
	return (0);
}
