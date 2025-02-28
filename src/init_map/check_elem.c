/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 20:18:20 by marvin            #+#    #+#             */
/*   Updated: 2025/02/28 20:18:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Cube3D.h"

char	*path_elem(t_map *map)
{
	int		size;
	char	*elem;

	while (ft_isalpha(map->file[map->i]) != 0)
		map->i++;
	while (map->file[map->i] == ' ')
		map->i++;
	size = 0;
	while (map->file[map->i + size] != '\n'
		&& map->file[map->i + size] != '\0')
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

int	name_elem(t_map *map)
{
	if (is_spawn(map->file, map->i))
	{
		if (map->i == 0 && is_spawn(map->file, map->i) == 1)
			return (-1);
		if (map->file[map->i - 1] == '\n' && is_spawn(map->file, map->i) == 1)
			return (-1);
		return (-2);
	}
	if (map->i != 0)
	{
		if (map->file[map->i - 1] != '\n')
			return (-1);
	}
	if (map->file[map->i + 1] != '\0' && map->file[map->i + 2] == ' ')
	{
		if (map->file[map->i] == 'N' && map->file[map->i + 1] == 'O')
			return (1);
		else if (map->file[map->i] == 'S' && map->file[map->i + 1] == 'O')
			return (2);
		else if (map->file[map->i] == 'W' && map->file[map->i + 1] == 'E')
			return (3);
		else if (map->file[map->i] == 'E' && map->file[map->i + 1] == 'A')
			return (4);
	}
	return (-1);
}

int	id_texture2(t_map *map)
{
	if (name_elem(map) == 3)
	{
		if (!map->file_we)
		{
			map->file_we = path_elem(map);
			if (!map->file_we)
				return (printf("Error allocation malloc\n"));
		}
		else
			return (printf("Error: texture WE defined more than once\n"));
	}
	if (name_elem(map) == 4)
	{
		if (!map->file_ea)
		{
			map->file_ea = path_elem(map);
			if (!map->file_ea)
				return (printf("Error allocation malloc\n"));
		}
		else
			return (printf("Error: texture EA defined more than once\n"));
	}
	if (name_elem(map) == -1)
		return (printf("Error name elem\n"));
	return (0);
}

int	id_texture(t_map *map)
{
	if (name_elem(map) == 1)
	{
		if (!map->file_no)
		{
			map->file_no = path_elem(map);
			if (!map->file_no)
				return (printf("Error allocation malloc\n"));
		}
		else
			return (printf("Error: texture NO defined more than once\n"));
	}
	if (name_elem(map) == 2)
	{
		if (!map->file_so)
		{
			map->file_so = path_elem(map);
			if (!map->file_so)
				return (printf("Error allocation malloc\n"));
		}
		else
			return (printf("Error: texture SO defined more than once\n"));
	}
	return (id_texture2(map));
}
