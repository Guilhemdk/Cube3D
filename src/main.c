/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pitroin <pitroin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:52:03 by pitroin           #+#    #+#             */
/*   Updated: 2024/11/18 21:50:18 by pitroin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	init_struct(t_map *map)
{
	map->file_SO = NULL;
	map->file_NO = NULL;
	map->file_WE = NULL;
	map->file_EA = NULL;
	map->color_c = NULL;
	map->color_f = NULL;
}

int	main(int ac, char **av)
{
	t_map	map;

	if (ac != 2)
		return (printf("ERROR\n"));
	init_struct(&map);
	if (init_map(&map, av[1]) > 0)
		printf("Error\n");
	else
		printf("\nHELLO WORLD\n");
	// init_window minilibx
	// exec_game()
	// exit propre
	free_map(&map);
	return (0);
}