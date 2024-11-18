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

char	*path_elem(t_map *map, int i)
{
	int	size;
	char *elem;

	i += 2;
	while (map->file_map[i] == ' ')
		i++;
	size = 0;
	while (map->file_map[i + size] != '\n' && map->file_map[i + size] != '\0')
		size++;
	elem = malloc(sizeof(char) * (size + 1));
	if (!elem)
		return (NULL);
	size = 0;
	while (map->file_map[i] != '\n' && map->file_map[i] != '\0')
	{
		elem[size] = map->file_map[i];
		size++;
		i++;
	}
	elem[size] = '\0';
	printf("\nPATH ELEM: %s\n", elem);
	return (elem);
}

int	id_texture(t_map *map, char a, char b, int i)
{
	if (a == 'N' && b == 'O')
	{
		map->file_NO = path_elem(map, i);
		if (!map->file_NO)
			return (-1);
	}
	if (a == 'S' && b == 'O')
	{
		map->file_SO = path_elem(map, i);
		if (!map->file_SO)
			return (-1);
	}
	if (a == 'W' && b == 'E')
	{
		map->file_WE = path_elem(map, i);
		if (!map->file_WE)
			return (-1);
	}
	if (a == 'E' && b == 'A')
	{
		map->file_EA = path_elem(map, i);
		if (!map->file_EA)
			return (-1);
	}
	return (0);
}

int	ft_search_elem(t_map *map)
{
	int	i;

	i = 0;
	while (map->file_map[i])
	{
		while (map->file_map[i] == ' ')
			i++;
		if (map->file_map[i] == '1')
		{
			while (map->file_map[i] != '\n' && map->file_map[i] != '\0')
				i++;
		}
		else if (id_texture(map, map->file_map[i], map->file_map[i + 1], i) == -1)
			return (1);
		else
			i++;
	}
	return (0);
}

int	init_info_map(t_map *map)
{
	int	i;

	i = -1;
	while (map->file_map[++i])
		write(1, &map->file_map[i], 1);
	ft_search_elem(map);
	return (0);
}
