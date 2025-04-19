/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_raycasting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chugon <chugon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 15:33:25 by chugon            #+#    #+#             */
/*   Updated: 2025/04/12 14:12:39 by chugon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>

#include "c3d_types.h"
#include "c3d_display.h"
#include "c3d_log.h"

static void	c3d_initialize_raycasting(t_ray *_ray, t_player *_player, int _x)
{
	_ray->camera.x = 2.0 * _x / (double)C3D_WINDOW_WIDTH - 1;
	_ray->ray_dir.x = _ray->dir.x + _ray->plane.x * _ray->camera.x;
	_ray->ray_dir.y = _ray->dir.y + _ray->plane.y * _ray->camera.x;
	_ray->map.x = (int)_player->position.x;
	_ray->map.y = (int)_player->position.y;
	if (_ray->ray_dir.x == 0)
		_ray->delta.x = 1.0e30;
	else
		_ray->delta.x = fabs(1 / _ray->ray_dir.x);
	if (_ray->ray_dir.y == 0)
		_ray->delta.y = 1.0e30;
	else
		_ray->delta.y = fabs(1 / _ray->ray_dir.y);
}

static void	c3d_initialize_dda(t_ray *_ray, t_player *_player)
{
	if (_ray->ray_dir.x < 0)
	{
		_ray->step.x = -1;
		_ray->side.x = (_player->position.x - _ray->map.x) * _ray->delta.x;
	}
	else
	{
		_ray->step.x = 1;
		_ray->side.x = (_ray->map.x + 1 - _player->position.x) * _ray->delta.x;
	}
	if (_ray->ray_dir.y < 0)
	{
		_ray->step.y = -1;
		_ray->side.y = (_player->position.y - _ray->map.y) * _ray->delta.y;
	}
	else
	{
		_ray->step.y = 1;
		_ray->side.y = (_ray->map.y + 1 - _player->position.y) * _ray->delta.y;
	}
}

static void	c3d_perform_dda(t_ray *_ray, t_map *_map)
{
	t_bool	hit;

	hit = FT_FALSE;
	while (hit == FT_FALSE)
	{
		if (_ray->side.x < _ray->side.y)
		{
			_ray->side.x += _ray->delta.x;
			_ray->map.x += _ray->step.x;
			_ray->surface = 0;
		}
		else
		{
			_ray->side.y += _ray->delta.y;
			_ray->map.y += _ray->step.y;
			_ray->surface = 1;
		}
		if (_ray->map.x < 0 || _ray->map.x >= _map->width
			|| _ray->map.y < 0 || _ray->map.y >= _map->height)
			break ;
		else if (_map->data[_ray->map.y][_ray->map.x] != C3D_MAP_SPACE)
			hit = FT_TRUE;
	}
}

static void	c3d_calculate_camera_projection(t_ray *_ray, t_player *_player)
{
	if (_ray->surface == 0)
		_ray->wall_dist = _ray->side.x - _ray->delta.x;
	else
		_ray->wall_dist = _ray->side.y - _ray->delta.y;
	_ray->line_height = (int)(C3D_WINDOW_HEIGHT / _ray->wall_dist);
	_ray->draw_start = -_ray->line_height / 2 + C3D_WINDOW_HEIGHT / 2;
	if (_ray->draw_start < 0)
		_ray->draw_start = 0;
	_ray->draw_end = _ray->line_height / 2 + C3D_WINDOW_HEIGHT / 2;
	if (_ray->draw_end >= C3D_WINDOW_HEIGHT)
		_ray->draw_end = C3D_WINDOW_HEIGHT;
	if (_ray->surface == 0)
		_ray->wallx = _player->position.y + _ray->wall_dist * _ray->ray_dir.y;
	else
		_ray->wallx = _player->position.x + _ray->wall_dist * _ray->ray_dir.x;
	_ray->wallx -= floor(_ray->wallx);
}

void	c3d_raycasting(t_data *_data)
{
	t_ray	v_ray;
	int		x;

	v_ray = _data->ray;
	x = -1;
	while (++x < C3D_WINDOW_WIDTH)
	{
		c3d_initialize_raycasting(&v_ray, &(_data->player), x);
		c3d_initialize_dda(&v_ray, &(_data->player));
		c3d_perform_dda(&v_ray, &(_data->map));
		c3d_calculate_camera_projection(&v_ray, &(_data->player));
		c3d_render_texture(_data, &(v_ray), x);
	}
}
