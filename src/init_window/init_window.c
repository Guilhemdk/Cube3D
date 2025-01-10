/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 13:11:56 by pitroin           #+#    #+#             */
/*   Updated: 2024/12/22 16:45:03 by gmiorcec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Cube3D.h"

void	put_pixel(t_image *img, int x, int y, int color)
{
	char	*pixel;

	if (x >= 0 && x < SCREEN_WIDTH && y >= 0 && y < SCREEN_HEIGHT)
	{
		pixel = img->buffer + (y * img->line_bytes + x * (img->pixel_bits / 8));
		*(int *)pixel = color;
	}
}

// int	key_event(int keycode, t_data *d)
// {
// 	mlx_destroy_image(d->w.mlx, d->w.img.image);
// 	ft_putnbr_fd(keycode, 1);
// 	if (keycode == ESC_KEY)
// 		escape_event(&d->w);
// 	/* // else */
// 	/* // 		more_key(keycode, d); */
// 	/* d->w.img.image = mlx_new_image(d->w.mlx, */
// 	/* 				SCREEN_WIDTH, SCREEN_HEIGHT); */
// 	/* d->w.img.buffer = mlx_get_data_addr(d->w.img.image, */
// 	/* 				&d->w.img.pixel_bits, &d->w.img.line_bytes, */
// 	/* 				&d->w.img.endian); */
// 	/* calc_rays(d); */
// 	/* mlx_put_image_to_window(d->w.mlx, d->w.win, */
// 	/* 		d->w.img.image, 0, 0); */
// 	return (1);
// }
//
// static void wrap_mouse_pos(t_data *data, int x, int y)
// {
// 	if (x > SCREEN_WIDTH - DIST_MOUSE_WRAP)
// 	{
// 		x = DIST_MOUSE_WRAP;
// 		mlx_mouse_move(data->w.mlx, data->w.win, x, y);
// 	}
// 	if (x < DIST_MOUSE_WRAP)
// 	{
// 		x = SCREEN_WIDTH - DIST_MOUSE_WRAP;
// 		mlx_mouse_move(data->w.mlx, data->w.win, x, y);
// 	}
// }

void image_to_window(t_win *win)
{
    if (win->img.image)
    {
        mlx_put_image_to_window(win->mlx, win->win, win->img.image, 0, 0);
        mlx_destroy_image(win->mlx, win->img.image);
    }
    win->img.image = mlx_new_image(win->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
    if (!win->img.image)
	win->img.buffer = mlx_get_data_addr(win->img.image, \
            &win->img.pixel_bits, &win->img.line_bytes, &win->img.endian);
}

void	init_window(t_win *win)
{
	win->mlx = mlx_init();
	win->win = mlx_new_window(win->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "CUB3D");
	win->img.image = mlx_new_image(win->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	win->img.buffer = mlx_get_data_addr(win->img.image, \
			    &win->img.pixel_bits, &win->img.line_bytes, &win->img.endian);
    if (!win->img.image || !win->img.buffer)
        exit(EXIT_FAILURE);
}
