/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_action.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 06:23:15 by wahasni           #+#    #+#             */
/*   Updated: 2019/05/02 06:23:34 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	move(int key, t_args *args)
{
	if (key == KEY_LEFT)
		args->x1 += 30 / args->zoom;
	if (key == KEY_RIGHT)
		args->x1 -= 30 / args->zoom;
	if (key == KEY_DOWN)
		args->y1 -= 30 / args->zoom;
	if (key == KEY_UP)
		args->y1 += 30 / args->zoom;
}

void	zoom(int x, int y, t_args *args)
{
	args->x1 = (x / args->zoom + args->x1) - (x / (args->zoom * 1.3));
	args->y1 = (y / args->zoom + args->y1) - (y / (args->zoom * 1.3));
	args->zoom *= 1.3;
	args->it_max++;
}

void	dezoom(int x, int y, t_args *args)
{
	args->x1 = (x / args->zoom + args->x1) - (x / (args->zoom / 1.3));
	args->y1 = (y / args->zoom + args->y1) - (y / (args->zoom / 1.3));
	args->zoom /= 1.3;
	args->it_max--;
}