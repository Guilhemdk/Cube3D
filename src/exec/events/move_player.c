/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pitroin <pitroin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:54:50 by pitroin           #+#    #+#             */
/*   Updated: 2025/02/24 13:26:57 by pitroin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/Cube3D.h"

static void	rotate_player(t_data *data, int rotdir)
{
	double	rotspeed;

	rotspeed = MOUSE_SENSITIVITY * rotdir;
	data->player.angle += rotspeed;
	if (data->player.angle > 2 * PI)
		data->player.angle -= 2 * PI;
	if (data->player.angle < 0)
		data->player.angle += 2 * PI;
}

static void	move_player(t_data *data, double move_x, double move_y)
{
	int	map_y;
	int	map_x;
	int	new_x;
	int	new_y;

	new_x = roundf(data->player.posx + move_x);
	new_y = roundf(data->player.posy + move_y);
	map_x = (new_x / TILE_SIZE);
	map_y = (new_y / TILE_SIZE);
	if (data->m.map[map_y][map_x] != '1' && \
			(data->m.map[map_y][data->player.posx / TILE_SIZE] != '1' && \
			data->m.map[data->player.posy / TILE_SIZE][map_x] != '1'))
	{
		if (data->m.map[(new_y - 1)
				/ TILE_SIZE][(new_x - 1) / TILE_SIZE] == '1')
			return ;
		data->player.posx = new_x;
		data->player.posy = new_y;
	}
}

void	hook(t_data *data, double move_x, double move_y)
{
	if (data->player.rotation == 1)
		rotate_player(data, 1);
	else if (data->player.rotation == -1)
		rotate_player(data, -1);
	if (data->player.move_l_r == 1)
	{
		move_x = -sin(data->player.angle) * PLAYER_SPEED;
		move_y = cos(data->player.angle) * PLAYER_SPEED;
	}
	else if (data->player.move_l_r == -1)
	{
		move_x = sin(data->player.angle) * PLAYER_SPEED;
		move_y = -cos(data->player.angle) * PLAYER_SPEED;
	}
	if (data->player.move_u_d == 1)
	{
		move_x = cos(data->player.angle) * PLAYER_SPEED;
		move_y = sin(data->player.angle) * PLAYER_SPEED;
	}
	else if (data->player.move_u_d == -1)
	{
		move_x = -cos(data->player.angle) * PLAYER_SPEED;
		move_y = -sin(data->player.angle) * PLAYER_SPEED;
	}
	move_player(data, move_x, move_y);
}
