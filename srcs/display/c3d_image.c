/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chugon <chugon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 12:06:54 by chugon            #+#    #+#             */
/*   Updated: 2025/04/12 15:51:59 by chugon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include <mlx.h>

#include "c3d_display.h"
#include "c3d_error.h"

#define C3D_BIG_ENDIAN 1

t_color	c3d_getpixel(const char _buffer[], int _endian)
{
	t_color	v_color;

	if (_endian == C3D_BIG_ENDIAN)
	{
		v_color.b = _buffer[3];
		v_color.g = _buffer[2];
		v_color.r = _buffer[1];
		v_color.a = _buffer[0];
	}
	else
	{
		v_color.b = _buffer[0];
		v_color.g = _buffer[1];
		v_color.r = _buffer[2];
		v_color.a = _buffer[3];
	}
	return (v_color);
}

void	c3d_setpixel(char _buffer[], t_color _color, int _endian)
{
	if (_endian == C3D_BIG_ENDIAN)
	{
		_buffer[0] = _color.a;
		_buffer[1] = _color.r;
		_buffer[2] = _color.g;
		_buffer[3] = _color.b;
	}
	else
	{
		_buffer[0] = _color.b;
		_buffer[1] = _color.g;
		_buffer[2] = _color.r;
		_buffer[3] = _color.a;
	}
}

t_error	c3d_create_image(t_data *_data, t_image *_img, int _w, int _h)
{
	_img->width = _w;
	_img->height = _h;
	_img->data = mlx_new_image(_data->display.mlx, _w, _h);
	if (_img->data == NULL)
		return (c3d_seterror(&(_data->error), C3D_EMLX, "new image"));
	_img->buffer = mlx_get_data_addr(_img->data,
			&(_img->bpp), &(_img->bytes), &(_img->endian));
	if (_img->buffer == NULL)
		return (c3d_seterror(&(_data->error), C3D_EMLX, "get data addr"));
	return (C3D_ENONE);
}

void	c3d_setcolor(t_image *_img, t_color _color)
{
	int	i_w;
	int	i_h;
	int	v_pixel;

	i_h = -1;
	while (++i_h < _img->height)
	{
		i_w = -1;
		while (++i_w < _img->width)
		{
			v_pixel = (i_h * _img->bytes) + (i_w * C3D_BYTES_PER_COLOR);
			c3d_setpixel(&(_img->buffer[v_pixel]), _color, _img->endian);
		}
	}
}

t_color	c3d_getpixel_from_image(t_image *_img, int _x, int _y)
{
	int		v_addr;

	v_addr = (_y * _img->bytes) + (_x * C3D_BYTES_PER_COLOR);
	return (c3d_getpixel(&(_img->buffer[v_addr]), _img->endian));
}
