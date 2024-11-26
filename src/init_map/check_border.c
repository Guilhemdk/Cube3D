/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_border.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pitroin <pitroin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 10:15:48 by pitroin           #+#    #+#             */
/*   Updated: 2024/11/22 12:03:06 by pitroin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"


int	check_next_line(t_map *map, t_border *bord)
{
	int	j;
	int	i;

	j = map->i;
	if (bord->space == 0)
		return (0);
	while (map->file[j] != '\n')
		j++;
	j += bord->size -1;
	i = -1;
	while (++i <= bord->space + 1)
	{
		if (map->file[j] != '1' && i > 0 && i < bord->space + 1)
		{
			map->i = j;
			return (not_wall(map, bord, 0));
		}
		else if (map->file[j] != '1')
			return (printf("Error: Border not closed\n"));
		j++;
	}
	return (0);
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

void	init_border(t_border *bord)
{
	bord->height = 0;
	bord->width = 0;
	bord->size = 1;
	bord->space = 0;
	bord->spawn = 0;
}

void	locate_spawn(t_map *map)
{
	int	i;

	i = 0;
	map->y_spawn = 0;
	map->x_spawn = 0;
	while (map->file_map[i] != '\0')
	{
		if (is_spawn(map->file_map, i) == 0)
			return ;
		if (map->file_map[i] == '\n')
		{
			map->y_spawn++;
			map->x_spawn = -1;
		}
		map->x_spawn++;
		i++;
	}
}

int	check_border(t_map *map)
{
	t_border	bord;
	int			check;

	init_border(&bord);
	locate_spawn(map);
	check = 0;
	printf("map->x_spawn = %d et map->y_spawn %d\n", map->x_spawn, map->y_spawn);
	if (map->file_map[map->x_spawn + 1 + map->y_spawn * map->width] == '0')
		check = flood_fill(map, map->x_spawn + 1, map->y_spawn);
	else if (map->file_map[map->x_spawn - 1 + map->y_spawn * map->width] == '0')
		check = flood_fill(map, map->x_spawn + 1, map->y_spawn);
	else if (map->file_map[map->x_spawn + (map->y_spawn + 1) * map->width] == '0')
		check = flood_fill(map, map->x_spawn, map->y_spawn + 1);
	else if (map->file_map[map->x_spawn + (map->y_spawn - 1) * map->width] == '0')
		check = flood_fill(map, map->x_spawn, map->y_spawn - 1);
	if (check > 0)
		return (printf("Error: Border not closed\n"));
	return (0);
}
