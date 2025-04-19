/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chugon <chugon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 12:07:08 by chugon            #+#    #+#             */
/*   Updated: 2025/04/12 19:29:03 by chugon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

#include "c3d_event.h"
#include "c3d_log.h"

#define C3D_MOUSE_THRESHOLD 3

int	c3d_event_quit(t_data *_data)
{
	c3d_log(__func__, C3D_LOG_EVENT, "quit");
	mlx_loop_end(_data->display.mlx);
	return (EXIT_SUCCESS);
}

int	c3d_event_key(int key, t_data *_data)
{
	if (key == C3D_KEY_QUIT)
		c3d_event_quit(_data);
	else if (key == C3D_KEY_MOVE_UP)
		c3d_move_up(_data);
	else if (key == C3D_KEY_MOVE_DOWN)
		c3d_move_down(_data);
	else if (key == C3D_KEY_MOVE_LEFT)
		c3d_move_left(_data);
	else if (key == C3D_KEY_MOVE_RIGHT)
		c3d_move_right(_data);
	else if (key == C3D_KEY_ROTATE_LEFT)
		c3d_rotate(_data, C3D_DIRECTION_WEST);
	else if (key == C3D_KEY_ROTATE_RIGHT)
		c3d_rotate(_data, C3D_DIRECTION_EAST);
	return (EXIT_SUCCESS);
}

int	c3d_event_mouse(int _x, int _y, t_data *_data)
{
	static int	v_pos = C3D_WINDOW_WIDTH / 2;

	c3d_log(__func__, C3D_LOG_EVENT, "mouse: %d, %d", _x, _y);
	if (_x < v_pos - C3D_MOUSE_THRESHOLD)
	{
		c3d_rotate(_data, C3D_DIRECTION_WEST);
		v_pos = _x;
	}
	else if (_x > v_pos + C3D_MOUSE_THRESHOLD)
	{
		c3d_rotate(_data, C3D_DIRECTION_EAST);
		v_pos = _x;
	}
	return (EXIT_SUCCESS);
}

int	c3d_event_click(int _btn, int _x, int _y, t_data *_data)
{
	(void)_btn;
	_data->animation.x = _x - _data->animation.frames[0].width / 2;
	_data->animation.y = _y - _data->animation.frames[0].height / 2;
	_data->animation.show = FT_TRUE;
	_data->animation.index = 0;
	_data->update = FT_TRUE;
	c3d_log(__func__, C3D_LOG_EVENT, "click: (%d, %d)", _x, _y);
	return (EXIT_SUCCESS);
}
