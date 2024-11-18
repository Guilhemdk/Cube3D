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
}

int	main(int ac, char **av)
{
	t_map	map;

	if (ac != 2)
		return (printf("ERROR\n"));
	init_struct(&map);
	if (init_map(&map, av[1]) > 0)
		return (printf("Error\n"));
	// init_window minilibx
	// exec_game()
	// exit propre
	printf("\nHELLO WORLD\n");
	free_map(&map);
	return (0);
}