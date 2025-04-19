/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chugon <chugon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 12:07:04 by chugon            #+#    #+#             */
/*   Updated: 2025/04/12 13:36:06 by chugon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

#include "c3d_types.h"
#include "c3d_display.h"
#include "c3d_log.h"

long	c3d_elapsed(t_fps *_prev)
{
	t_fps	v_now;
	long	v_elapsed;

	gettimeofday(&v_now, NULL);
	v_elapsed = (v_now.tv_sec - _prev->tv_sec) * 1000000L
		+ v_now.tv_usec - _prev->tv_usec;
	return (v_elapsed);
}

int	c3d_update_window(t_data *_data)
{
	const long	elapsed = c3d_elapsed(&(_data->fps));

	if (_data->update == FT_FALSE)
		return (EXIT_SUCCESS);
	_data->update = FT_FALSE;
	c3d_raycasting(_data);
	c3d_update_minimap(_data);
	c3d_update_animation(_data, elapsed);
	mlx_put_image_to_window(_data->display.mlx, _data->display.window,
		_data->screen.data, 0, 0);
	gettimeofday(&(_data->fps), NULL);
	return (EXIT_SUCCESS);
}
