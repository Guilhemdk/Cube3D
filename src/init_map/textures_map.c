/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 17:18:44 by pitroin           #+#    #+#             */
/*   Updated: 2025/02/28 15:38:29 by marvin           ###   ########.fr       */
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

int	check_color(t_map *m, char **str)
{
	int i;
	int	j;

	i = 0;

	if (!str)
		return (m->flag_hex = 1);
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			// printf("%c", str[i][j]);
			if (str[i][j] < '0' || str[i][j] > '9')
				m->flag_hex = 1;
			j++;
		}
		i++;
	}
	if (i != 3)
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
		return (1);
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
	if (map->flag_hex != 0)
		return (printf("Error missing a value for color\n"));
	return (0);
}
