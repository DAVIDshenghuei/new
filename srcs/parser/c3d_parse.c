/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chugon <chugon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 12:07:32 by chugon            #+#    #+#             */
/*   Updated: 2025/02/27 12:07:33 by chugon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>

#include "c3d_parse.h"
#include "c3d_error.h"
#include "c3d_log.h"
#include "c3d_game.h"
#include "c3d_utils.h"

#define C3D_FILE_EXTENSION ".cub"
#define C3D_FILE_EXTENSION_SIZE 4

t_bool	c3d_is_header_complet(t_data *_data)
{
	int	v_tid;

	v_tid = -1;
	while (++v_tid < C3D_TOTAL_COUNT)
	{
		if (_data->texture[v_tid].set == FT_FALSE)
			return (FT_FALSE);
	}
	return (FT_TRUE);
}

void	c3d_file_check(t_data *_data, const char *_filename)
{
	const char	*s_ext;
	size_t		v_length;

	c3d_log(__func__, C3D_LOG_PARSE, "filename: %s", _filename);
	if (_filename == NULL)
		c3d_exit(_data, C3D_EFILE, "null");
	v_length = ft_strlen(_filename);
	if (v_length <= C3D_FILE_EXTENSION_SIZE)
		c3d_exit(_data, C3D_EFILE, _filename);
	s_ext = _filename + v_length - C3D_FILE_EXTENSION_SIZE;
	if (ft_strncmp(s_ext, C3D_FILE_EXTENSION, C3D_FILE_EXTENSION_SIZE + 1))
		c3d_exit(_data, C3D_EFILE, _filename);
}

t_error	c3d_read_file(t_data *_data, int _fd)
{
	char	*s_line;
	char	*s_trim;

	(void)_data;
	while (FT_TRUE)
	{
		s_line = get_next_line(_fd);
		if (s_line == NULL)
			break ;
		s_trim = ft_strtrim(s_line, " \n");
		c3d_log(__func__, C3D_LOG_PARSE, "read line: `%s`", s_trim);
		if (c3d_is_header_complet(_data) == FT_FALSE)
			c3d_parse_header(_data, s_trim);
		else
			c3d_parse_map(_data, s_line);
		free(s_trim);
		free(s_line);
		if (_data->error != C3D_ENONE)
			c3d_exit(_data, C3D_EPARSE, NULL);
	}
	return (C3D_ENONE);
}

void	c3d_parse(t_data *_data, const char *_filename)
{
	int	v_fd;

	c3d_file_check(_data, _filename);
	v_fd = open(_filename, O_RDONLY);
	if (v_fd < 0)
		c3d_exit(_data, C3D_ESYSTEM, _filename);
	c3d_read_file(_data, v_fd);
	if (close(v_fd) < 0)
		c3d_exit(_data, C3D_ESYSTEM, _filename);
	if (_data->error != C3D_ENONE || c3d_map_data(_data) != C3D_ENONE)
		c3d_exit(_data, C3D_EMAP, NULL);
}
