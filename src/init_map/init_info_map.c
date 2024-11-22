/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_info_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pitroin <pitroin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 21:12:16 by pitroin           #+#    #+#             */
/*   Updated: 2024/11/22 13:12:23 by pitroin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

char	*path_elem(t_map *map)
{
	int		size;
	char	*elem;

	while (ft_isalpha(map->file[map->i]) != 0)
		map->i++;
	while (map->file[map->i] == ' ')
		map->i++;
	size = 0;
	while (map->file[map->i+ size] != '\n' && map->file[map->i + size] != '\0')
		size++;
	elem = malloc(sizeof(char) * (size + 1));
	if (!elem)
		return (NULL);
	size = 0;
	while (map->file[map->i] != '\n' && map->file[map->i] != '\0')
	{
		elem[size] = map->file[map->i];
		size++;
		map->i++;
	}
	elem[size] = '\0';
	return (elem);
}

int	id_texture(t_map *map)
{
	if (map->file[map->i] == 'N' && map->file[map->i + 1] == 'O')
	{
		map->file_NO = path_elem(map);
		if (!map->file_NO)
			return (-1);
	}
	if (map->file[map->i] == 'S' && map->file[map->i + 1] == 'O')
	{
		map->file_SO = path_elem(map);
		if (!map->file_SO)
			return (-1);
	}
	if (map->file[map->i] == 'W' && map->file[map->i + 1] == 'E')
	{
		map->file_WE = path_elem(map);
		if (!map->file_WE)
			return (-1);
	}
	if (map->file[map->i] == 'E' && map->file[map->i + 1] == 'A')
	{
		map->file_EA = path_elem(map);
		if (!map->file_EA)
			return (-1);
	}
	return (0);
}

int	id_color(t_map *map)
{
	if (map->file[map->i] == 'F' && ft_isalpha(map->file[map->i + 1]) == 0)
	{
		map->color_f = path_elem(map);
		if (!map->color_f)
			return (-1);
	}
	if (map->file[map->i] == 'C' && ft_isalpha(map->file[map->i + 1]) == 0)
	{
		map->color_c = path_elem(map);
		if (!map->color_c)
			return (-1);
	}
	return (0);
}

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

int	init_info_map(t_map *map)
{
	map->i = -1;
	if (ft_search_elem(map) != 0)
		return (1);
	return (0);
}
