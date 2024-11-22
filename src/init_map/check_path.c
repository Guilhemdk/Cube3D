/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pitroin <pitroin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:30:42 by pitroin           #+#    #+#             */
/*   Updated: 2024/11/22 14:01:28 by pitroin          ###   ########.fr       */
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
