/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pitroin <pitroin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:52:03 by pitroin           #+#    #+#             */
/*   Updated: 2025/01/20 14:19:48 by pitroin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cube3D.h"

void	init_struct(t_map *map)
{
	map->file_SO = NULL;
	map->file_NO = NULL;
	map->file_WE = NULL;
	map->file_EA = NULL;
	map->color_c = NULL;
	map->color_f = NULL;
}

void	init_player(t_data *data)
{
	data->player.posX = (data->m.x_spawn * TILE_SIZE) + TILE_SIZE / 2;
	data->player.posY = (data->m.y_spawn * TILE_SIZE) + TILE_SIZE / 2;
	data->player.fov = (FOV * PI) / 180;
	if (data->m.dir_spawn == 'N')
		data->player.angle = 3 * PI / 2;
	else if (data->m.dir_spawn == 'E')
		data->player.angle = 0;
	else if (data->m.dir_spawn == 'S')
		data->player.angle = PI / 2;
	else
		data->player.angle = PI;
	data->rc.h_hitX = 0.0f;
	data->rc.h_hitY = 0.0f;
	data->rc.v_hitX = 0.0f;
	data->rc.v_hitY = 0.0f;
	data->rc.wall_hit_x = 0.0;
	data->rc.wall_hit_y = 0.0;
	data->rc.wall_hit = 0.0;
	data->rc.wall_flag =  0;
}

int game_loop(t_data *d)
{
    hook(d, 0, 0);
    calc_rays(d);
    image_to_window(&d->w);
    return (0);
}

void	affiche_info(t_data *d)
{
	printf("tex s:%s\n", d->m.file_SO);
	printf("tex n:%s\n", d->m.file_NO);
	printf("tex e:%s\n", d->m.file_EA);
	printf("tex w:%s\n", d->m.file_WE);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		return (printf("ERROR\n"));
	init_struct(&data.m);
	if (init_map(&data.m, av[1]) > 0)
		return(free_map(&data.m), 1);
	else
		printf("\nGG !\n");
	data.m.map = ft_split(data.m.file_map, '\n');
	if (!data.m.map)
		error(&data, "Error creating map\n");
	init_player(&data);
	if (init_window(&data))
		return (1);
    mlx_loop_hook(data.w.mlx, &game_loop, &data);
    mlx_hook(data.w.win, 2, 1L << 0, generate_event, &data);
    mlx_hook(data.w.win, 3, 1L << 1, release_key, &data);
    mlx_loop(data.w.mlx);
	free_map(&data.m);
	return (0);
}
