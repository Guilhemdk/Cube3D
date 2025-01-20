/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pitroin <pitroin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 20:36:53 by pitroin           #+#    #+#             */
/*   Updated: 2025/01/20 16:45:42 by pitroin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cube3D.h"

void	*safe_malloc(size_t bytes, t_data *data)
{
	void	*res;

	res = malloc(bytes);
	if (res == NULL)
		error(data, MALLOC_ERR);
	return (res);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != 0 && s2[i] != 0)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	set_tab(t_data *data)
{
	int	h;
	int	w;
	int	i;

	data->m.map = safe_malloc((sizeof(char *) * data->m.height), data);
	h = -1;
	i = 0;
	while (++h < data->m.height)
	{
		data->m.map[h] = safe_malloc(data->m.width, data);
		w = -1;
		while (data->m.file_map[i] && data->m.file_map[i++] != '\n')
			data->m.map[h][++w] = data->m.file_map[i];
	}
}
