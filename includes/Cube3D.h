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
void calc_rays(t_data *data);
void exec_game(t_data *data);
float norm_angle(float angle);
void DDa(t_data *data, int ray);
void put_pixel(t_image *img, int x, int y, int color);

//keys
int generate_event(int key, t_data *data);
int release_key(int key, t_data *data);
int escape_event(t_win *w);

//move_player
void hook(t_data *data, double move_x, double move_y);

//init map
int		init_map(t_map *map, char *file);
int		init_info_map(t_map *map);
int		check_border(t_map *map);
int		check_path(t_map *map);
void	load_map(t_map *map, const char *filename);
int		ft_search_elem(t_map *map);
int		id_color(t_map *map);
int		id_texture(t_map *map);
char	*path_elem(t_map *map);
int		is_spawn(char *str, int i);


//tex_render
int		load_textures(t_data *data, void *mlx);

//init window
int		init_window(t_data *d);
void	image_to_window(t_win *win);

//utils
void	*safe_malloc(size_t bytes, t_data *data);
void	set_tab(t_data *data);
int		ft_strcmp(const char *s1, const char *s2);

//free
void	error(t_data *data, char *msg);
void	free_map(t_map *map);
#endif
