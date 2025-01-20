#include "../../../includes/Cube3D.h"

static int get_color(t_data *data, int wall_flag, int tex_x, int tex_y)
{
	data->rc.angle = norm_angle(data->rc.angle);

	if (wall_flag == 0)
	{
		if (data->rc.angle > PI / 2 && data->rc.angle < 3 * (PI / 2))
			return (get_pixel_color(&data->w.tex_we, tex_x, tex_y)); // West
		else
			return (get_pixel_color(&data->w.tex_ea, tex_x, tex_y)); // East
	}
	else
	{
		if (data->rc.angle > 0 && data->rc.angle < PI)
		{
			// printf("SO\n");
			return (get_pixel_color(&data->w.tex_so, tex_x, tex_y)); // South
		}
		else
		{
			// printf("NO\n");
			return (get_pixel_color(&data->w.tex_no, tex_x, tex_y)); // North
		}
	}
	return (0);
}

static void draw_wall(t_data *data, int ray, double wall_height, double top_pix, double bot_pix)
{
	int color;
	int	tex_x;
	int	tex_y;
	int r = data->w.tex_ea.width / TILE_SIZE;

	printf("r: %d\n", r);
	// int	flag = 0;
	if (data->rc.wall_flag == 0)
		data->rc.wall_hit = data->rc.wall_hit_y - floor(data->rc.wall_hit_y / TILE_SIZE) * TILE_SIZE;
	else
		data->rc.wall_hit = data->rc.wall_hit_x - floor(data->rc.wall_hit_x / TILE_SIZE) * TILE_SIZE;
	tex_x = (int)(data->rc.wall_hit * r);
	// tex_x = tex_x % (data->w.tex_so.width);
	// tex_x = tex_x % data->w.tex_so.width;
	printf("tex: %d\n", tex_x);
	// if (tex_x < 0)
	// 	tex_x = 0;
	// if (tex_x >= (data->w.tex_so.width))
	// 	tex_x = (data->w.tex_so.width) - 1;

	while(top_pix < bot_pix - 3)
	{
		if (data->rc.wall_flag == 0) {  // Est/Ouest
			tex_y = (int)((top_pix - ((double)SCREEN_HEIGHT / 2 - wall_height / 2)) / wall_height * data->w.tex_ea.height);
		} else {  // Nord/Sud
			tex_y = (int)((top_pix - ((double)SCREEN_HEIGHT / 2 - wall_height / 2)) / wall_height * data->w.tex_no.height);
		}
		if (tex_y < 0)
			tex_y = 0;
		if (tex_y >= data->w.tex_no.height)
			tex_y = data->w.tex_no.height - 1;
		// printf("ray: %d, tex_x: %d, tex_y: %d\n", ray, tex_x, tex_y);
		color = get_color(data, data->rc.wall_flag, tex_x, tex_y);
		put_pixel(&data->w.img, ray, top_pix++, color);
	}
}

static void draw_floor_ceiling(t_data *data, int ray, int top_pix, int bot_pix)
{
	int i;

	i = bot_pix;
	while(i < SCREEN_HEIGHT)
		put_pixel(&data->w.img, ray, i++, data->m.hex_f);
	i = 0;
	while(i < top_pix)
		put_pixel(&data->w.img, ray, i++, data->m.hex_c);
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
	draw_wall(data, ray, wall_height, top_pix, bot_pix);
	draw_floor_ceiling(data, ray, top_pix, bot_pix);
}
