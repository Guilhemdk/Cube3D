#ifndef CUBE3D_H
#define CUBE3D_H

# include <math.h>
#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include "structs.h"
#include "macros.h"
# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"
# include "../minilibx-linux/mlx.h"

//init_game_vars
void init_player(t_data *data);
void init_data(t_player *player, t_ray *raycast, t_data *data);

//raycasting
void exec_game(t_data *data);
float norm_angle(float angle);
void DDA(t_data *data, int ray);
void putPixelToBuffer(int x, int y, int color);
int getWallColor();


//init map
int		init_map(t_map *map, char *file);
int		init_info_map(t_map *map);
int		check_next_line(t_map *map, t_border *bord);
int		check_border(t_map *map);
int		check_path(t_map *map);

//utils_map
int		is_spawn(char *str, int i);
int		not_wall(t_map *map, t_border *bord, int f);

//init window
int	init_window(t_data *d);

//utils
int		ft_strcmp(const char *s1, const char *s2);

//free
void	free_map(t_map *map);
#endif
