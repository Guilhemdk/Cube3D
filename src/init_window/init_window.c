/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pitroin <pitroin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 13:11:56 by pitroin           #+#    #+#             */
/*   Updated: 2024/11/25 13:38:17 by pitroin          ###   ########.fr       */
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

int	escape_event(t_win *w)
{
	mlx_clear_window(w->mlx, w->win);
	mlx_destroy_window(w->mlx, w->win);
	free(w->mlx);
	exit(EXIT_SUCCESS);
	return (1);
}

int	key_event(int keycode, t_data *d)
{
	if (keycode == 53)
		escape_event(&d->w);
	return (1);
}

int	luncher(t_data * d)
{
	init_texture(d);
	// d->w.img.image = mlx_new_image(d->w.mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	// d->w.img.addr = (int *)mlx_get_data_addr(d->w.img.wallN, &d->w.img.pixel_bits,
	// 	&d->w.img.line_bytes, &d->w.img.endian);
	mlx_put_image_to_window(d->w.mlx, d->w.win, d->w.img.wallN, 0, 0);
	mlx_put_image_to_window(d->w.mlx, d->w.win, d->w.img.wallE, 0, 100);
	mlx_put_image_to_window(d->w.mlx, d->w.win, d->w.img.wallS, 0, 200);
	mlx_put_image_to_window(d->w.mlx, d->w.win, d->w.img.wallW, 0, 300);
	return (0);
}

int	init_window(t_data *d)
{
	d->w.mlx = mlx_init();
	d->w.win = mlx_new_window(d->w.mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "CUB3D");
	luncher(d);
	mlx_key_hook(d->w.win, &key_event, &d->w);
	mlx_hook(d->w.win, 17, 0, &escape_event, &d->w);
	mlx_loop(d->w.mlx);
	return (0);
}
