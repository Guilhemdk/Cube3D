/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pitroin <pitroin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 09:40:58 by pitroin           #+#    #+#             */
/*   Updated: 2025/01/22 11:42:33 by pitroin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	char			**map;
	char			*file_map;
	char			*file;
	char			*file_no;
	char			*file_so;
	char			*file_we;
	char			*file_ea;
	char			*color_f;
	char			*color_c;
	unsigned int	hex_f;
	unsigned int	hex_c;
	char			dir_spawn;
	int				nb_line;
	int				x_spawn;
	int				y_spawn;
	int				i;
	int				height;
	int				width;
}	t_map;

typedef struct s_image
{
	int				pixel_bits;
	int				line_bytes;
	int				endian;
	char			*buffer;
	void			*image;
}	t_image;

typedef struct s_texture
{
	void			*img;
	char			*addr;
	int				width;
	int				height;
	int				bpp;
	int				line_length;
	int				endian;
}	t_texture;

typedef struct s_win
{
	void			*mlx;
	void			*win;
	t_image			img;
	double			zoom;
	double			horizontal;
	double			vertical;
	double			rotation_angle_x;
	double			rotation_angle_y;
	double			rotation_angle_z;
	int				perspective;
	t_texture		tex_no;
	t_texture		tex_so;
	t_texture		tex_we;
	t_texture		tex_ea;
}	t_win;

typedef struct s_ray
{
	double			angle;
	double			distance;
	double			wall_flag;
	double			wall_hit;
	double			wall_hit_x;
	double			wall_hit_y;
	float			h_hitx;
	float			h_hity;
	float			v_hitx;
	float			v_hity;
	double			closest_h_wall;
	double			closest_v_wall;
	int				ray;
}	t_ray;

typedef struct s_wall
{
	double			dist;
	int				height;
	int				start;
	int				end;
}	t_wall;

typedef struct s_player
{
	int				posx;
	int				posy;
	float			fov;
	double			angle;
	double			rotation;
	int				move_l_r;
	int				move_u_d;
}	t_player;

typedef struct s_data
{
	t_win			w;
	t_map			m;
	t_ray			rc;
	t_player		player;
	t_wall			wall;
}	t_data;
