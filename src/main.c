/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:52:03 by pitroin           #+#    #+#             */
/*   Updated: 2025/02/28 20:14:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cube3D.h"

void	init_struct(t_map *map)
{
	map->file_so = NULL;
	map->file_no = NULL;
	map->file_we = NULL;
	map->file_ea = NULL;
	map->file_map = NULL;
	map->file = NULL;
	map->color_c = NULL;
	map->color_f = NULL;
	map->map = NULL;
	map->flag_hex = 0;
}

void	init_player(t_data *data)
{
	data->player.posx = (data->m.x_spawn * TILE_SIZE) + TILE_SIZE / 2;
	data->player.posy = (data->m.y_spawn * TILE_SIZE) + TILE_SIZE / 2;
	data->player.fov = (FOV * PI) / 180;
	if (data->m.dir_spawn == 'N')
		data->player.angle = 3 * PI / 2;
	else if (data->m.dir_spawn == 'E')
		data->player.angle = 0;
	else if (data->m.dir_spawn == 'S')
		data->player.angle = PI / 2;
	else
		data->player.angle = PI;
	data->rc.h_hitx = 0.0f;
	data->rc.h_hity = 0.0f;
	data->rc.v_hitx = 0.0f;
	data->rc.v_hity = 0.0f;
	data->rc.wall_hit_x = 0.0;
	data->rc.wall_hit_y = 0.0;
	data->rc.wall_hit = 0.0;
	data->rc.wall_flag = 0.0;
	data->player.rotation = 0.0;
	data->player.move_l_r = 0;
	data->player.move_u_d = 0;
}

int	game_loop(t_data *d)
{
	hook(d, 0.0, 0.0);
	calc_rays(d);
	image_to_window(&d->w);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		return (printf("Error: wrong arguments\n"));
	init_struct(&data.m);
	if (init_map(&data.m, av[1]) > 0)
		return (free_map(&data.m), 1);
	data.m.map = ft_split(data.m.file_map, '\n');
	if (!data.m.map)
		error(&data, "Error creating map\n");
	init_player(&data);
	if (init_window(&data))
		return (free_map(&data.m), 1);
	mlx_loop_hook(data.w.mlx, &game_loop, &data);
	mlx_hook(data.w.win, 2, 1L << 0, generate_event, &data);
	mlx_hook(data.w.win, 3, 1L << 1, release_key, &data);
	mlx_hook(data.w.win, 17, 0, escape_event, &data);
	mlx_loop(data.w.mlx);
	return (0);
}
