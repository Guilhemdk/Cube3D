/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pitroin <pitroin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:52:22 by pitroin           #+#    #+#             */
/*   Updated: 2024/11/26 17:19:26 by pitroin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include "../libft/libft.h"
# include "../gnl/get_next_line.h"
# include "../minilibx-linux/mlx.h"

# define PATH_N	"../textures/N.xpm"
# define PATH_S	"../textures/S.xpm"
# define PATH_E	"../textures/E.xpm"
# define PATH_W	"../textures/W.xpm"

# define WINDOW_WIDTH 800
# define WINDOW_HEIGHT 600

typedef struct s_border
{
	int	i;
	int	j;
	int	size;
	int	space;
	int	spawn;
	int	height;
	int	width;
}	t_border;

typedef struct s_map
{
	char	*file_map;
	char	*file;
	char	*file_NO;
	char	*file_SO;
	char	*file_WE;
	char	*file_EA;
	char	*color_f;
	char	*color_c;
	char	dir_spawn;
	int		x_spawn;
	int		y_spawn;
	int		i;
	int		height;
	int		width;
}	t_map;

typedef struct s_image
{
	int		pixel_bits;
	int		line_bytes;
	int		endian;
	char	*buffer;
	void	*image;
}	t_image;

typedef struct s_win
{
	void	*mlx;
	void	*win;
	t_image	img;
	double	horizontal;
	double	vertical;
}	t_win;

typedef struct s_data
{
	t_win	w;
	t_map	m;
}	t_data;


//init map
int		init_map(t_map *map, char *file);
int		init_info_map(t_map *map);
int		check_border(t_map *map);
int		check_path(t_map *map);
int		ft_search_elem(t_map *map);
int		id_color(t_map *map);
int		id_texture(t_map *map);

//utils_map
int		is_spawn(char *str, int i);

//init window
int	init_window(t_data *d);

//utils
int		ft_strcmp(const char *s1, const char *s2);

//free
void	free_map(t_map *map);

#endif
