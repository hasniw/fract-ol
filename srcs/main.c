/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 03:23:21 by wahasni           #+#    #+#             */
/*   Updated: 2019/05/02 06:02:29 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int      print_fract(t_args *args)
{
	if (args->fract == 1)
    {
        printf("q\n");
		if (!(print_mandelbrot(args)))
		{
            printf("j\n");
            return (0);
        }
    }
	// if (args->fract == 2)
	// 	if (!(print_julia(args)))
	// 		return (0);
	return (1);
}

static int		key_hook(int key, void *args)
{
	if (key == KEY_ESCAPE)
		destroy_window(((t_args *)args)->mlx);
	if (key > 122 && key < 127)
		move(key, ((t_args *)args));
	// if (key == 69)
	// {
	// 	printf("69\n");
	// 	((t_args *)args)->it_max += 10;
	// }
	// if (key == 78)
	// {
	// 	((t_args *)args)->it_max -= 10;
	// 	printf("78\n");
	// }
	// if (key == 30)
	// {
	// 	((t_args *)args)->it_max += 1000;
	// 	printf("30\n");
	// }
	// if (key == 33)
	// {
	// 	printf("33\n");
	// 	if (((t_args *)args)->it_max - 500 > 0)
	// 		((t_args *)args)->it_max -= 500;
	// }
	// if (key == 35)
	// {
	// 	if (((t_args *)args)->pause == 1)
	// 		((t_args *)args)->pause = 0;
	// 	else
	// 		((t_args *)args)->pause = 1;
	// }
	if ((key > 17 && key < 22) || (key == 23))
		color_input(key, ((t_args *)args));
	print_fract(args);
	return (0);
}

static void		init_fract(char *str, t_args *args)
{
	if (!ft_strcmp(str, "Mandelbrot"))
	{
		init_mandelbrot(args);
		args->fract = 1;
	}
    // printf("lalala\n");
	// else if (!ft_strcmp(str, "Julia"))
	// {
	// 	init_julia(args);
	// 	args->fract = 2;
	// }
}

static t_args	*ft_init(void)
{
	t_args	*args;

	if (!(args = malloc(sizeof(t_args))))
		return (0);
    // printf("yes\n");
	if (!(args->mlx = malloc(sizeof(t_mlx))))
		return (0);
    // printf("no\n");
	if (!(args->var = malloc(sizeof(t_var))))
		return (0);
	args->mlx->mlx_p = mlx_init();
    // printf("olo\n");
	args->mlx->win_p = mlx_new_window(args->mlx->mlx_p, WIDTH, WIDTH, "WaWwWeeee");
	args->mlx->img_p = mlx_new_image(args->mlx->mlx_p, WIDTH, WIDTH);
    // printf("test\n");
	args->mlx->tab = (unsigned int *)mlx_get_data_addr(args->mlx->img_p,
			&args->mlx->bpp, &args->mlx->sizeline, &args->mlx->endian);
    // printf("aie\n");
	args->color = 1;
    // printf("test\n");
	return (args);
}

static int      ft_check_usage(int ac, char **av)
{
    if (ac != 2)
    {
        ft_putendl("Ce n'est pas le bon nombre d'argument");
        return (0);
    }
	else if ((ft_strcmp(av[1], "Julia") && (ft_strcmp(av[1], "Mandelbrot"))))
    {
        ft_putendl("usage : ./fractol [fractal]");
        ft_putendl("fractals :");
        ft_putendl("--> Mandelbrot");
        ft_putendl("--> Julia");
        return (0);
    }
	return (1);
}

int             main(int ac, char **av)
{
    t_args  *args;
    // t_image *image;

    if (ft_check_usage(ac, av) != 1)
        return (0);
    if (!(args = ft_init()))
        return (0);
    // printf("1\n");
    init_fract(av[1], args);
    // printf("2\n");
    if (!(print_fract(args)))
        return (0);
    ft_putendl("<-------->");
    // int i = 0;
    // while (i < 100000000)
    // {
    //         print_mandelbrot(&args);
    //         i++;
    // }
    // mlx_mouse_hook(args->win_ptr, deal_mouse, args);
    printf("yoyoyo\n");
	mlx_mouse_hook(args->mlx->win_p, mouse_hook, args);
	mlx_hook(args->mlx->win_p, 2, 0, key_hook, args);
	mlx_loop(args->mlx->mlx_p);
    return (0);
}