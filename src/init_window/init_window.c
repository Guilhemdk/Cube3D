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

#include "../../include/cub3d.h"

void	put_pixel(t_image *img, int x, int y, int color)
{
	char	*pixel;

	if (x >= 0 && x < WINDOW_WIDTH && y >= 0 && y < WINDOW_HEIGHT)
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


int	init_window(t_data *d)
{
	d->w.mlx = mlx_init();
	d->w.win = mlx_new_window(d->w.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "CUB3D");
	mlx_key_hook(d->w.win, &key_event, &d->w);
	mlx_hook(d->w.win, 17, 0, &escape_event, &d->w);
	mlx_loop(d->w.mlx);
	return (0);
}
