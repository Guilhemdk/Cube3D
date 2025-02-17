/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DDA.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pitroin <pitroin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:54:55 by pitroin           #+#    #+#             */
/*   Updated: 2025/01/22 11:34:41 by pitroin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/Cube3D.h"

unsigned int	get_pixel_color(t_texture *texture, int x, int y)
{
	char	*pixel;

	if (x < 0 || x >= texture->width || y < 0 || y >= texture->height)
		return (0);
	pixel = texture->addr + (y * texture->line_length + x * (texture->bpp / 8));
	return (*(unsigned int *)pixel);
}

int	get_color(t_data *d, int wall_flag, int tex_x, int tex_y)
{
	d->rc.angle = norm_angle(d->rc.angle);
	if (wall_flag == 0)
	{
		if (d->rc.angle > PI / 2 && d->rc.angle < 3 * (PI / 2))
			return (get_pixel_color(&d->w.tex_we, tex_x, tex_y));
		else
			return (get_pixel_color(&d->w.tex_ea, tex_x, tex_y));
	}
	else
	{
		if (d->rc.angle > 0 && d->rc.angle < PI)
			return (get_pixel_color(&d->w.tex_so, tex_x, tex_y));
		else
			return (get_pixel_color(&d->w.tex_no, tex_x, tex_y));
	}
	return (0);
}

void	draw_wall(t_data *d, double wall_height, double top_pix, double bot_pix)
{
	int	tex_x;
	int	tex_y;

	if (d->rc.wall_flag == 0)
		d->rc.wall_hit = d->rc.wall_hit_y
			- floor(d->rc.wall_hit_y / TILE_SIZE) * TILE_SIZE;
	else
		d->rc.wall_hit = d->rc.wall_hit_x
			- floor(d->rc.wall_hit_x / TILE_SIZE) * TILE_SIZE;
	tex_x = (int)(d->rc.wall_hit * (d->w.tex_ea.width / TILE_SIZE));
	while (top_pix < bot_pix)
	{
		if (d->rc.wall_flag == 0)
			tex_y = (int)((top_pix - ((double)SCREEN_HEIGHT / 2 \
			- wall_height / 2)) / wall_height * d->w.tex_ea.height);
		else
			tex_y = (int)((top_pix - ((double)SCREEN_HEIGHT / 2 \
			- wall_height / 2)) / wall_height * d->w.tex_no.height);
		if (tex_y < 0)
			tex_y = 0;
		if (tex_y >= d->w.tex_no.height)
			tex_y = d->w.tex_no.height - 1;
		put_pixel(&d->w.img, d->rc.ray, top_pix++,
			get_color(d, d->rc.wall_flag, tex_x, tex_y));
	}
}

void	draw_floor_ceiling(t_data *d, int top_pix, int bot_pix)
{
	int	i;

	i = bot_pix;
	while (i < SCREEN_HEIGHT)
		put_pixel(&d->w.img, d->rc.ray, i++, d->m.hex_f);
	i = 0;
	while (i < top_pix)
		put_pixel(&d->w.img, d->rc.ray, i++, d->m.hex_c);
}

void	dda(t_data *d)
{
	double	wall_height;
	double	bot_pix;
	double	top_pix;

	d->rc.distance *= cos(norm_angle(d->rc.angle - d->player.angle));
	wall_height = (TILE_SIZE / d->rc.distance) * (((double)SCREEN_WIDTH / 2)
			/ tan(d->player.fov / 2));
	bot_pix = ((double)SCREEN_HEIGHT / 2) + (wall_height / 2);
	top_pix = ((double)SCREEN_HEIGHT / 2) - (wall_height / 2);
	if (bot_pix > SCREEN_HEIGHT)
		bot_pix = SCREEN_HEIGHT;
	if (top_pix < 0)
		top_pix = 0;
	draw_wall(d, wall_height, top_pix, bot_pix);
	draw_floor_ceiling(d, top_pix, bot_pix);
}
