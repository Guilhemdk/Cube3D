#include "../includes/Cube3D.h"

static void calculateRayDirection(int x, t_raycasting *raycast, t_player *player)
{
	raycast->cameraX = 2 * x / (double)SCREEN_WIDTH - 1;
	raycast->raydirX = player->dirX + player->planeX * raycast->cameraX;
	raycast->raydirY = player->dirY + player->planeY * raycast->cameraX;
}

static void get_step_and_side(t_raycasting *raycast, t_player *player)
{
	if (raycast->raydirX < 0)
	{
		raycast->stepX = -1;
		raycast->sidedistX = (player->posX - raycast->mapX) * raycast->deltadistX;
	}
	else
	{
		raycast->stepX = 1;
		raycast->sidedistX = (raycast->mapX + 1 - player->posX) * raycast->deltadistX;
	}
	if (raycast->raydirY < 0)
	{
		raycast->stepY = -1;
		raycast->sidedistY = (player->posY - raycast->mapY) * raycast->deltadistY;
	}
	else
	{
		raycast->stepY = 1;
		raycast->sidedistY = (raycast->mapY + 1 - player->posY) * raycast->deltadistY;
	}
}

static void set_calc_variables(t_raycasting *raycast, t_player *player)
{
	if (raycast->raydirX == 0)
		raycast->deltadistX = INT_MAX;
	else
		raycast->deltadistX = fabs(1 / raycast->raydirX);
	if (raycast->raydirY == 0)
		raycast->deltadistY = INT_MAX;
	else
		raycast->deltadistY = fabs(1 / raycast->raydirY);
	get_step_and_side(raycast, player);
}

void raycasting(t_player *player)
{
	int x;
	t_raycasting raycast;

	x = 0;
	// loop for each X column on the screen
	while (x < SCREEN_WIDTH)
	{
		calculateRayDirection(x, &raycast, player);
		raycast.mapX = (int)player->posX;
		raycast.mapY = (int)player->posY;
		set_calc_variables(&raycast, player);
		performDDA(x, &raycast, player);
	}
}
