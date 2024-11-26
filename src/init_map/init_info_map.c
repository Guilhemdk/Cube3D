/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_info_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pitroin <pitroin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 21:12:16 by pitroin           #+#    #+#             */
/*   Updated: 2024/11/26 17:21:29 by pitroin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	char_map(t_map *map)
{
	int	start;

	start = 0;
	while (map->file[map->i] != '\0')
	{
		if (map->file[map->i] == '1' || map->file[map->i] == '0'
			|| map->file[map->i] == '\n' || map->file[map->i] == ' '
			|| (map->file[map->i] >= 9 && map->file[map->i] <= 13))
				map->i++;
		else if (is_spawn(map->file, map->i) == 0)
		{
			start++;
			if (start > 1)
				return (printf("Error: too many spawn\n"));
			map->dir_spawn = map->file[map->i];
			map->i++;
		}
		else
			return (printf("Error: wrong char\n"));
	}
	if (start == 0)
		return (printf("Error: not spawn\n"));
	return (0);
}

int	size_map(t_map *map, int i)
{
	int		size;

	map->width = 0;
	map->height = 0;
	while (map->file[i] != '\0')
	{
		size = 0;
		while (map->file[i] != '\n' && map->file[i] != '\0')
		{
			size++;
			i++;
		}
		if (size > map->width)
			map->width = size + 1;
		if (map->file[i] != '\0')
			i++;
		map->height++;
	}
	return (map->height * map->width);
}

void	add_in_file(t_map *map, int j)
{
	int	i;

	i = 0;
	while (map->file[j] != '\0')
	{
		while (map->file[j] != '\n' && map->file[j] != '\0'
			&& !(map->file[j] >= 9 && map->file[j] <= 13))
		{
			map->file_map[i] = map->file[j];
			i++;
			j++;
		}
		while ((i % map->width != 0 || i < map->width))
		{
			map->file_map[i] = '-';
			i++;
		}
		if (map->file[j] != '\0')
		{
			map->file_map[--i] = '\n';
			i++;
			j++;
		}
	}
	map->file_map[--i] = '\0';
}

int	create_file(t_map *map)
{
	int		i;

	i = 1;
	if (map->i - i >= 0 && map->file[map->i - i] == ' ')
	{
		while (map->i - i >= 0 && map->file[map->i - i] == ' ')
			i++;
		i--;
	}
	else
		i = 0;
	map->file_map = malloc(sizeof(char) * (size_map(map, map->i - i) + 1));
	if (!map->file_map)
		return (1);
	add_in_file(map, map->i - i);
	printf("file_map>\n%s\n<", map->file_map);
	return (0);
}

int	ft_search_elem(t_map *map)
{
	int	i;

	map->i = 0;
	while (map->file[map->i])
	{
		while (map->file[map->i] == ' ')
			map->i++;
		if (map->file[map->i] == '1')
		{
			i = map->i;
			if (char_map(map) != 0 )
				return (1);
			map->i = i;
			if (create_file(map) != 0)
				return (1);
			return(check_border(map));
		}
		else if (id_texture(map) == -1)
			return (printf("Error allocation malloc\n"));
		else if (id_color(map) == -1)
			return (printf("Error allocation malloc\n"));
		else
			map->i++;
	}
	return (1);
}
