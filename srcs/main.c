/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 03:23:21 by wahasni           #+#    #+#             */
/*   Updated: 2019/05/05 06:10:27 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int      print_fract(t_args *args)
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
	if (args->fract == 6)
		if (!(print_disque_siegel(args)))
			return (0);
	if (args->fract == 7)
		if (!(print_dragon_douady(args)))
			return (0);
	return (1);
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
	else if (!ft_strcmp(str, "Dendrite"))
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
}

t_args	*ft_init(void)
{
	t_args	*args;

	if (!(args = malloc(sizeof(t_args))))
		return (0);
	if (!(args->mlx = malloc(sizeof(t_mlx))))
		return (0);
	if (!(args->var = malloc(sizeof(t_var))))
		return (0);
	args->mlx->mlx_p = mlx_init();
	args->mlx->win_p = mlx_new_window(args->mlx->mlx_p, WIDTH, WIDTH, "WaWwWeeee");
	args->mlx->img_p = mlx_new_image(args->mlx->mlx_p, WIDTH, WIDTH);
	args->mlx->tab = (unsigned int *)mlx_get_data_addr(args->mlx->img_p,
			&args->mlx->bpp, &args->mlx->sizeline, &args->mlx->endian);
	args->color = 1;
	return (args);
}

int      ft_check_usage(int ac, char **av)
{
    if (ac != 2)
    {
        ft_putendl("Ce n'est pas le bon nombre d'argument");
        return (0);
    }
	else if ((ft_strcmp(av[1], "Julia") && (ft_strcmp(av[1], "Mandelbrot")
			&& (ft_strcmp(av[1], "Burningship") && (ft_strcmp(av[1], "Basilique")
			&& (ft_strcmp(av[1], "Dendrite") && (ft_strcmp(av[1], "Disque_siegel")
			&& (ft_strcmp(av[1], "Dragon_douady")))))))))
    {
        ft_putendl("usage : ./fractol [fractal]");
        ft_putendl("fractals :");
        ft_putendl("--> Mandelbrot");
        ft_putendl("--> Julia");
		ft_putendl("--> Burningship");
		ft_putendl("--> Basilique");
		ft_putendl("--> Dendrite");
		ft_putendl("--> Disque_sieguel");
		ft_putendl("--> Dragon_douady");
        return (0);
    }
	return (1);
}

int             main(int ac, char **av)
{
    t_args  *args;

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