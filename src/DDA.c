#include "../includes/Cube3D.h"

static double calculateWallDist(int side, t_raycasting *raycast, t_player *player)
{
	double perpWallDist;
	if (side == 0)
		perpWallDist = ((float)raycast->mapX - player->posX + (1 - (float)raycast->stepX) / 2) / raycast->raydirX;
	else
		perpWallDist = ((float)raycast->mapY - player->posY + (1 - (float)raycast->stepY) / 2) / raycast->raydirY;
	return (perpWallDist);
}

static void calculateWallHeight(t_wall *wall)
{
	wall->height = (int)(SCREEN_HEIGHT / wall->dist);
	wall->start = -wall->height / 2 + SCREEN_HEIGHT / 2;
	if (wall->start < 0)
		wall->start = 0
	wall->end = wall->height / 2 + SCREEN_HEIGHT / 2;
	if (wall->end >= SCREEN_HEIGHT)
		wall->end = SCREEN_HEIGHT - 1;
}

//genere des ombres (a verifier)
static void drawVline(int x, int side, t_wall *wall)
{
	int color;
	int y;

	y = 0;
	color = getWallColor(); //TODO
	if (side == 1)
		color = (color >> 1) & 0x7F7F7F;
	while(y++ < wall->end)
		putPixelToBuffer(x, y, color);
}

static void gen_wall(int x, int side, t_raycasting *raycast, t_player *player)
{
	t_wall wall;

	wall.dist = calculateWallDist(side, raycast, player);
	calculateWallHeight(&wall);
	drawVline(x, side, &wall);
}

void performDDA(int x, t_raycasting *raycast, t_player *player)
{
	int hit;
	int side;

	hit = 0;
	side = 0;
	while(hit == 0)
	{
		if (raycast->sidedistX < raycast->sidedistY)
		{
			raycast->sidedistX += raycast->deltadistX;
			raycast->mapX += raycast->stepX;
			side = 0;
		}
		else
		{
			raycast->sidedistY += raycast->deltadistY;
			raycast->mapY += raycast->stepY;
			side = 1;
		}
		if (map[raycast->mapX][raycast->mapY] > 0)
			hit = 1;
	}
	gen_wall(x, side, raycast, player);
}
