/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pitroin <pitroin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:52:22 by pitroin           #+#    #+#             */
/*   Updated: 2024/11/18 21:13:25 by pitroin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include "../libft/libft.h"
# include "../gnl/get_next_line.h"

typedef struct s_map
{
	char	*file_map;
	char	*file_NO;
	char	*file_SO;
	char	*file_WE;
	char	*file_EA;
	int		color_f;
	int		color_c;
}	t_map;


//init map
int		init_map(t_map *map, char *file);
int		init_info_map(t_map *map);

//utils
int		ft_strcmp(const char *s1, const char *s2);

//free
void	free_map(t_map *map);

#endif