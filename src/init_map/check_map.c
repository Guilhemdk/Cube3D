/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pitroin <pitroin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:57:06 by pitroin           #+#    #+#             */
/*   Updated: 2024/11/20 11:53:05 by pitroin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

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
