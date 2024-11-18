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

int	check_type_map(char *file)
{
	int	i;
	char	*check;

	i = 0;
	check = ft_strchr(file, '.');
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
	init_info_map(map);
	return (0);
}
