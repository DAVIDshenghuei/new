/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chugon <chugon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 12:43:08 by chugon            #+#    #+#             */
/*   Updated: 2025/04/12 15:56:21 by chugon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_types.h"
#include "c3d_display.h"
#include "c3d_log.h"

static t_tid	c3d_gettid_from_ray(t_ray *_ray)
{
	if (_ray->surface == 1)
	{
		if (_ray->ray_dir.y < 0)
			return (C3D_TID_N);
		else
			return (C3D_TID_S);
	}
	if (_ray->ray_dir.x < 0)
		return (C3D_TID_W);
	return (C3D_TID_E);
}

void	c3d_render_pixel(t_data *_data, t_color _color, int _x, int _y)
{
	int	v_addr;

	if (_x < 0 || _x > C3D_WINDOW_WIDTH
		|| _y < 0 || _y > C3D_WINDOW_HEIGHT
		|| _color.a == (char)0xFF)
		return ;
	v_addr = (_y * _data->screen.bytes) + (_x * C3D_BYTES_PER_COLOR);
	c3d_setpixel(&(_data->screen.buffer[v_addr]), _color, _data->screen.endian);
}

void	c3d_render_image(t_data *_data, t_image *_img, int _x, int _y)
{
	int		i_w;
	int		i_h;
	int		v_addr;
	t_color	v_pixel;

	i_h = -1;
	while (++i_h < _img->height)
	{
		i_w = -1;
		while (++i_w < _img->width)
		{
			v_addr = (i_h * _img->bytes) + (i_w * C3D_BYTES_PER_COLOR);
			v_pixel = c3d_getpixel(&(_img->buffer[v_addr]), _img->endian);
			c3d_render_pixel(_data, v_pixel, _x + i_w, _y + i_h);
		}
	}
}

void	c3d_render_background(t_data *_data, int _upper, int _lower, int _x)
{
	int	i_height;

	i_height = 0;
	while (i_height < _upper && i_height < C3D_WINDOW_HEIGHT)
	{
		c3d_render_pixel(_data, _data->texture[C3D_TID_C].color, _x, i_height);
		++i_height;
	}
	i_height = _lower;
	while (i_height < C3D_WINDOW_HEIGHT && i_height >= _upper)
	{
		c3d_render_pixel(_data, _data->texture[C3D_TID_F].color, _x, i_height);
		++i_height;
	}
}

void	c3d_render_texture(t_data *_data, t_ray *_ray, int _x)
{
	t_renderdata	v_render;
	int				i_height;
	t_color			v_color;

	v_render.texture = &(_data->texture[c3d_gettid_from_ray(_ray)]);
	v_render.x = (int)(_ray->wallx * v_render.texture->image.width);
	if ((_ray->surface == 0 && _ray->ray_dir.x > 0)
		|| (_ray->surface == 1 && _ray->ray_dir.y < 0))
		v_render.x = v_render.texture->image.width - v_render.x - 1;
	v_render.step = 1.0 * v_render.texture->image.height / _ray->line_height;
	v_render.pos = (_ray->draw_start - C3D_WINDOW_HEIGHT / 2
			+ _ray->line_height / 2) * v_render.step;
	c3d_render_background(_data, _ray->draw_start, _ray->draw_end, _x);
	i_height = _ray->draw_start;
	while (i_height < _ray->draw_end)
	{
		v_render.y = (int)v_render.pos & (v_render.texture->image.height - 1);
		v_render.pos += v_render.step;
		v_color = c3d_getpixel_from_image(&(v_render.texture->image),
				v_render.x, v_render.y);
		c3d_render_pixel(_data, v_color, _x, i_height);
		++i_height;
	}
}
