/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_position.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chugon <chugon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 12:07:17 by chugon            #+#    #+#             */
/*   Updated: 2025/04/12 14:54:46 by chugon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_types.h"
#include "c3d_log.h"

#define C3D_POSITION_THRESHOLD 0.01

static t_bool	c3d_isavailable(t_map *_map, double _x, double _y)
{
	const int	v_col[] = {
		(int)(_x - C3D_POSITION_THRESHOLD),
		(int)(_x + C3D_POSITION_THRESHOLD),
		(int)(_x)
	};
	const int	v_row[] = {
		(int)(_y - C3D_POSITION_THRESHOLD),
		(int)(_y + C3D_POSITION_THRESHOLD),
		(int)(_y)
	};
	int			i_col;
	int			i_row;

	i_row = -1;
	while (++i_row < 3)
	{
		i_col = -1;
		while (++i_col < 3)
		{
			if (_map->data[v_row[i_row]][v_col[i_col]] != C3D_MAP_SPACE)
				return (FT_FALSE);
		}
	}
	return (FT_TRUE);
}

void	c3d_setposition(t_data *_data, double _x, double _y)
{
	if (c3d_isavailable(&(_data->map), _x, _y) == FT_FALSE)
		return ;
	_data->player.position.x = _x;
	_data->player.position.y = _y;
	c3d_log(__func__, C3D_LOG_EVENT, "%lf, %lf", _x, _y);
	_data->update = FT_TRUE;
}
