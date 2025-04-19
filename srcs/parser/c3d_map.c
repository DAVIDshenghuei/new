/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chugon <chugon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 12:07:27 by chugon            #+#    #+#             */
/*   Updated: 2025/04/09 15:36:05 by chugon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "c3d_parse.h"
#include "c3d_utils.h"
#include "c3d_error.h"

#define C3D_MAP_FORMAT " 01NSWE\n"
#define ERR_WALL "not surrounded by wall"
#define ERR_POS "multiple starting positions"
#define ERR_MISS "no starting position"
#define ERR_SMALL "missing elements"

t_error	c3d_wall_horizontal(t_data *data, int w, int h);
t_error	c3d_wall_vertical(t_data *data, int w, int h);

static void	c3d_map_copy_line(char *_dst, const char *_src, int _width)
{
	int	i_w;

	ft_memset(_dst, C3D_MAP_EMPTY, _width);
	i_w = -1;
	while (++i_w < _width)
	{
		if (_src[i_w] == '\0')
			break ;
		else if (_src[i_w] == '\n' || _src[i_w] == ' ')
			_dst[i_w] = C3D_MAP_EMPTY;
		else
			_dst[i_w] = _src[i_w];
	}
}

t_error	c3d_map_position(t_data *_data, char _c, int _w, int _h)
{
	if (_c == 'N' || _c == 'S' || _c == 'W' || _c == 'E')
	{
		if (_data->player.set == FT_TRUE)
			return (c3d_seterror(&(_data->error), C3D_EMAP, ERR_POS));
		if (_c == C3D_DIRECTION_NORTH)
			_data->player.angle = -M_PI_2;
		else if (_c == C3D_DIRECTION_SOUTH)
			_data->player.angle = M_PI_2;
		else if (_c == C3D_DIRECTION_EAST)
			_data->player.angle = M_PI;
		else if (_c == C3D_DIRECTION_WEST)
			_data->player.angle = 0.0;
		_data->map.data[_h][_w] = C3D_MAP_SPACE;
		_data->player.position.x = (double)_w + 0.5;
		_data->player.position.y = (double)_h + 0.5;
		_data->player.set = FT_TRUE;
		_data->ray.dir.x = cos(_data->player.angle);
		_data->ray.dir.y = sin(_data->player.angle);
		_data->ray.plane.x = cos(_data->player.angle + M_PI_2);
		_data->ray.plane.y = sin(_data->player.angle + M_PI_2);
	}
	return (_data->error);
}

t_error	c3d_map_check(t_data *_data)
{
	const t_map	*p_map = &(_data->map);
	int			i_h;
	int			i_w;

	i_h = -1;
	while (++i_h < p_map->height)
	{
		i_w = -1;
		while (++i_w < p_map->width)
		{
			if (c3d_map_position(_data, p_map->data[i_h][i_w], i_w, i_h) != 0)
				return (_data->error);
			if (p_map->data[i_h][i_w] == C3D_MAP_SPACE)
			{
				if (c3d_wall_horizontal(_data, i_w, i_h) != C3D_ENONE
					|| c3d_wall_vertical(_data, i_w, i_h) != C3D_ENONE)
					return (_data->error);
			}
		}
	}
	if (_data->player.set == FT_FALSE)
		c3d_seterror(&(_data->error), C3D_EMAP, ERR_MISS);
	return (_data->error);
}

t_error	c3d_map_data(t_data *_data)
{
	char	**s_map;
	int		i_h;

	if (_data->map.width < 3 || _data->map.height < 3)
		return (c3d_seterror(&(_data->error), C3D_EMAP, ERR_SMALL));
	s_map = (char **)malloc((_data->map.height + 1) * sizeof(char *));
	if (s_map == NULL)
		return (c3d_seterror(&(_data->error), C3D_ESYSTEM, NULL));
	i_h = -1;
	while (_data->map.data[++i_h] != NULL)
	{
		s_map[i_h] = (char *)malloc(_data->map.width * sizeof(char));
		if (s_map[i_h] == NULL)
		{
			c3d_strsclear(s_map);
			return (c3d_seterror(&(_data->error), C3D_ESYSTEM, NULL));
		}
		c3d_map_copy_line(s_map[i_h], _data->map.data[i_h], _data->map.width);
	}
	c3d_strsclear(_data->map.data);
	s_map[_data->map.height] = NULL;
	_data->map.data = s_map;
	return (c3d_map_check(_data));
}

t_error	c3d_parse_map(t_data *_data, const char *_line)
{
	int	i_map;
	int	v_width;

	if (*_line == '\n')
		return (C3D_ENONE);
	i_map = -1;
	while (_line[++i_map] != '\0')
	{
		if (ft_strchr(C3D_MAP_FORMAT, _line[i_map]) == NULL)
			return (c3d_seterror(&(_data->error), C3D_EFORMAT, _line));
	}
	v_width = ft_strlen(_line);
	if (_line[v_width - 1] == '\n')
		--v_width;
	if (v_width > _data->map.width)
		_data->map.width = v_width;
	++(_data->map.height);
	_data->map.data = c3d_strscat(_data->map.data, ft_strdup(_line));
	return (C3D_ENONE);
}
