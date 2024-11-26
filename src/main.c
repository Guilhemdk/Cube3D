/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pitroin <pitroin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:52:03 by pitroin           #+#    #+#             */
/*   Updated: 2024/11/25 13:37:04 by pitroin          ###   ########.fr       */
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
	t_data	data;

	if (ac != 2)
		return (printf("ERROR\n"));
	init_struct(&data.m);
	if (init_map(&data.m, av[1]) > 0)
		return(free_map(&data.m), 1);
	else
		printf("\nGG !\n");
	init_window(&data);
	// exec_game()
	// exit propre
	free_map(&data.m);
	return (0);
}
