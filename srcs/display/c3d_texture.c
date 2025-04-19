/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chugon <chugon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 12:07:00 by chugon            #+#    #+#             */
/*   Updated: 2025/04/12 12:55:20 by chugon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

#include "c3d_types.h"
#include "c3d_display.h"
#include "c3d_error.h"
#include "c3d_log.h"

t_error	c3d_load_textures(t_data *_data)
{
	int			i_texture;
	t_texture	*p_texture;

	i_texture = -1;
	while (++i_texture < C3D_TEXTURE_COUNT)
	{
		p_texture = &(_data->texture[i_texture]);
		c3d_log(__func__, C3D_LOG_GAME,
			"loading %s", p_texture->filename);
		p_texture->image.data = mlx_xpm_file_to_image(
				_data->display.mlx, p_texture->filename,
				&(p_texture->image.width), &(p_texture->image.height));
		if (p_texture->image.data == NULL)
			return (c3d_seterror(&(_data->error), C3D_ELOAD,
					p_texture->filename));
		p_texture->image.buffer = mlx_get_data_addr(
				p_texture->image.data, &(p_texture->image.bpp),
				&(p_texture->image.bytes), &(p_texture->image.endian));
	}
	return (_data->error);
}

void	c3d_unload_textures(t_data *_data)
{
	int	i_texture;

	i_texture = -1;
	while (++i_texture < C3D_TEXTURE_COUNT)
	{
		c3d_log(__func__, C3D_LOG_GAME,
			"unloading %s", _data->texture[i_texture].filename);
		if (_data->texture[i_texture].filename != NULL)
			free(_data->texture[i_texture].filename);
		if (_data->texture[i_texture].image.data != NULL)
			mlx_destroy_image(_data->display.mlx,
				_data->texture[i_texture].image.data);
	}
}
