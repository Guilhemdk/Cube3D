/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pitroin <pitroin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 21:00:40 by pitroin           #+#    #+#             */
/*   Updated: 2025/01/20 16:31:10 by pitroin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cube3D.h"

void	free_map(t_map *map)
{
	int	i;

	if (map->file)
		free(map->file);
	if (map->file_SO)
		free(map->file_SO);
	if (map->file_NO)
		free(map->file_NO);
	if (map->file_WE)
		free(map->file_WE);
	if (map->file_EA)
		free(map->file_EA);
	if (map->color_c)
		free(map->color_c);
	if (map->color_f)
		free(map->color_f);
	if (map->file_map)
		free(map->file_map);
	i = 0;
	if (map->map)
	{
		while (map->map[i])
			free(map->map[i++]);
		free(map->map);
	}
}

void	error(t_data *data, char *msg)
{
	write(1, &msg, ft_strlen(msg));
	free_map(&data->m);
}
