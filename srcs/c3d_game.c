/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chugon <chugon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 12:08:13 by chugon            #+#    #+#             */
/*   Updated: 2025/04/10 09:27:42 by chugon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

#include "cub3d.h"

void	c3d_create(t_data *_data)
{
	_data->display.mlx = mlx_init();
	if (_data->display.mlx == NULL)
		c3d_exit(_data, C3D_EMLX, "failed to initialize mlx");
	_data->display.window = mlx_new_window(_data->display.mlx,
			C3D_WINDOW_WIDTH, C3D_WINDOW_HEIGHT, C3D_GAME_NAME);
	if (_data->display.window == NULL)
		c3d_exit(_data, C3D_EMLX, "failed to initialize window");
	if (c3d_load_textures(_data) != C3D_ENONE)
		c3d_exit(_data, C3D_ELOAD, NULL);
	c3d_create_image(_data, &(_data->screen),
		C3D_WINDOW_WIDTH, C3D_WINDOW_HEIGHT);
	c3d_create_minimap(_data);
	c3d_create_animation(_data);
	c3d_log(__func__, C3D_LOG_GAME, "initialized");
}

void	c3d_destroy(t_data *_data)
{
	c3d_destroy_animation(_data);
	c3d_destroy_minimap(_data);
	c3d_unload_textures(_data);
	if (_data->screen.data != NULL)
		mlx_destroy_image(_data->display.mlx, _data->screen.data);
	if (_data->display.mlx != NULL && _data->display.window != NULL)
		mlx_destroy_window(_data->display.mlx, _data->display.window);
	if (_data->display.mlx != NULL)
	{
		mlx_destroy_display(_data->display.mlx);
		free(_data->display.mlx);
	}
	c3d_strsclear(_data->map.data);
	c3d_log(__func__, C3D_LOG_GAME, "clean");
}

void	c3d_run(t_data *_data)
{
	void	*p_win;

	p_win = _data->display.window;
	mlx_hook(p_win, C3D_EVENT_CLOSE, C3D_MASK_CLOSE, &c3d_event_quit, _data);
	mlx_hook(p_win, C3D_EVENT_PRESS, C3D_MASK_PRESS, &c3d_event_key, _data);
	mlx_hook(p_win, C3D_EVENT_MOUSE, C3D_MASK_MOUSE, &c3d_event_mouse, _data);
	mlx_mouse_hook(p_win, &c3d_event_click, _data);
	mlx_loop_hook(_data->display.mlx, &c3d_update_window, _data);
	gettimeofday(&(_data->fps), NULL);
	_data->update = FT_TRUE;
	if (_data->error == C3D_ENONE)
		mlx_loop(_data->display.mlx);
}

void	c3d_exit(t_data *_data, t_error _error, const char *arg)
{
	c3d_seterror(&(_data->error), _error, arg);
	c3d_destroy(_data);
	exit(EXIT_FAILURE);
}
