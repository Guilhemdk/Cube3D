/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pitroin <pitroin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 13:11:56 by pitroin           #+#    #+#             */
/*   Updated: 2025/02/10 17:23:20 by pitroin          ###   ########.fr       */
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

void	image_to_window(t_win *win)
{
	if (win->img.image)
	{
		mlx_put_image_to_window(win->mlx, win->win, win->img.image, 0, 0);
		mlx_destroy_image(win->mlx, win->img.image);
	}
	win->img.image = mlx_new_image(win->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!win->img.image)
	{
		win->img.buffer = mlx_get_data_addr(win->img.image, \
			&win->img.pixel_bits, &win->img.line_bytes, &win->img.endian);
	}
}

void	init_text(t_win *w)
{
	w->tex_ea.img = NULL;
	w->tex_we.img = NULL;
	w->tex_ea.img = NULL;
	w->tex_ea.img = NULL;
}

int	init_window(t_data *d)
{
	d->w.mlx = mlx_init();
	d->w.win = mlx_new_window(d->w.mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "CUB3D");
	if (load_textures(d, d->w.mlx) > 0)
	{
		printf("Error: textures not valid !\n");
		mlx_destroy_window(d->w.mlx, d->w.win);
		return (free(d->w.mlx), 1);
	}
	d->w.img.image = mlx_new_image(d->w.mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	d->w.img.buffer = mlx_get_data_addr(d->w.img.image, \
			&d->w.img.pixel_bits, &d->w.img.line_bytes, &d->w.img.endian);
	if (!d->w.img.image || !d->w.img.buffer)
		return (1);
	return (0);
}
