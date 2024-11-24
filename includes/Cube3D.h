#ifndef CUBE3D_H
#define CUBE3D_H

#include <unistd.h>
#include <stdio.h>
#include <math.h>
#include <limits.h>
#include "structs.h"
#include "macros.h"


void raycasting(t_player *player);
void performDDA(int x, t_raycasting *raycast, t_player *player);
void putPixelToBuffer(int x, int y, int color);
int getWallColor();

#endif
