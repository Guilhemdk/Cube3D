/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pitroin <pitroin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 21:00:40 by pitroin           #+#    #+#             */
/*   Updated: 2025/02/24 15:33:36 by pitroin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cube3D.h"

void	free_map(t_map *map)
{
	int	i;

	if (!map)
		printf("ZIZI\n");
	printf("eheh\n");
	// printf("map file %s\n", map->file);
	if (map->file)
	{
		free(map->file);
		map->file = NULL;
	}
	printf("debile\n");
	if (map->file_so)
	{
		free(map->file_so);
		map->file_so = NULL;
	}
	if (map->file_no)
	{
		free(map->file_no);
		map->file_no = NULL;
	}
	if (map->file_we)
	{
		free(map->file_we);
		map->file_we = NULL;
	}
	if (map->file_ea)
	{
		free(map->file_ea);
		map->file_ea = NULL;
	}
	if (map->color_c)
	{
		free(map->color_c);
		map->color_c = NULL;
	}
	if (map->color_f)
	{
		free(map->color_f);
		map->color_f = NULL;
	}
	if (map->file_map)
	{
		free(map->file_map);
		map->file_map = NULL;
	}
	i = 0;
	if (map->map)
	{
		while (map->map[i])
		{
			free(map->map[i]);
			map->map[i] = NULL;
			i++;
		}
		free(map->map);
		map->map = NULL;
	}
}

void	error(t_data *data, char *msg)
{
	write(1, &msg, ft_strlen(msg));
	free_map(&data->m);
}
