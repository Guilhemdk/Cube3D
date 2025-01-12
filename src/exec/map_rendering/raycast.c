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
	float h_x;
	float h_y;
	float x_step;
	float y_step;
	int  pixel;

	y_step = TILE_SIZE;
	x_step = TILE_SIZE / tan(angl);
	h_y = floor(data->player.posY / (float)TILE_SIZE) * TILE_SIZE;
	pixel = inter_check(angl, &h_y, &y_step, 1);
	h_x = data->player.posX + (h_y - data->player.posY) / tan(angl);
	if ((ray_orientation(angl, 'y') && x_step > 0) || (!ray_orientation(angl, 'y') && x_step < 0)) // check x_step value
		x_step *= -1;
	while (!wall_hit(h_x, h_y - pixel, data)) // check the wall hit whit the pixel value
	{
		h_x += x_step;
		h_y += y_step;
	}
	return (sqrt(pow(h_x - data->player.posX, 2) + pow(h_y - data->player.posY, 2)));
}

static float get_next_v_wall(t_data *data, float angl)
{
float v_x;
	float v_y;
	float x_step;
	float y_step;
	int  pixel;

	x_step = TILE_SIZE; 
	y_step = TILE_SIZE * tan(angl);
	v_x = floor(data->player.posX / (float)TILE_SIZE) * TILE_SIZE;
	pixel = inter_check(angl, &v_x, &x_step, 0); // check the intersection and get the pixel value
	v_y = data->player.posY + (v_x - data->player.posX) * tan(angl);
	if ((ray_orientation(angl, 'x') && y_step < 0) || (!ray_orientation(angl, 'x') && y_step > 0)) // check y_step value
		y_step *= -1;
	while (!wall_hit(v_x - pixel, v_y, data)) // check the wall hit whit the pixel value
	{
		v_x += x_step;
		v_y += y_step;
	}
	return (sqrt(pow(v_x - data->player.posX, 2) + pow(v_y - data->player.posY, 2))); // get the distance
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
}

