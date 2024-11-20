/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_border.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pitroin <pitroin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 10:15:48 by pitroin           #+#    #+#             */
/*   Updated: 2024/11/20 13:44:38 by pitroin          ###   ########.fr       */
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

// int	first_line(t_map *map, t_border *bord)
// {
// 	while (map->i - bord->size >= 0 && map->file[map->i - bord->size] == ' ')
// 		bord->size++;
// 	while (!(map->file[map->i] >= 9 && map->file[map->i] <= 13))
// 	{
// 		bord->space = 0;
// 		while (map->file[map->i] == '1')
// 		{
// 			bord->size++;
// 			map->i++;
// 		}
// 		if (not_wall(map, bord, 0) != 0)
// 			return (1);
// 		map->i += bord->space;
// 	}
// 	return (0);
// }

// int	recurs_border(t_map *map, int i)
// {
// 	if (map->file_map[i + 1] == '0')
// 		recurs_border9(map, i + 1);
// 	else if (map->file_map[i + 1] == '1')
// }

// int	extend_spawn(t_map *map)
// {
// 	if (map->y_spawn == 0 || map->x_spawn == 0 || map->x_spawn == map->width)
// 		return (printf("Error: Spawn in border\n"));
// 	printf("spawn: %c", map->file_map[map->y_spawn * map->width + map->x_spawn]);
// 	if (map->file_map[map->y_spawn * map->width + map->x_spawn + 1] == '0')
// 		return (recurs_border(map, map->y_spawn * map->width + map->x_spawn + 1));
// 	else if (map->file_map[map->y_spawn * map->width + map->x_spawn - 1] == '0')
// 		return (recurs_border(map, map->y_spawn * map->width + map->x_spawn + 1));
// 	else if (map->file_map[map->y_spawn * map->width + map->x_spawn + map->width] == '0')
// 		return (recurs_border(map, map->y_spawn * map->width + map->x_spawn + 1));
// 	else if (map->file_map[map->y_spawn * map->width + map->x_spawn - map->width] == '0')
// 		return (recurs_border(map, map->y_spawn * map->width + map->x_spawn + 1));
// 	else
// 		return (1);
// }

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
	map->y_spawn = 1;
	map->x_spawn = 0;
	while (map->file_map[i] != '\0')
	{
		if (is_spawn(map->file_map, i) == 0)
		{
			printf(">%d<\n", map->width);
			return ;
		}
		if (map->file_map[i] == '\n')
		{
			map->y_spawn++;
			map->x_spawn = 0;
		}
		map->x_spawn++;
		i++;
	}
}

int	check_border(t_map *map)
{
	t_border	bord;

	init_border(&bord);
	locate_spawn(map);
	printf("map->x_spawn = %d et map->y_spawn %d\n", map->x_spawn, map->y_spawn);
	// if (first_line(map, &bord) != 0)
	// 	return (1);
	return (0);
}