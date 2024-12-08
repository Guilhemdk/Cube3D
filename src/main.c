/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pitroin <pitroin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:52:03 by pitroin           #+#    #+#             */
/*   Updated: 2024/12/06 15:27:13 by gmiorcec         ###   ########.fr       */
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
	data->player.posX = data->m.x_spawn * TILE_SIZE + TILE_SIZE / 2;
	data->player.posY = data->m.y_spawn * TILE_SIZE + TILE_SIZE / 2;
	data->player.fov = (FOV * PI) / 180;
	if (data->m.dir_spawn == 'N')
		data->player.angle = 3 * PI / 2;
	else if (data->m.dir_spawn == 'E')
		data->player.angle = 0;
	else if (data->m.dir_spawn == 'S')
		data->player.angle = PI / 2;
	else
		data->player.angle = PI;


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
	init_window(&data);
	exec_game(&data);
	// exit propre
	free_map(&data.m);
	return (0);
}
