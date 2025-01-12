#include "../../../includes/Cube3D.h"

static int get_color(t_data *data, int wall_flag)
{
	data->rc.angle = norm_angle(data->rc.angle);
	if (wall_flag == 0)
	{
		if (data->rc.angle > PI / 2 && data->rc.angle < 3 * (PI / 2))
            return (0x00FF00FF); //W
		else
			return (0xFFFF00FF); //E
	}
	else
	{
		if (data->rc.angle > 0 && data->rc.angle < PI)
			return (0xFF0000FF); //S
		else
			return (0x0000FFFF); //N
	}
	return (0);
}

static void draw_wall(t_data *data, int ray, int top_pix, double bot_pix)
{
	int color;

	color = get_color(data, data->rc.wall_flag); //TODO
	//if (orientation == 'I')
		//error(data);
	while(top_pix < bot_pix)
		put_pixel(&data->w.img, ray, top_pix++, color);
}

static void draw_floor_ceiling(t_data *data, int ray, int top_pix, int bot_pix)
{
	int i;

	i = bot_pix;
	while(i < SCREEN_HEIGHT)
		put_pixel(&data->w.img, ray, i++, 0xFFFFFFFF); //floor
	i = 0;
	while(i < top_pix)
		put_pixel(&data->w.img, ray, i++, 0xFFFFFFFF); //ceiling
}

void DDa(t_data *data, int ray)
{
	double wall_height;
	double bot_pix;
	double top_pix;

	data->rc.distance *= cos(norm_angle(data->rc.angle - data->player.angle));
	wall_height = (TILE_SIZE / data->rc.distance) * (((double)SCREEN_WIDTH / 2) / tan(data->player.fov / 2));
	bot_pix = ((double)SCREEN_HEIGHT / 2) + (wall_height / 2);
	top_pix = ((double)SCREEN_HEIGHT / 2) - (wall_height / 2);
	if (bot_pix > SCREEN_HEIGHT)
		bot_pix = SCREEN_HEIGHT;
	if (top_pix < 0)
		top_pix = 0;
	draw_wall(data, ray, top_pix, bot_pix);
	draw_floor_ceiling(data, ray, top_pix, bot_pix);
}
