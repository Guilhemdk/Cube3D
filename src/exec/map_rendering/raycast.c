#include "../../../includes/Cube3D.h"

float norm_angle(float angle)
{
	if (angle < 0)
		angle += (2 * PI);
	else if (angle > (2 * PI))
		angle -= 2 * PI;
	return (angle);
}

int inter_check(float angle, float *inter, float *step, int is_horizon)
{
	if (is_horizon)
	{
		if (angle > 0 && angle < PI)
		{
			*inter += TILE_SIZE;
			return (-1);
		}
		*step *= -1;
	}
	else
	{
		if (!(angle > PI / 2 && angle < 3 * PI / 2))
		{
			*inter += TILE_SIZE;
			return (-1);
		}
		*step *= -1;
	}
	return (1);
}

int ray_orientation(float angle, char c)
{
	if (c == 'x')
	{
		if (angle > 0 && angle < PI)
        {
            // printf("looking this way\n");
			return (1); //looking at the upper half of the circle
        }
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

static float get_next_h_wall(t_data *data, float angl)
{
	float x_step;
	float y_step;
	int  pixel;

	y_step = TILE_SIZE;
	x_step = TILE_SIZE / tan(angl);
	data->rc.h_hitY = floor(data->player.posY / (float)TILE_SIZE) * TILE_SIZE;
	pixel = inter_check(angl, &data->rc.h_hitY, &y_step, 1);
	data->rc.h_hitX = data->player.posX + (data->rc.h_hitY - data->player.posY) / tan(angl);
	if ((ray_orientation(angl, 'y') && x_step > 0) || (!ray_orientation(angl, 'y') && x_step < 0)) // check x_step value
		x_step *= -1;
	while (!wall_hit(data->rc.h_hitX, data->rc.h_hitY - pixel, data)) // check the wall hit whit the pixel value
	{
		data->rc.h_hitX += x_step;
		data->rc.h_hitY += y_step;
	}
	return (sqrt(pow(data->rc.h_hitX - data->player.posX, 2) + pow(data->rc.h_hitY - data->player.posY, 2)));
}

static float get_next_v_wall(t_data *data, float angl)
{
	float x_step;
	float y_step;
	int  pixel;

	x_step = TILE_SIZE;
	y_step = TILE_SIZE * tan(angl);
	data->rc.v_hitX = floor(data->player.posX / (float)TILE_SIZE) * TILE_SIZE;
	pixel = inter_check(angl, &data->rc.v_hitX, &x_step, 0); // check the intersection and get the pixel value
	data->rc.v_hitY = data->player.posY + (data->rc.v_hitX - data->player.posX) * tan(angl);
	if ((ray_orientation(angl, 'x') && y_step < 0) || (!ray_orientation(angl, 'x') && y_step > 0)) // check y_step value
		y_step *= -1;
	while (!wall_hit(data->rc.v_hitX - pixel, data->rc.v_hitY, data)) // check the wall hit whit the pixel value
	{
		data->rc.v_hitX += x_step;
		data->rc.v_hitY += y_step;
	}
	return (sqrt(pow(data->rc.v_hitX - data->player.posX, 2) + pow(data->rc.v_hitY - data->player.posY, 2))); // get the distance
}
void calc_rays(t_data *data)
{
	double closest_h_wall;
	double closest_v_wall;
	int ray;


	ray = 0;
    closest_h_wall = 0;
    closest_v_wall = 0;
    // printf("player s angle = %f\n", data->player.angle);
//	set_tab(data);
	data->rc.angle = data->player.angle - (data->player.fov / 2);
	while(ray < SCREEN_WIDTH)
	{
		data->rc.wall_flag = 0;
		closest_h_wall = get_next_h_wall(data, norm_angle(data->rc.angle));
		closest_v_wall = get_next_v_wall(data, norm_angle(data->rc.angle));
		if (closest_v_wall <= closest_h_wall)
		{
			data->rc.distance = closest_v_wall;
			data->rc.wall_hit_x = data->rc.v_hitX;
			data->rc.wall_hit_y = data->rc.v_hitY;
		}
		else
		{
			data->rc.distance = closest_h_wall;
			data->rc.wall_flag = 1;
			data->rc.wall_hit_x = data->rc.h_hitX;
			data->rc.wall_hit_y = data->rc.h_hitY;
		}
		DDa(data, ray);
		ray++;
		// printf("ray %d\n", ray);
		data->rc.angle += (data->player.fov / SCREEN_WIDTH);
	}
}

