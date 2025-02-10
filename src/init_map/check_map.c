/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pitroin <pitroin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:57:06 by pitroin           #+#    #+#             */
/*   Updated: 2025/02/10 15:26:54 by pitroin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Cube3D.h"

int	check_path(t_map *map)
{
	if (!map->file_no)
	{
		map->file_no = ft_strdup(PATH_N);
		if (!map->file_no)
			return (1);
	}
	if (!map->file_so)
	{
		map->file_so = ft_strdup(PATH_S);
		if (!map->file_so)
			return (1);
	}
	if (!map->file_ea)
	{
		map->file_ea = ft_strdup(PATH_E);
		if (!map->file_ea)
			return (1);
	}
	if (!map->file_we)
	{
		map->file_we = ft_strdup(PATH_W);
		if (!map->file_we)
			return (1);
	}
	return (0);
}

int	not_elem(t_map *map)
{
	if (map->file_no == NULL)
		map->file_no = ft_strdup(PATH_N);
	if (map->file_so == NULL)
		map->file_so = ft_strdup(PATH_S);
	if (map->file_we == NULL)
		map->file_we = ft_strdup(PATH_W);
	if (map->file_ea == NULL)
		map->file_ea = ft_strdup(PATH_E);
	if (!map->file_no || !map->file_so || !map->file_we
		|| !map->file_ea)
		return (1);
	return (0);
}

int	init_info_map(t_map *map)
{
	map->i = -1;
	if (ft_search_elem(map) != 0)
		return (1);
	if (not_elem(map) > 0)
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
	printf("Error: the file must be .cub\n");
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
		return (printf("Error: not valid file\n"));
	map->file = ft_strdup("");
	line = get_next_line(fd);
	while (line != NULL)
	{
		gnl = ft_strjoin(map->file, line);
		free(map->file);
		map->file = gnl;
		free(line);
		line = get_next_line(fd);
		map->nb_line++;
	}
	close(fd);
	if (init_info_map(map) != 0)
		return (1);
	return (0);
}
