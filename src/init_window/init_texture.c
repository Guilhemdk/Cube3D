/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 15:55:17 by marvin            #+#    #+#             */
/*   Updated: 2024/12/08 15:55:17 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Cube3D.h"

int	init_texture(t_data *d)
{
	d->w.img.height = 80;
	d->w.img.width = 80;

	printf("%s\n", d->m.file_NO);
	d->w.img.wallN = mlx_xpm_file_to_image(d->w.mlx, d->m.file_NO,
			&(d->w.img.width), &(d->w.img.height));
	d->w.img.wallE = mlx_xpm_file_to_image(d->w.mlx, d->m.file_EA,
			&(d->w.img.width), &(d->w.img.height));
	d->w.img.wallS = mlx_xpm_file_to_image(d->w.mlx, d->m.file_SO,
			&(d->w.img.width), &(d->w.img.height));
	d->w.img.wallW = mlx_xpm_file_to_image(d->w.mlx, d->m.file_WE,
			&(d->w.img.width), &(d->w.img.height));
	if (!d->w.img.wallN || !d->w.img.wallE || !d->w.img.wallS || !d->w.img.wallW)
		return (printf("fail\n"));
	printf("lets go\n");
	return (0);
}
