/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_minimap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chugon <chugon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 11:06:26 by chugon            #+#    #+#             */
/*   Updated: 2025/04/12 15:57:08 by chugon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include <mlx.h>

#include "c3d_display.h"

#define C3D_IMG_WIDTH 16
#define C3D_IMG_HEIGHT 16

#define C3D_COLOR_WALL 0x4C13AC
#define C3D_COLOR_EMPTY 0x212121
#define C3D_COLOR_PLAYER 0xD43838
#define C3D_COLOR_SPACE 0x777777

static char	c3d_getdata(t_map *_map, int _w, int _h)
{
	if (_w < 0 || _h < 0 || _w >= _map->width || _h >= _map->height)
		return (C3D_MAP_EMPTY);
	return (_map->data[_h][_w]);
}

void	c3d_create_minimap(t_data *_data)
{
	const t_color	v_color_wall = {.rgb = C3D_COLOR_WALL};
	const t_color	v_color_empty = {.rgb = C3D_COLOR_EMPTY};
	const t_color	v_color_player = {.rgb = C3D_COLOR_PLAYER};
	const t_color	v_color_space = {.rgb = C3D_COLOR_SPACE};
	t_minimap		*p_map;

	p_map = &(_data->minimap);
	c3d_create_image(_data, &(p_map->wall), C3D_IMG_WIDTH, C3D_IMG_HEIGHT);
	c3d_create_image(_data, &(p_map->player), C3D_IMG_WIDTH, C3D_IMG_HEIGHT);
	c3d_create_image(_data, &(p_map->space), C3D_IMG_WIDTH, C3D_IMG_HEIGHT);
	c3d_create_image(_data, &(p_map->empty), C3D_IMG_WIDTH, C3D_IMG_HEIGHT);
	c3d_setcolor(&(p_map->wall), v_color_wall);
	c3d_setcolor(&(p_map->player), v_color_player);
	c3d_setcolor(&(p_map->space), v_color_space);
	c3d_setcolor(&(p_map->empty), v_color_empty);
}

void	c3d_destroy_minimap(t_data *_data)
{
	if (_data->minimap.empty.data != NULL)
		mlx_destroy_image(_data->display.mlx, _data->minimap.empty.data);
	if (_data->minimap.player.data != NULL)
		mlx_destroy_image(_data->display.mlx, _data->minimap.player.data);
	if (_data->minimap.space.data != NULL)
		mlx_destroy_image(_data->display.mlx, _data->minimap.space.data);
	if (_data->minimap.wall.data != NULL)
		mlx_destroy_image(_data->display.mlx, _data->minimap.wall.data);
}

void	c3d_render_minimap(t_data *_data)
{
	int		i_w;
	int		i_h;
	t_image	*p_image;

	i_h = -1;
	while (++i_h < C3D_MINIMAP_HEIGHT)
	{
		i_w = -1;
		while (++i_w < C3D_MINIMAP_WIDTH)
		{
			p_image = &(_data->minimap.empty);
			if (_data->minimap.data[i_h][i_w] == C3D_MAP_WALL)
				p_image = &(_data->minimap.wall);
			else if (_data->minimap.data[i_h][i_w] == C3D_MAP_PLAYER)
				p_image = &(_data->minimap.player);
			else if (_data->minimap.data[i_h][i_w] == C3D_MAP_SPACE)
				p_image = &(_data->minimap.space);
			c3d_render_image(_data, p_image,
				i_w * C3D_IMG_WIDTH, i_h * C3D_IMAGE_HEIGHT);
		}
	}
}

void	c3d_update_minimap(t_data *_data)
{
	const int	row = (int)_data->player.position.y;
	const int	col = (int)_data->player.position.x;
	int			i_w;
	int			i_h;

	i_h = -1;
	while (++i_h < C3D_MINIMAP_HEIGHT)
	{
		i_w = -1;
		while (++i_w < C3D_MINIMAP_WIDTH)
		{
			_data->minimap.data[i_h][i_w] = c3d_getdata(&(_data->map),
					col + i_w - C3D_MINIMAP_WIDTH / 2,
					row + i_h - C3D_MINIMAP_HEIGHT / 2);
		}
	}
	_data->minimap.data[C3D_MINIMAP_HEIGHT / 2][C3D_MINIMAP_WIDTH / 2]
		= C3D_MAP_PLAYER;
	c3d_render_minimap(_data);
}
