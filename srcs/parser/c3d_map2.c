/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_map2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chugon <chugon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 16:36:32 by chugon            #+#    #+#             */
/*   Updated: 2025/04/07 16:43:30 by chugon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_types.h"
#include "c3d_error.h"

#define ERR_WALL "not surrounded by wall"

#define SURROUNDING_WALL 1
#define SURROUNDING_SAPCE 0
#define SURROUNDING_ERROR -1

static int	c3d_check_surrounding(char _c)
{
	if (_c == C3D_MAP_WALL)
		return (SURROUNDING_WALL);
	else if (_c == C3D_DIRECTION_NORTH
		|| _c == C3D_DIRECTION_SOUTH
		|| _c == C3D_DIRECTION_EAST
		|| _c == C3D_DIRECTION_WEST
		|| _c == C3D_MAP_SPACE)
		return (SURROUNDING_SAPCE);
	return (SURROUNDING_ERROR);
}

t_error	c3d_wall_horizontal(t_data *_data, int _w, int _h)
{
	int	i_col;
	int	v_count;

	v_count = 0;
	i_col = _w;
	while (--i_col >= 0)
	{
		v_count += c3d_check_surrounding(_data->map.data[_h][i_col]);
		if (v_count != SURROUNDING_SAPCE)
			break ;
	}
	i_col = _w;
	while (++i_col < _data->map.width)
	{
		v_count += c3d_check_surrounding(_data->map.data[_h][i_col]);
		if (v_count != SURROUNDING_WALL)
			break ;
	}
	if (v_count != SURROUNDING_WALL * 2)
		c3d_seterror(&(_data->error), C3D_EMAP, ERR_WALL);
	return (_data->error);
}

t_error	c3d_wall_vertical(t_data *_data, int _w, int _h)
{
	int	i_row;
	int	v_count;

	v_count = 0;
	i_row = _h;
	while (--i_row >= 0)
	{
		v_count += c3d_check_surrounding(_data->map.data[i_row][_w]);
		if (v_count != SURROUNDING_SAPCE)
			break ;
	}
	i_row = _h;
	while (++i_row < _data->map.height)
	{
		v_count += c3d_check_surrounding(_data->map.data[i_row][_w]);
		if (v_count != SURROUNDING_WALL)
			break ;
	}
	if (v_count != SURROUNDING_WALL * 2)
		c3d_seterror(&(_data->error), C3D_EMAP, ERR_WALL);
	return (_data->error);
}
