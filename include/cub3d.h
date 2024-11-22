/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pitroin <pitroin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:52:22 by pitroin           #+#    #+#             */
/*   Updated: 2024/11/22 14:00:08 by pitroin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include "../libft/libft.h"
# include "../gnl/get_next_line.h"

# define PATH_N	"../textures/N.xpm"
# define PATH_S	"../textures/S.xpm"
# define PATH_E	"../textures/E.xpm"
# define PATH_W	"../textures/W.xpm"

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


//init map
int		init_map(t_map *map, char *file);
int		init_info_map(t_map *map);
int		check_next_line(t_map *map, t_border *bord);
int		check_border(t_map *map);
int		check_path(t_map *map);

//utils_map
int		is_spawn(char *str, int i);
int		not_wall(t_map *map, t_border *bord, int f);

//utils
int		ft_strcmp(const char *s1, const char *s2);

//free
void	free_map(t_map *map);

#endif