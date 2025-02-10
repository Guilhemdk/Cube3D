/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pitroin <pitroin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:54:42 by pitroin           #+#    #+#             */
/*   Updated: 2025/02/10 17:38:00 by pitroin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/Cube3D.h"

int	escape_event(t_win *w, t_map *map)
{
	mlx_destroy_image(w->mlx, w->tex_no.img);
	mlx_destroy_image(w->mlx, w->tex_so.img);
	mlx_destroy_image(w->mlx, w->tex_we.img);
	mlx_destroy_image(w->mlx, w->tex_ea.img);
	if (w->img.image)
		mlx_destroy_image(w->mlx, w->img.image);
	mlx_clear_window(w->mlx, w->win);
	mlx_destroy_window(w->mlx, w->win);
	mlx_destroy_display(w->mlx);
	free(w->mlx);
	free_map(map);
	exit(EXIT_SUCCESS);
	return (1);
}

int	release_key(int key, t_data *data)
{
	if (key == DOWN_KEY || key == UP_KEY)
		data->player.move_u_d = 0;
	else if (key == LEFT_KEY || key == RIGHT_KEY)
		data->player.move_l_r = 0;
	else if (key == LEFT_ARROW || key == RIGHT_ARROW)
		data->player.rotation = 0;
	return (0);
}

int	generate_event(int key, t_data *data)
{
	if (key == UP_KEY)
		data->player.move_u_d = 1;
	else if (key == DOWN_KEY)
		data->player.move_u_d = -1;
	else if (key == LEFT_KEY)
		data->player.move_l_r = -1;
	else if (key == RIGHT_KEY)
		data->player.move_l_r = 1;
	else if (key == LEFT_ARROW)
		data->player.rotation = -1;
	else if (key == RIGHT_ARROW)
		data->player.rotation = 1;
	else if (key == ESC_KEY)
		escape_event(&data->w, &data->m);
	return (0);
}
