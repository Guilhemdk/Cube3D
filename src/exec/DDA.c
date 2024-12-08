#include "../../includes/Cube3D.h"

// static char get_color(t_data *data, int wall_flag)
// {
// 	data->rc.angle = norm_angle(data->rc.angle);
// 	if (wall_flag == 0)
// 	{
// 		if (data->rc.angle > PI / 2 && data->rc.angle < 3 * PI / 2)
// 			return ('W'); //TODO
// 		else
// 			return ('E'); //TODO
// 	}
// 	else
// 	{
// 		if (data->rc.angle > 0 && data->rc.angle < PI)
// 			return ('S'); //TODO
// 		else
// 			return ('N'); //TODO
// 	}
// 	return ('I');
// }

// static void draw_wall(t_data *data, int ray, double top_pix, double bot_pix)
// {
// 	char orientation;

// 	orientation = get_color(data, data->rc.wall_flag); //TODO
// 	//if (orientation == 'I')
// 		//error(data);
// 	while(top_pix < bot_pix)
// 		gen_wall(orientation); //TODO
// }

// static void draw_floor_ceiling(t_data *data, int ray, int top_pix, int bot_pix)
// {
// 	int i;

// 	i = bot_pix;
// 	while(i < SCREEN_HEIGHT)
// 		gen_floor(); //TODO
// 	i = 0;
// 	while(i < top_pix)
// 		gen_ceiling(); //TODO
// }

void DDA(t_data *data, int ray)
{
	double wall_height;
	double bot_pix;
	double top_pix;

	data->rc.distance *= cos(norm_angle(data->rc.angle - data->player.angle));
	wall_height = (TILE_SIZE / data->rc.distance) * ((SCREEN_WIDTH / 2) / tan(data->player.fov / 2));
	bot_pix = (SCREEN_HEIGHT / 2) + (wall_height / 2);
	top_pix = (SCREEN_HEIGHT / 2) - (wall_height / 2);
	if (bot_pix > SCREEN_HEIGHT)
		bot_pix = SCREEN_HEIGHT;
	if (top_pix < 0)
		top_pix = 0;
	ray = 0;
	top_pix = ray;
	// draw_wall(data, ray, top_pix, bot_pix);
	// draw_floor_ceiling(data, ray, top_pix, bot_pix);
}
