/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 17:20:11 by wahasni           #+#    #+#             */
/*   Updated: 2019/05/01 05:52:27 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


int     deal_mouse(int mouse, int x, int y, t_args *args)
{
    void    *img;
//    char    *data;
//    int     bpp;
//    int     sizeline;
//    int     endian;
//    int     pixel_nbr;
//    pixel_nbr = 0;
    if (mouse == 1)
    {
        //if (!(img = mlx_new_image(args->mlx_ptr, 10, 10)))
        //        printf("new image failled !\n");
        //data = mlx_get_data_addr(img, &bpp, &sizeline, &endian);
        img = mlx_new_image(args->mlx_ptr, 10, 10);
        //data = mlx_get_data_addr(img, &bpp, &sizeline, &endian);
        //printf("%d, %d, %d\n", bpp, sizeline, endian);
        //while (pixel_nbr < 190000)
        //{
        //    data[pixel_nbr] = 100;
        //    pixel_nbr++;
        //}
        mlx_put_image_to_window(args->mlx_ptr, args->win_ptr, img, x, y);
        //mlx_put_image_to_window(args->mlx_ptr, args->win_ptr, img, x, y);
    }
    else if (mouse == 2)
        mlx_string_put (args->mlx_ptr, args->win_ptr, x, y, 0xffffff, "Click gauche" );
    else if (mouse == 4)
        mlx_string_put (args->mlx_ptr, args->win_ptr, x, y, 0xffffff, "ZOOM" );
    else if (mouse == 5)
        mlx_string_put (args->mlx_ptr, args->win_ptr, x, y, 0xffffff, "DEZOOM" );
    // else if (mouse == 3)
    //     map_color(args->mlx_ptr, args->win_ptr, 255);
    return (0);
}

int     deal_key(int key, t_args *args)
{
    static int  i = 1;

    if (key == 53)
    {
        mlx_destroy_window(args->mlx_ptr, args->win_ptr);
        free(args);
        args = NULL;
        exit(0);
    }
    else if (key == 51)
    {
        mlx_clear_window(args->mlx_ptr, args->win_ptr);
        i = 1;
    }
    else if (key == 0)
        mlx_string_put (args->mlx_ptr, args->win_ptr, (i = i + 10), 1, 0xffffff, "a" );
    else if (key == 11)
        mlx_string_put (args->mlx_ptr, args->win_ptr, (i = i + 10), 1, 0xffffff, "b" );
    else if (key == 8)
        mlx_string_put (args->mlx_ptr, args->win_ptr, (i = i + 10), 1, 0xffffff, "c" );
    else if (key == 2)
        mlx_string_put (args->mlx_ptr, args->win_ptr, (i = i + 10), 1, 0xffffff, "d" );
    else if (key == 14)
        mlx_string_put (args->mlx_ptr, args->win_ptr, (i = i + 10), 1, 0xffffff, "e" );
    else if (key == 3)
        mlx_string_put (args->mlx_ptr, args->win_ptr, (i = i + 10), 1, 0xffffff, "f" );
    else if (key == 5)
        mlx_string_put (args->mlx_ptr, args->win_ptr, (i = i + 10), 1, 0xffffff, "g" );
    else if (key == 4)
        mlx_string_put (args->mlx_ptr, args->win_ptr, (i = i + 10), 1, 0xffffff, "h" );
    else if (key == 34)
        mlx_string_put (args->mlx_ptr, args->win_ptr, (i = i + 10), 1, 0xffffff, "i" );
    else if (key == 38)
        mlx_string_put (args->mlx_ptr, args->win_ptr, (i = i + 10), 1, 0xffffff, "j" );
    else if (key == 40)
        mlx_string_put (args->mlx_ptr, args->win_ptr, (i = i + 10), 1, 0xffffff, "k" );
    else if (key == 37)
        mlx_string_put (args->mlx_ptr, args->win_ptr, (i = i + 10), 1, 0xffffff, "l" );
    else if (key == 46)
        mlx_string_put (args->mlx_ptr, args->win_ptr, (i = i + 10), 1, 0xffffff, "m" );
    else if (key == 45)
        mlx_string_put (args->mlx_ptr, args->win_ptr, (i = i + 10), 1, 0xffffff, "n" );
    else if (key == 31)
        mlx_string_put (args->mlx_ptr, args->win_ptr, (i = i + 10), 1, 0xffffff, "o" );
    else if (key == 35)
        mlx_string_put (args->mlx_ptr, args->win_ptr, (i = i + 10), 1, 0xffffff, "p" );
    else if (key == 12)
        mlx_string_put (args->mlx_ptr, args->win_ptr, (i = i + 10), 1, 0xffffff, "q" );
    else if (key == 15)
        mlx_string_put (args->mlx_ptr, args->win_ptr, (i = i + 10), 1, 0xffffff, "r" );
    else if (key == 1)
        mlx_string_put (args->mlx_ptr, args->win_ptr, (i = i + 10), 1, 0xffffff, "s" );
    else if (key == 17)
        mlx_string_put (args->mlx_ptr, args->win_ptr, (i = i + 10), 1, 0xffffff, "t" );
    else if (key == 32)
        mlx_string_put (args->mlx_ptr, args->win_ptr, (i = i + 10), 1, 0xffffff, "u" );
    else if (key == 9)
        mlx_string_put (args->mlx_ptr, args->win_ptr, (i = i + 10), 1, 0xffffff, "v" );
    else if (key == 13)
        mlx_string_put (args->mlx_ptr, args->win_ptr, (i = i + 10), 1, 0xffffff, "w" );
    else if (key == 7)
        mlx_string_put (args->mlx_ptr, args->win_ptr, (i = i + 10), 1, 0xffffff, "x" );
    else if (key == 16)
        mlx_string_put (args->mlx_ptr, args->win_ptr, (i = i + 10), 1, 0xffffff, "y" );
    else if (key == 6)
        mlx_string_put (args->mlx_ptr, args->win_ptr, (i = i + 10), 1, 0xffffff, "z" );
    else if (key == 49)
        mlx_string_put (args->mlx_ptr, args->win_ptr, (i = i + 10), 1, 0xffffff, " " );
    else if (key == 18)
        mlx_string_put (args->mlx_ptr, args->win_ptr, (i = i + 10), 1, 0xffffff, "!" );
    return (0);
}