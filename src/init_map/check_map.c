/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pitroin <pitroin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:57:06 by pitroin           #+#    #+#             */
/*   Updated: 2024/11/18 21:21:57 by pitroin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	check_next_line(t_map *map, int size, int space)
{
	int	j;
	int	i;

	j = map->i;
	if (space == 0)
		return (0);
	while (map->file_map[j] != '\n')
		j++;
	j += size -1;
	i = -1;
	printf("eee\n");
	while (++i <= space + 1)
	{
		printf("%c\n", map->file_map[j]);
		if (map->file_map[j] != '1')
			return (printf("Error: Border not closed\n"));
		j++;
	}
	return (0);
}

int	check_border(t_map *map)
{
	int size;
	int	space;

	size = 1;
	printf("%s\n", &map->file_map[map->i]);
	while (map->i - size >= 0 && map->file_map[map->i - size] == ' ')
		size++;
	while (!(map->file_map[map->i] >= 9 && map->file_map[map->i] <= 13))
	{
		space = 0;
		while (map->file_map[map->i] == '1')
		{
			size++;
			map->i++;
		}
		while (map->file_map[map->i + space] == ' ')
			space++;
		if (check_next_line(map, size, space) == 1)
			return (1);
		map->i += space;
	}
	return (0);
}

int	check_type_map(char *file)
{
	char	*check;

	check = ft_strchr(file, '.');
	if (!check)
		return (1);
	if (ft_strcmp(check,".cub") == 0)
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
	map->file_map = ft_strdup("");
	line = get_next_line(fd);
	while (line != NULL)
	{
		gnl = ft_strjoin(map->file_map, line);
		free(map->file_map);
		map->file_map = gnl;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	if (init_info_map(map) != 0)
		return (1);
	return (0);
}
