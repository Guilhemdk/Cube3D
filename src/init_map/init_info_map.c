/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_info_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pitroin <pitroin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 21:12:16 by pitroin           #+#    #+#             */
/*   Updated: 2024/11/18 22:17:09 by pitroin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

char	*path_elem(t_map *map)
{
	int		size;
	char	*elem;

	while (ft_isalpha(map->file_map[map->i]) != 0)
		map->i++;
	while (map->file_map[map->i] == ' ')
		map->i++;
	size = 0;
	while (map->file_map[map->i+ size] != '\n' && map->file_map[map->i + size] != '\0')
		size++;
	elem = malloc(sizeof(char) * (size + 1));
	if (!elem)
		return (NULL);
	size = 0;
	while (map->file_map[map->i] != '\n' && map->file_map[map->i] != '\0')
	{
		elem[size] = map->file_map[map->i];
		size++;
		map->i++;
	}
	elem[size] = '\0';
	printf("PATH ELEM: %s\n", elem);
	return (elem);
}

int	id_texture(t_map *map)
{
	if (map->file_map[map->i] == 'N' && map->file_map[map->i + 1] == 'O')
	{
		map->file_NO = path_elem(map);
		if (!map->file_NO)
			return (-1);
	}
	if (map->file_map[map->i] == 'S' && map->file_map[map->i + 1] == 'O')
	{
		map->file_SO = path_elem(map);
		if (!map->file_SO)
			return (-1);
	}
	if (map->file_map[map->i] == 'W' && map->file_map[map->i + 1] == 'E')
	{
		map->file_WE = path_elem(map);
		if (!map->file_WE)
			return (-1);
	}
	if (map->file_map[map->i] == 'E' && map->file_map[map->i + 1] == 'A')
	{
		map->file_EA = path_elem(map);
		if (!map->file_EA)
			return (-1);
	}
	return (0);
}

int	id_color(t_map *map)
{
	if (map->file_map[map->i] == 'F' && ft_isalpha(map->file_map[map->i + 1]) == 0)
	{
		map->color_f = path_elem(map);
		if (!map->color_f)
			return (-1);
	}
	if (map->file_map[map->i] == 'C' && ft_isalpha(map->file_map[map->i + 1]) == 0)
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

	while (map->file_map[map->i] != '\0')
	{
		if (map->file_map[map->i] == '1' || map->file_map[map->i] == '0'
			|| map->file_map[map->i] == '\n' || map->file_map[map->i] == ' '
			|| (map->file_map[map->i] >= 9 && map->file_map[map->i] <= 13))
				map->i++;
		else if (map->file_map[map->i] == 'N' || map->file_map[map->i] == 'S'
			|| map->file_map[map->i] == 'W' || map->file_map[map->i] == 'E')
		{
			start++;
			if (start > 1)
				return (printf("Error: too many spawn\n"));
			map->pos_start = map->file_map[map->i];
			map->i++;
		}
		else
			return (printf("Error: wrong char\n"));
	}
	return (0);
}

int	ft_search_elem(t_map *map)
{
	int	i;

	map->i = 0;
	while (map->file_map[map->i])
	{
		while (map->file_map[map->i] == ' ')
			map->i++;
		if (map->file_map[map->i] == '1')
		{
			i = map->i;
			if (char_map(map) != 0)
				return (1);
			map->i = i;
			printf("ici\n");
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
	while (map->file_map[++map->i])
		write(1, &map->file_map[map->i], 1);
	if (ft_search_elem(map) != 0)
		return (1);
	return (0);
}
