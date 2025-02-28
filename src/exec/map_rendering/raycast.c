/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:54:57 by pitroin           #+#    #+#             */
/*   Updated: 2025/02/28 13:47:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/Cube3D.h"

static float	get_next_h_wall(t_data *data, float angl)
{
	float	x_step;
	float	y_step;
	int		pixel;

	y_step = TILE_SIZE;
	x_step = TILE_SIZE / tan(angl);
	data->rc.h_hity = floor(data->player.posy / (float)TILE_SIZE) * TILE_SIZE;
	pixel = inter_check(angl, &data->rc.h_hity, &y_step, 1);
	data->rc.h_hitx = data->player.posx + (data->rc.h_hity - data->player.posy)
		/ tan(angl);
	if ((ray_orientation(angl, 'y') && x_step > 0)
		|| (!ray_orientation(angl, 'y') && x_step < 0))
		x_step *= -1;
	while (!wall_hit(data->rc.h_hitx, data->rc.h_hity - pixel, data))
	{
		data->rc.h_hitx += x_step;
		data->rc.h_hity += y_step;
	}
	return (sqrt(pow(data->rc.h_hitx - data->player.posx, 2)
			+ pow(data->rc.h_hity - data->player.posy, 2)));
}

static float	get_next_v_wall(t_data *data, float angl)
{
	float	x_step;
	float	y_step;
	int		pixel;

	x_step = TILE_SIZE;
	y_step = TILE_SIZE * tan(angl);
	data->rc.v_hitx = floor(data->player.posx / (float)TILE_SIZE) * TILE_SIZE;
	pixel = inter_check(angl, &data->rc.v_hitx, &x_step, 0);
	data->rc.v_hity = data->player.posy + (data->rc.v_hitx - data->player.posx)
		* tan(angl);
	if ((ray_orientation(angl, 'x') && y_step < 0)
		|| (!ray_orientation(angl, 'x') && y_step > 0))
		y_step *= -1;
	while (!wall_hit(data->rc.v_hitx - pixel, data->rc.v_hity, data))
	{
		data->rc.v_hitx += x_step;
		data->rc.v_hity += y_step;
	}
	return (sqrt(pow(data->rc.v_hitx - data->player.posx, 2)
			+ pow(data->rc.v_hity - data->player.posy, 2)));
}

void	init_ray(t_data *d)
{
	d->rc.ray = 0;
	d->rc.closest_h_wall = 0;
	d->rc.closest_v_wall = 0;
}

void	calc_rays(t_data *d)
{
	init_ray(d);
	d->rc.angle = d->player.angle - (d->player.fov / 2);
	while (d->rc.ray < SCREEN_WIDTH)
	{
		d->rc.wall_flag = 0;
		d->rc.closest_h_wall = get_next_h_wall(d, norm_angle(d->rc.angle));
		d->rc.closest_v_wall = get_next_v_wall(d, norm_angle(d->rc.angle));
		if (d->rc.closest_v_wall <= d->rc.closest_h_wall)
		{
			d->rc.distance = d->rc.closest_v_wall;
			d->rc.wall_hit_x = d->rc.v_hitx;
			d->rc.wall_hit_y = d->rc.v_hity;
		}
		else
		{
			d->rc.distance = d->rc.closest_h_wall;
			d->rc.wall_flag = 1;
			d->rc.wall_hit_x = d->rc.h_hitx;
			d->rc.wall_hit_y = d->rc.h_hity;
		}
		dda(d);
		d->rc.ray++;
		d->rc.angle += (d->player.fov / SCREEN_WIDTH);
	}
}
