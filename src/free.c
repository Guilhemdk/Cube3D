/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pitroin <pitroin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 21:00:40 by pitroin           #+#    #+#             */
/*   Updated: 2024/11/18 22:12:24 by pitroin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	free_map(t_map *map)
{
	if (map->file_map)
		free(map->file_map);
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
}
