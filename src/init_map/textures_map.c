/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 17:18:44 by pitroin           #+#    #+#             */
/*   Updated: 2024/12/21 21:17:57 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Cube3D.h"

void load_map(t_map *map, const char *filename)
{
    int     fd;
    char    *line;
    int     i;

    // Allouer de la mémoire pour le tableau des lignes
    map->map = malloc(sizeof(char *) * (map->nb_line + 1)); // +1 pour NULL à la fin
    if (!map->map)
        return; // Gestion d'erreur d'allocation mémoire

    fd = open(filename, O_RDONLY);
    if (fd < 0)
    {
        free(map->map);
        map->map = NULL; // Protection en cas d'échec
        return; // Gestion d'erreur d'ouverture de fichier
    }

    i = 0;
    while ((line = get_next_line(fd)) != NULL)
    {
        map->map[i] = ft_strdup(line); // Chaque ligne est stockée dans le tableau
		free(line);
        i++;
    }
    map->map[i] = NULL; // Marquer la fin du tableau
    close(fd);
}


char	*path_elem(t_map *map)
{
	int		size;
	char	*elem;

	while (ft_isalpha(map->file[map->i]) != 0)
		map->i++;
	while (map->file[map->i] == ' ')
		map->i++;
	size = 0;
	while (map->file[map->i+ size] != '\n'
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
