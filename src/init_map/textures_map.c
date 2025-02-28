/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 17:18:44 by pitroin           #+#    #+#             */
/*   Updated: 2025/02/28 20:29:59 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Cube3D.h"

int	is_int(t_map *m, char **str)
{
	int	i;
	int	j;

	i = 0;
	if (!str)
		return (m->flag_hex = 1);
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] < '0' || str[i][j] > '9')
			{
				m->flag_hex = 1;
				return (printf("Error: color not valid\n"));
			}
			j++;
		}
		i++;
	}
	return (i);
}

int	check_color(t_map *m, char **str)
{
	int	i;

	i = 0;
	if (is_int(m, str) != 3)
	{
		m->flag_hex = 1;
		i = 0;
		while (str[i])
		{
			free(str[i]);
			str[i] = NULL;
			i++;
		}
		free(str);
		return (printf("Error: color is not RGB\n"));
	}
	return (0);
}

unsigned int	rgb_to_hex(t_map *m, char *rgb_str)
{
	int				r;
	int				g;
	int				b;
	char			**rgb_values;
	unsigned int	hex_color;

	rgb_values = ft_split(rgb_str, ',');
	if (check_color(m, rgb_values) > 0)
		return (0);
	r = atoi(rgb_values[0]);
	g = atoi(rgb_values[1]);
	b = atoi(rgb_values[2]);
	free(rgb_values[0]);
	free(rgb_values[1]);
	free(rgb_values[2]);
	free(rgb_values);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
	{
		m->flag_hex = 1;
		return (0);
	}
	hex_color = (r << 16) | (g << 8) | b;
	return (hex_color);
}

int	id_color_2(t_map *map)
{
	if (map->file[map->i] == 'C')
	{
		if (!(map->file[map->i + 1] == ' ' && map->file[map->i - 1] == '\n'))
			return (printf("Error initialized C\n"));
		if (!map->color_c)
		{
			map->color_c = path_elem(map);
			if (!map->color_c)
				return (printf("Error allocation malloc\n"));
			map->hex_c = rgb_to_hex(map, map->color_c);
		}
		else
			return (printf("Error: texture C defined more than once\n"));
	}
	return (map->flag_hex);
}

int	id_color(t_map *map)
{
	if (map->file[map->i] == 'F')
	{
		if (!(map->file[map->i + 1] == ' ' && map->file[map->i - 1] == '\n'))
			return (printf("Error initialized F\n"));
		if (!map->color_f)
		{
			map->color_f = path_elem(map);
			if (!map->color_f)
				return (printf("Error allocation malloc\n"));
			map->hex_f = rgb_to_hex(map, map->color_f);
		}
		else
			return (printf("Error: texture F defined more than once\n"));
	}
	return (id_color_2(map));
}
