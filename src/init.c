#include "../includes/Cube3D.h"

void init_raycast(t_raycasting *raycast)
{
	raycast->deltadistY = 0;
	raycast->deltadistX = 0;
	raycast->sidedistX = 0;
	raycast->sidedistY = 0;
	raycast->stepX = 0;
	raycast->stepY = 0;
	raycast->cameraX = 0;
	raycast->raydirX = 0;
	raycast->raydirY = 0;
	raycast->mapX = 0;
	raycast->mapY = 0;
}

void init_player(t_player *player)
{
	player->posX = 0;
	player->posY = 0;
	player->dirX = 0;
	player->dirY = 0;
	player->planeX = 0;
	player->planeY = 0.66;

}

void init_data(t_player *player, t_raycasting *raycast)
{
	init_player(player);
	init_raycast(raycast);
}

