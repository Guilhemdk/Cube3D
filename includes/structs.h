//structs Pierre

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
	char	**map;
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
	double	zoom;
	double	horizontal;
	double	vertical;
	double	rotation_angle_x;
	double	rotation_angle_y;
	double	rotation_angle_z;
	int		perspective;
}	t_win;

//Structs Guilhem
typedef struct s_ray
{
	double angle;
	double distance;
	double wall_flag;
}	t_ray;

typedef struct s_wall
{
	double dist;
	int height;
	int start;
	int end;
}	t_wall;

typedef struct s_player
{
	int posX;
	int posY;
	float fov;
	double angle;
}	t_player;

typedef struct s_data
{
	t_win	w;
	t_map	m;
	t_ray rc;
	t_player player;
	t_wall wall;
}	t_data;
