/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pitroin <pitroin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 17:04:43 by pitroin           #+#    #+#             */
/*   Updated: 2025/01/20 17:05:43 by pitroin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/Cube3D.h"

float	norm_angle(float angle)
{
	if (angle < 0)
		angle += (2 * PI);
	else if (angle > (2 * PI))
		angle -= 2 * PI;
	return (angle);
}

int	inter_check(float angle, float *inter, float *step, int is_horizon)
{
	if (is_horizon)
	{
		if (angle > 0 && angle < PI)
		{
			*inter += TILE_SIZE;
			return (-1);
		}
		*step *= -1;
	}
	else
	{
		if (!(angle > PI / 2 && angle < 3 * PI / 2))
		{
			*inter += TILE_SIZE;
			return (-1);
		}
		*step *= -1;
	}
	return (1);
}

int	ray_orientation(float angle, char c)
{
	if (c == 'x')
	{
		if (angle > 0 && angle < PI)
			return (1);
	}
	else if (c == 'y')
		if (angle > (PI / 2) && angle < (3 * PI) / 2)
			return (1);
	return (0);
}

int	wall_hit(float x, float y, t_data *data)
{
	int	map_x;
	int	map_y;

	if (x < 0 || y < 0)
		return (1);
	map_x = floor(x / TILE_SIZE);
	map_y = floor(y / TILE_SIZE);
	if (map_y >= data->m.height || map_x >= data->m.width)
		return (1);
	if (data->m.map[map_y] && map_x <= (int)ft_strlen(data->m.map[map_y]))
		if (data->m.map[map_y][map_x] == '1')
			return (1);
	return (0);
}
