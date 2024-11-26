/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pitroin <pitroin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 10:32:36 by pitroin           #+#    #+#             */
/*   Updated: 2024/11/20 11:50:37 by pitroin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	is_spawn(char *str, int i)
{
	if (str[i] == 'S' || str[i] == 'N' || str[i] == 'O'
		|| str[i] == 'W')
		return (0);
	return (1);
}

int	not_wall(t_map *map, t_border *bord, int f)
{
	bord->space = 0;
	while (map->file[map->i + bord->space] == ' ')
		bord->space++;
	if (f == 0 && is_spawn(map->file, map->i + bord->space) == 0)
		return (printf("Error: Spawn in border\n"));
	if (f == 0 && map->file[map->i + bord->space] == '0')
		return (printf("Error: Border not closed\n"));
	if (check_next_line(map, bord) != 0)
		return (1);
	return (0);
}
