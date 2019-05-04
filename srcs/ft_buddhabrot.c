/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buddhabrot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 02:10:49 by wahasni           #+#    #+#             */
/*   Updated: 2019/05/04 02:22:25 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		init_buddhabrot(t_args *args)
{
    args->x1 = -2;
	args->y1 = -1.5;
	args->zoom = 300;
	args->it_max = 50;
}

void	algo_buddhabrot(t_mlx *mlx, t_var *var, t_args *args)
{
    int i;

    var->c_r = var->x / args->zoom + args->x1;
	var->c_i = var->y / args->zoom + args->y1;
	var->z_r = 0;
	var->z_i = 0;
	i = 0;
}

int			print_buddhabrot(t_args *args)
{
	int i;

    var->c_r = var->x / args->zoom + args->x1;
	var->c_i = var->y / args->zoom + args->y1;
	var->z_r = 0;
	var->z_i = 0;
	i = 0;
}