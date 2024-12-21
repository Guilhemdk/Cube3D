#include "../../includes/Cube3D.h"

float norm_angle(float angle)
{
	if (angle < 0)
		angle += (2 * PI);
	else if (angle > 2 * PI)
		angle -= 2 * PI;
	return (angle);
}

int inter_check(float angle, float inter, float step, int is_horizon)
{
	if (is_horizon)
	{
		if (angle > 0 && angle < PI)
		{
			inter += TILE_SIZE;
			return (-1);
		}
		step *= -1;
	}
	else
	{
		if (!(angle > PI / 2 && angle < 3 * PI / 2))
		{
			inter *= TILE_SIZE;
			return (-1);
		}
		step *= -1;
	}
	return (1);
}

int ray_orientation(float angle, char c)
{
	if (c == 'x')
	{
		if (angle > 0 && angle < PI)
			return (1); //looking at the upper half of the circle
	}
	else if (c == 'y')
		if (angle > (PI / 2) && angle < (3 * PI) / 2)
			return (1);  //looking at the half left of circle
	return (0);  //one of the 2 left areas, depending on 'c'
}

int wall_hit(float x, float y, t_data *data)
{
	int map_x;
	int map_y;

	if (x < 0 || y < 0)
		return (1);
	map_x = floor(x / TILE_SIZE);
	map_y = floor(y / TILE_SIZE);
	if (map_y >= data->m.height || map_x >= data->m.width)
		return (1);
	if (data->m.map[map_y] && map_x <= (int)ft_strlen(data->m.map[map_y]))
		if (data->m.map[map_y][map_x] == '1')
			return (1);
	return (0);
}

static float get_next_h_wall(t_data *data, float angle)
{
	float x_step;
	float y_step;
	float xray_intersection;
	float yray_intersection;
	int io_wall;

	y_step = TILE_SIZE;
	x_step = TILE_SIZE / tan(angle);
	yray_intersection = floor(data->player.posY / TILE_SIZE) * TILE_SIZE;
	io_wall = inter_check(angle, yray_intersection, y_step, 1);
	xray_intersection = data->player.posX + (yray_intersection - data->player.posY) / tan(angle);
	if ((ray_orientation(angle, 'y') && x_step > 0) || (!ray_orientation(angle, 'y') && x_step < 0))
		x_step *= -1;
	while(!wall_hit(xray_intersection, yray_intersection - io_wall, data))
	{
		yray_intersection += y_step;
		xray_intersection += x_step;
	}
	return (sqrt(pow(xray_intersection - data->player.posX, 2) + pow(yray_intersection - data->player.posY, 2)));
}

static float get_next_v_wall(t_data *data, float angle)
{
	float x_step;
	float y_step;
	float xray_intersection;
	float yray_intersection;
	int io_wall;

	x_step = TILE_SIZE;
	y_step = TILE_SIZE / tan(angle);
	xray_intersection = floor(data->player.posX / TILE_SIZE) * TILE_SIZE;
	io_wall = inter_check(angle, xray_intersection, x_step, 1);
	yray_intersection = data->player.posY + (xray_intersection - data->player.posX) * tan(angle);
	if ((ray_orientation(angle, 'x') && y_step < 0) || (!ray_orientation(angle, 'x') && y_step > 0))
		y_step *= -1;
	while (!wall_hit(xray_intersection - io_wall, yray_intersection, data))
	{
		xray_intersection += x_step;
		yray_intersection += y_step;
	}
	return (sqrt(pow(xray_intersection - data->player.posX, 2) + pow(yray_intersection - data->player.posY, 2)));
}

void image_to_window(t_win *mlx, t_data *data)
{
	if (mlx->img.image)
	{
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.image, 0, 0);
		mlx_destroy_image(mlx->mlx, mlx->img.image);
	}
	mlx->img.image = mlx_new_image(mlx->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!mlx->img.image)
		error(data, MLX_ERR);
	mlx->img.buffer = mlx_get_data_addr(mlx->img.image, \
			&mlx->img.pixel_bits, &mlx->img.line_bytes, &mlx->img.endian);
}

void calc_rays(t_data *data)
{
	double closest_h_wall;
	double closest_v_wall;
	int ray;


	ray = 0;
	data->rc.angle = data->player.angle - (data->player.fov / 2);
	while(ray < SCREEN_WIDTH)
	{
		data->rc.wall_flag = 0;
		closest_h_wall = get_next_h_wall(data, norm_angle(data->rc.angle));
		closest_v_wall = get_next_v_wall(data, norm_angle(data->rc.angle));
		if (closest_v_wall <= closest_h_wall)
			data->rc.distance = closest_v_wall;
		else
		{
			data->rc.distance = closest_h_wall;
			data->rc.wall_flag = 1;
		}
		DDa(data, ray);
		ray++;
		data->rc.angle += (data->player.fov / SCREEN_WIDTH);
	}
	image_to_window(data->w.mlx, data);
}

void exec_game(t_data *data)
{
	t_win *mlx;

	mlx = &data->w;
	mlx->img.image = mlx_new_image(data->w.mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	mlx->img.buffer = mlx_get_data_addr(mlx->img.image, \
			&mlx->img.pixel_bits, &mlx->img.line_bytes, &mlx->img.endian);
	calc_rays(data);
//	mlx_hook(data->w, 2, 1L << 0, generate_event, data);
	mlx_loop(mlx->mlx);
}
