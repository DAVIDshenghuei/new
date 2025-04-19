/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chugon <chugon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 12:06:43 by chugon            #+#    #+#             */
/*   Updated: 2025/04/09 15:27:25 by chugon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_types.h"
#include "c3d_log.h"
#include "c3d_utils.h"

#define C3D_ANGULAR 0.025
#define C3D_VELOCITY 0.06

void	c3d_setposition(t_data *data, double x, double y);

void	c3d_move_up(t_data *_data)
{
	double	v_x;
	double	v_y;

	v_x = _data->player.position.x + cos(_data->player.angle) * C3D_VELOCITY;
	v_y = _data->player.position.y + sin(_data->player.angle) * C3D_VELOCITY;
	c3d_setposition(_data, v_x, v_y);
}

void	c3d_move_down(t_data *_data)
{
	double	v_x;
	double	v_y;

	v_x = _data->player.position.x - cos(_data->player.angle) * C3D_VELOCITY;
	v_y = _data->player.position.y - sin(_data->player.angle) * C3D_VELOCITY;
	c3d_setposition(_data, v_x, v_y);
}

void	c3d_move_right(t_data *_data)
{
	double	v_x;
	double	v_y;

	v_x = _data->player.position.x - sin(_data->player.angle) * C3D_VELOCITY;
	v_y = _data->player.position.y + cos(_data->player.angle) * C3D_VELOCITY;
	c3d_setposition(_data, v_x, v_y);
}

void	c3d_move_left(t_data *_data)
{
	double	v_x;
	double	v_y;

	v_x = _data->player.position.x + sin(_data->player.angle) * C3D_VELOCITY;
	v_y = _data->player.position.y - cos(_data->player.angle) * C3D_VELOCITY;
	c3d_setposition(_data, v_x, v_y);
}

void	c3d_rotate(t_data *_data, t_direction _dir)
{
	if (_dir == C3D_DIRECTION_EAST)
		_data->player.angle += M_PI * C3D_ANGULAR;
	else if (_dir == C3D_DIRECTION_WEST)
		_data->player.angle -= M_PI * C3D_ANGULAR;
	if (_data->player.angle > M_PI)
		_data->player.angle = _data->player.angle - M_PI - M_PI;
	if (_data->player.angle <= -M_PI)
		_data->player.angle = _data->player.angle + M_PI + M_PI;
	_data->ray.dir.x = cos(_data->player.angle);
	_data->ray.dir.y = sin(_data->player.angle);
	_data->ray.plane.x = cos(_data->player.angle + M_PI_2);
	_data->ray.plane.y = sin(_data->player.angle + M_PI_2);
	_data->update = FT_TRUE;
	c3d_log(__func__, C3D_LOG_EVENT, "angle: %lf",
		_data->player.angle * 180.0 / M_PI);
}
