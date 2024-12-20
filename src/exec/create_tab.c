#include "../../includes/Cube3D.h"


void set_tab(t_data *data)
{
	int h;
	int w;
	int i;

	data->m.map = safe_malloc((sizeof(char *) * data->m.height), data);
	h = -1;
	i = 0;
	while(++h < data->m.height)
	{
		data->m.map[h] = safe_malloc(data->m.width, data);
		w = -1;
		while(data->m.file_map[i] && data->m.file_map[i++] != '\n')
			data->m.map[h][++w] = data->m.file_map[i];
	}
}
