/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_header.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chugon <chugon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 12:07:22 by chugon            #+#    #+#             */
/*   Updated: 2025/04/12 15:59:36 by chugon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

#include "c3d_parse.h"
#include "c3d_utils.h"
#include "c3d_error.h"
#include "c3d_log.h"

int	c3d_texture_getid(const char *_str)
{
	static const char	*tid[] = {
		"NO", "SO", "WE", "EA", "F", "C", NULL
	};
	int					v_id;

	v_id = -1;
	while (_str != NULL && tid[++v_id] != NULL)
	{
		if (ft_strncmp(_str, tid[v_id], ft_strlen(tid[v_id]) + 1) == 0)
			return (v_id);
	}
	return (-1);
}

unsigned char	c3d_tocolor(t_error *_error, const char *_str)
{
	static const int	size = 3;
	int					i_str;
	unsigned int		v_color;

	c3d_log(__func__, C3D_LOG_PARSE, "string: `%s`", _str);
	if (_str == NULL || (int)ft_strlen(_str) > size)
		return (c3d_seterror(_error, C3D_EFORMAT, _str), 0);
	v_color = 0;
	i_str = -1;
	while (_str[++i_str] != '\0')
	{
		if (ft_isdigit(_str[i_str]) == FT_FALSE)
			return (c3d_seterror(_error, C3D_EFORMAT, _str), 0);
		v_color = v_color * 10 + (_str[i_str] - '0');
	}
	if (v_color > UCHAR_MAX)
		return (c3d_seterror(_error, C3D_EFORMAT, _str), 0);
	return ((unsigned char)v_color);
}

t_error	c3d_parse_color(t_data *_data, int _id, char **_args)
{
	char	**s_color;

	if (_data->texture[_id].set == FT_TRUE)
		return (c3d_seterror(&(_data->error), C3D_EALREADY, _args[0]));
	s_color = ft_split(_args[1], ',');
	if (c3d_strslen(s_color) != 3)
		c3d_seterror(&(_data->error), C3D_EFORMAT, _args[1]);
	else
	{
		_data->texture[_id].color.r = c3d_tocolor(&(_data->error), s_color[0]);
		_data->texture[_id].color.g = c3d_tocolor(&(_data->error), s_color[1]);
		_data->texture[_id].color.b = c3d_tocolor(&(_data->error), s_color[2]);
		_data->texture[_id].color.a = 0;
		_data->texture[_id].set = FT_TRUE;
	}
	c3d_strsclear(s_color);
	return (C3D_ENONE);
}

t_error	c3d_parse_texture(t_data *_data, int _id, char **_args)
{
	c3d_log(__func__, C3D_LOG_PARSE, "path: %s", _args[1]);
	if (_data->texture[_id].set == FT_TRUE)
		return (c3d_seterror(&(_data->error), C3D_EALREADY, _args[0]));
	_data->texture[_id].filename = ft_strdup(_args[1]);
	_data->texture[_id].set = FT_TRUE;
	c3d_log(__func__, C3D_LOG_PARSE, "set `%s` with `%s`", _args[0], _args[1]);
	return (C3D_ENONE);
}

t_error	c3d_parse_header(t_data *_data, const char *_line)
{
	char	**s_args;
	int		v_id;

	s_args = ft_split(_line, ' ');
	if (s_args == NULL || *s_args == NULL)
		;
	else if (c3d_strslen(s_args) == 2)
	{
		v_id = c3d_texture_getid(s_args[0]);
		if (v_id < 0)
			c3d_seterror(&(_data->error), C3D_EBADID, s_args[0]);
		else if (v_id == C3D_TID_F || v_id == C3D_TID_C)
			c3d_parse_color(_data, v_id, s_args);
		else
			c3d_parse_texture(_data, v_id, s_args);
	}
	else
		c3d_seterror(&(_data->error), C3D_EFORMAT, _line);
	c3d_strsclear(s_args);
	return (_data->error);
}
