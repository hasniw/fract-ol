/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_action.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 06:23:15 by wahasni           #+#    #+#             */
/*   Updated: 2019/05/10 01:21:21 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		move(int key, t_args *args)
{
	if (key == KEY_LEFT)
		args->x1 += 25 / args->zoom;
	if (key == KEY_RIGHT)
		args->x1 -= 25 / args->zoom;
	if (key == KEY_DOWN)
		args->y1 -= 25 / args->zoom;
	if (key == KEY_UP)
		args->y1 += 25 / args->zoom;
}

void		zoom(int x, int y, t_args *args)
{
	args->x1 = (x / args->zoom + args->x1) - (x / (args->zoom * 1.3));
	args->y1 = (y / args->zoom + args->y1) - (y / (args->zoom * 1.3));
	args->zoom *= 1.3;
	args->it_max++;
}

void		dezoom(int x, int y, t_args *args)
{
	args->x1 = (x / args->zoom + args->x1) - (x / (args->zoom / 1.3));
	args->y1 = (y / args->zoom + args->y1) - (y / (args->zoom / 1.3));
	args->zoom /= 1.3;
	args->it_max--;
}

t_args		*ft_init(void)
{
	t_args	*args;

	if (!(args = ft_memalloc(sizeof(t_args))))
		return (0);
	if (!(args->mlx = ft_memalloc(sizeof(t_mlx))))
		return (0);
	if (!(args->var = ft_memalloc(sizeof(t_var))))
		return (0);
	args->mlx->mlx_p = mlx_init();
	args->mlx->win_p = mlx_new_window(args->mlx->mlx_p, WIDTH, WIDTH, "Frac");
	args->mlx->img_p = mlx_new_image(args->mlx->mlx_p, WIDTH, WIDTH);
	args->mlx->tab = (unsigned int *)mlx_get_data_addr(args->mlx->img_p,
			&args->mlx->bpp, &args->mlx->sizeline, &args->mlx->endian);
	args->color = 1;
	return (args);
}

int			ft_check_usage(int ac, char **av)
{
	if (ac != 2)
	{
		ft_putendl("Il n'y a pas le bon nombre d'argument");
		return (0);
	}
	else if ((ft_strcmp(av[1], "Julia") && (ft_strcmp(av[1], "Mandelbrot")
	&& (ft_strcmp(av[1], "Burningship") && (ft_strcmp(av[1], "Basilique")
	&& (ft_strcmp(av[1], "Dendrite") && (ft_strcmp(av[1], "Disque_siegel")
	&& (ft_strcmp(av[1], "Dragon_douady")
	&& (ft_strcmp(av[1], "Multibrot") && (ft_strcmp(av[1], "Fatou")))))))))))
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
		ft_putendl("--> Multibrot");
		ft_putendl("--> Fatou");
		return (0);
	}
	return (1);
}
