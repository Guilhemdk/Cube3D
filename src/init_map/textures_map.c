/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pitroin <pitroin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 17:18:44 by pitroin           #+#    #+#             */
/*   Updated: 2025/01/21 08:01:46 by pitroin          ###   ########.fr       */
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

unsigned int	rgb_to_hex(char *rgb_str)
{
	int				r;
	int				g;
	int				b;
	char			**rgb_values;
	unsigned int	hex_color;

	rgb_values = ft_split(rgb_str, ',');
	if (!rgb_values)
		return (0);
	r = atoi(rgb_values[0]);
	g = atoi(rgb_values[1]);
	b = atoi(rgb_values[2]);
	free(rgb_values[0]);
	free(rgb_values[1]);
	free(rgb_values[2]);
	free(rgb_values);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return (0);
	hex_color = (r << 16) | (g << 8) | b;
	return (hex_color);
}

int	id_color(t_map *map)
{
	if (map->file[map->i] == 'F' && ft_isalpha(map->file[map->i + 1]) == 0)
	{
		map->color_f = path_elem(map);
		if (!map->color_f)
			return (-1);
		map->hex_f = rgb_to_hex(map->color_f);
	}
	if (map->file[map->i] == 'C' && ft_isalpha(map->file[map->i + 1]) == 0)
	{
		map->color_c = path_elem(map);
		if (!map->color_c)
			return (-1);
		map->hex_c = rgb_to_hex(map->color_c);
	}
	return (0);
}

int	not_elem(t_map *map)
{
	if (map->file_NO == NULL)
		map->file_NO = ft_strdup(PATH_N);
	if (map->file_SO == NULL)
		map->file_SO = ft_strdup(PATH_S);
	if (map->file_WE == NULL)
		map->file_WE = ft_strdup(PATH_W);
	if (map->file_EA == NULL)
		map->file_EA = ft_strdup(PATH_E);
	if (!map->file_NO || !map->file_SO || !map->file_WE
		|| !map->file_EA)
		return (1);
	return (0);
}
