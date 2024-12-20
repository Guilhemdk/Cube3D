#include "../../includes/Cube3D.h"

static int is_key(int key)
{
	//return (key == xxx || key == xxx | key == xxx) //TODO
	return (0);
}

static void handle_key(int key, t_data *data)
{
	//Ici, on genere les evenements/ aplliques les maths sur les variables joueur pour reorrienter la cam/deplacer le joueur
}

int generate_event(int key, t_data *data)
{
	t_win *w;

	w = &data->w;
	if (is_key(key))
	{
		mlx_clear_window(w->mlx, w->win);
		handle_key(key, w);
		calc_rays(data);
	}
	return (0);
}
