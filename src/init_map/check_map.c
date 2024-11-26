/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pitroin <pitroin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:57:06 by pitroin           #+#    #+#             */
/*   Updated: 2024/11/26 16:32:10 by pitroin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	check_path(t_map *map)
{
	if (!map->file_NO)
	{
		map->file_NO = ft_strdup(PATH_N);
		if (!map->file_NO)
			return (1);
	}
	if (!map->file_SO)
	{
		map->file_SO = ft_strdup(PATH_S);
		if (!map->file_SO)
			return (1);
	}
	if (!map->file_EA)
	{
		map->file_EA = ft_strdup(PATH_E);
		if (!map->file_EA)
			return (1);
	}
	if (!map->file_WE)
	{
		map->file_WE = ft_strdup(PATH_W);
		if (!map->file_WE)
			return (1);
	}
	return (0);
}

int	init_info_map(t_map *map)
{
	map->i = -1;
	if (ft_search_elem(map) != 0)
		return (1);
	if (check_path(map) != 0)
		return (1);
	return (0);
}

int	check_type_map(char *file)
{
	char	*check;

	check = ft_strchr(file, '.');
	if (!check)
		return (1);
	if (ft_strcmp(check, ".cub") == 0)
		return (0);
	return (1);
}

int	init_map(t_map *map, char *file)
{
	int		fd;
	char	*line;
	char	*gnl;

	map->color_c = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0 || check_type_map(file) == 1)
		return (1);
	map->file = ft_strdup("");
	line = get_next_line(fd);
	while (line != NULL)
	{
		gnl = ft_strjoin(map->file, line);
		free(map->file);
		map->file = gnl;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	printf("%s\n", map->file);
	if (init_info_map(map) != 0)
		return (1);
	return (0);
}
