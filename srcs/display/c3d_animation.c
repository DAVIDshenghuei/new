/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_animation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chugon <chugon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 13:45:45 by chugon            #+#    #+#             */
/*   Updated: 2025/04/12 13:37:27 by chugon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

#include "c3d_display.h"
#include "c3d_error.h"
#include "c3d_log.h"

/// Duration for a single frame in us
#define C3D_FRAME_DURATION 20000

char	*c3d_getfilename(int _index)
{
	static char *const	names[] = {
		"assets/animation/anim-01.xpm", "assets/animation/anim-02.xpm",
		"assets/animation/anim-03.xpm", "assets/animation/anim-04.xpm",
		"assets/animation/anim-05.xpm", "assets/animation/anim-06.xpm",
		"assets/animation/anim-07.xpm", "assets/animation/anim-08.xpm",
		"assets/animation/anim-09.xpm", "assets/animation/anim-10.xpm",
		"assets/animation/anim-11.xpm", "assets/animation/anim-12.xpm",
		"assets/animation/anim-13.xpm", "assets/animation/anim-14.xpm",
		"assets/animation/anim-15.xpm", "assets/animation/anim-16.xpm",
		"assets/animation/anim-17.xpm", "assets/animation/anim-18.xpm",
		"assets/animation/anim-19.xpm", "assets/animation/anim-20.xpm",
	};

	if (_index < 0 || _index >= C3D_FRAME_COUNT)
		return (NULL);
	return (names[_index]);
}

t_error	c3d_create_animation(t_data *_data)
{
	t_image	*p_frame;
	char	*s_name;
	int		i_frame;

	i_frame = -1;
	while (++i_frame < C3D_FRAME_COUNT)
	{
		c3d_log(__func__, C3D_LOG_IMAGE, "creating frame %d", i_frame);
		s_name = c3d_getfilename(i_frame);
		p_frame = &(_data->animation.frames[i_frame]);
		p_frame->data = mlx_xpm_file_to_image(_data->display.mlx, s_name,
				&(p_frame->width), &(p_frame->height));
		p_frame->buffer = mlx_get_data_addr(p_frame->data,
				&(p_frame->bpp), &(p_frame->bytes), &(p_frame->endian));
		if (p_frame->data == NULL)
			return (c3d_seterror(&(_data->error), C3D_ELOAD, s_name));
	}
	return (_data->error);
}

t_error	c3d_destroy_animation(t_data *_data)
{
	t_image	*p_frame;
	int		i_frame;

	i_frame = -1;
	while (++i_frame < C3D_FRAME_COUNT)
	{
		c3d_log(__func__, C3D_LOG_IMAGE, "destroying frame %d", i_frame);
		p_frame = &(_data->animation.frames[i_frame]);
		if (p_frame->data != NULL)
			mlx_destroy_image(_data->display.mlx, p_frame->data);
	}
	return (C3D_ENONE);
}

void	c3d_update_animation(t_data *_data, long _elapsed)
{
	if (_data->animation.show == FT_FALSE)
		return ;
	_data->animation.duration += _elapsed;
	c3d_render_image(_data, &(_data->animation.frames[_data->animation.index]),
		_data->animation.x, _data->animation.y);
	if (_data->animation.duration > C3D_FRAME_DURATION)
	{
		_data->animation.duration = 0L;
		if (++_data->animation.index >= C3D_FRAME_COUNT)
			_data->animation.show = FT_FALSE;
	}
	_data->update = FT_TRUE;
}
