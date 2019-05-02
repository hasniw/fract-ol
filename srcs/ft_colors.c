/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 06:17:42 by wahasni           #+#    #+#             */
/*   Updated: 2019/05/02 06:45:26 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	color2(t_mlx *mlx, t_var *var, int i)
{
	if (i % 16 == 7)
		mlx->tab[var->y * WIDTH + var->x] = 776123;
	else if (i % 16 == 8)
		mlx->tab[var->y * WIDTH + var->x] = 838239;
	else if (i % 16 == 9)
		mlx->tab[var->y * WIDTH + var->x] = 8876320;
	else if (i % 16 == 10)
		mlx->tab[var->y * WIDTH + var->x] = 5401325;
	else if (i % 16 == 11)
		mlx->tab[var->y * WIDTH + var->x] = 16343279;
	else if (i % 16 == 12)
		mlx->tab[var->y * WIDTH + var->x] = 16520230;
	else if (i % 16 == 13)
		mlx->tab[var->y * WIDTH + var->x] = 13223112;
	else if (i % 16 == 14)
		mlx->tab[var->y * WIDTH + var->x] = 10923280;
	else if (i % 16 == 15)
		mlx->tab[var->y * WIDTH + var->x] = 6962301;
}

void	color(t_mlx *mlx, t_var *var, t_args *args, int i)
{
	if (i == args->it_max)
		mlx->tab[var->y * WIDTH + var->x] = 0;
	else if (i % 16 == 0)
		mlx->tab[var->y * WIDTH + var->x] = 433731;
	else if (i % 16 == 1)
		mlx->tab[var->y * WIDTH + var->x] = 162183;
	else if (i % 16 == 2)
		mlx->tab[var->y * WIDTH + var->x] = 5922137;
	else if (i % 16 == 3)
		mlx->tab[var->y * WIDTH + var->x] = 2213641;
	else if (i % 16 == 4)
		mlx->tab[var->y * WIDTH + var->x] = 1813222;
	else if (i % 16 == 5)
		mlx->tab[var->y * WIDTH + var->x] = 797284;
	else if (i % 16 == 6)
		mlx->tab[var->y * WIDTH + var->x] = 159233;
	else
		color2(mlx, var, i);
}

void	color_input(int key, t_args *args)
{
	if (key == NUMBER_1)
		args->color = 1;
	else
		args->color = 2;
	if (key == NUMBER_2)
		args->color_value = 100;
	if (key == NUMBER_3)
		args->color_value = 1800;
	if (key == NUMBER_4)
		args->color_value = 2400;
	if (key == NUMBER_5)
		args->color_value = 6000;
}