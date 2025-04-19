/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_debug.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chugon <chugon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 12:07:37 by chugon            #+#    #+#             */
/*   Updated: 2025/04/10 09:43:52 by chugon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "c3d_types.h"

#ifndef C3D_DEBUG_ENABLED

void	c3d_debug(t_data *_data)
{
	(void)_data;
}

#else

static void	c3d_debug_texture(t_texture *_tex, int _id)
{
	static const char	*ids[] = {
		"NORTH", "SOUTH", "WEST", "EAST", "FLOOR", "CEILING"
	};

	printf("Texture [%-7s]: ", ids[_id]);
	if (_id == C3D_TID_F || _id == C3D_TID_C)
		printf("%d,%d,%d\n",
			_tex->color.r & 0xFF,
			_tex->color.g & 0xFF,
			_tex->color.b & 0xFF);
	else
		printf("%s\n", _tex->filename);
}

static void	c3d_debug_map(t_map *_map)
{
	int	i_h;
	int	i_w;

	printf("Map: %d x %d\n", _map->width, _map->height);
	i_h = -1;
	while (++i_h < _map->height)
	{
		i_w = -1;
		while (++i_w < _map->width)
			printf("%c", _map->data[i_h][i_w]);
		printf("\n");
	}
}

void	c3d_debug(t_data *_data)
{
	int	index;

	index = -1;
	while (++index < C3D_TOTAL_COUNT)
		c3d_debug_texture(&(_data->texture[index]), index);
	c3d_debug_map(&(_data->map));
	printf("Position: (%lf, %lf)\n",
		_data->player.position.x,
		_data->player.position.y);
	printf("Direction: %lf\n", _data->player.angle);
}

#endif
