
typedef struct s_raycasting
{
	double deltadistX; // distance the ray must travel to move from one side of a map square the the next X or Y direction
	double deltadistY;
	double sidedistX;
	double sidedistY;
	int stepX;
	int stepY;
	double cameraX; // represents X coordinate in camera space (-1 (left side) -> 1 (right side))
	double raydirX; // represents the direction of the current ray
	double raydirY;
	int mapX; // represents the current square in the map grid the ray is in
	int mapY;
}			t_raycasting;

typedef struct s_wall
{
	double dist;
	int height;
	int start;
	int end;
}				t_wall;

typedef struct s_player
{
	double posX; //player pos Y on map
	double posY; //player pos X on map
	char start_player_dir;
	double dirX; // direction vector X the player is facing
	double dirY; // direction vector Y the player is facing
	double planeX; // Represents the 2D camera plane (perpendicular to dir X)
	double planeY; // Adjusts the FOV (field of view) (commonly set on 0.66/66°)
}			t_player;
