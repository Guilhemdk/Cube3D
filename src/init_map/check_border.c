/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_border.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 10:15:48 by pitroin           #+#    #+#             */
/*   Updated: 2025/02/28 20:16:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Cube3D.h"

int	is_spawn(char *str, int i)
{
	if (str[i] == 'S' || str[i] == 'N' || str[i] == 'E'
		|| str[i] == 'W')
		return (0);
	if (str[i] == ' ' || str[i] == '\n')
		return (2);
	if (str[i] == 'F' || str[i] == 'C')
		return (3);
	return (1);
}

int	flood_fill(t_map *map, int x, int y)
{
	if (map->file_map[x + y * map->width] != '1'
		&& map->file_map[x + y * map->width] != '0'
		&& map->file_map[x + y * map->width] != 'O'
		&& map->file_map[x + y * map->width] != map->dir_spawn)
		return (1);
	if (map->file_map[x + y * map->width] == '1'
		|| map->file_map[x + y * map->width] == 'O')
		return (0);
	if (map->file_map[x + y * map->width] == '0')
		map->file_map[x + y * map->width] = 'O';
	return (flood_fill(map, x + 1, y) + flood_fill(map, x - 1, y)
		+ flood_fill(map, x, y + 1) + flood_fill(map, x, y - 1));
}

int	locate_spawn(t_map *map)
{
	int	i;

	i = 0;
	map->y_spawn = 0;
	map->x_spawn = 0;
	while (map->file_map[i] != '\0')
	{
		if (is_spawn(map->file_map, i) == 0)
			return (0);
		if (map->file_map[i] == '\n')
		{
			map->y_spawn++;
			map->x_spawn = -1;
		}
		map->x_spawn++;
		i++;
	}
	return (1);
}

int	check_border(t_map *map)
{
	int			check;

	if (locate_spawn(map) == 1)
		return (printf("Spawn not in map\n"));
	check = 0;
	if (map->file_map[map->x_spawn + 1 + map->y_spawn * map->width] == '0')
		check = flood_fill(map, map->x_spawn + 1, map->y_spawn);
	else if (map->file_map[map->x_spawn - 1 + map->y_spawn * map->width] == '0')
		check = flood_fill(map, map->x_spawn + 1, map->y_spawn);
	else if (map->file_map[map->x_spawn
			+ (map->y_spawn + 1) * map->width] == '0')
		check = flood_fill(map, map->x_spawn, map->y_spawn + 1);
	else if (map->file_map[map->x_spawn
			+ (map->y_spawn - 1) * map->width] == '0')
		check = flood_fill(map, map->x_spawn, map->y_spawn - 1);
	else if (map->file_map[map->x_spawn + 1 + map->y_spawn * map->width] != '1'
		|| map->file_map[map->x_spawn - 1 + map->y_spawn * map->width] != '1'
		|| map->file_map[map->x_spawn + (map->y_spawn + 1) * map->width] != '1'
		|| map->file_map[map->x_spawn + (map->y_spawn - 1) * map->width] != '1')
		return (printf("Error: Spawn not in map\n"));
	if (check > 0)
		return (printf("Error: map not closed\n"));
	return (0);
}
