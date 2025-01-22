/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tex_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pitroin <pitroin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:55:06 by pitroin           #+#    #+#             */
/*   Updated: 2025/01/21 09:42:12 by pitroin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/Cube3D.h"

int	load_textures_2(t_data *data)
{
	data->w.tex_no.addr = mlx_get_data_addr(data->w.tex_no.img,
			&data->w.tex_no.bpp,
			&data->w.tex_no.line_length, &data->w.tex_no.endian);
	data->w.tex_so.addr = mlx_get_data_addr(data->w.tex_so.img,
			&data->w.tex_so.bpp,
			&data->w.tex_so.line_length, &data->w.tex_so.endian);
	data->w.tex_we.addr = mlx_get_data_addr(data->w.tex_we.img,
			&data->w.tex_we.bpp,
			&data->w.tex_we.line_length, &data->w.tex_we.endian);
	data->w.tex_ea.addr = mlx_get_data_addr(data->w.tex_ea.img,
			&data->w.tex_ea.bpp,
			&data->w.tex_ea.line_length, &data->w.tex_ea.endian);
	if (!data->w.tex_no.addr || !data->w.tex_so.addr
		|| !data->w.tex_ea.addr || !data->w.tex_we.addr)
		return (1);
	return (0);
}

int	load_textures(t_data *data, void *mlx)
{
	data->w.tex_no.img = mlx_xpm_file_to_image(mlx, data->m.file_no,
			&data->w.tex_no.width, &data->w.tex_no.height);
	data->w.tex_so.img = mlx_xpm_file_to_image(mlx, data->m.file_so,
			&data->w.tex_so.width, &data->w.tex_so.height);
	data->w.tex_we.img = mlx_xpm_file_to_image(mlx, data->m.file_we,
			&data->w.tex_we.width, &data->w.tex_we.height);
	data->w.tex_ea.img = mlx_xpm_file_to_image(mlx, data->m.file_ea,
			&data->w.tex_ea.width, &data->w.tex_ea.height);
	if (!data->w.tex_no.img || !data->w.tex_so.img
		|| !data->w.tex_we.img || !data->w.tex_ea.img)
		return (1);
	return (load_textures_2(data));
}
