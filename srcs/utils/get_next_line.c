/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chugon <chugon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:29:47 by chugon            #+#    #+#             */
/*   Updated: 2025/02/27 12:08:09 by chugon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "get_next_line.h"

/**
 * Reads up to `BUFFER_SIZE` data from the file descriptor `fd` and stores them
 * in the field `buffer.data` of `gnl`.
 *
 * @return An error code is returned.
 * @see e_gnl_error
 */
static int		gnl_gets(t_gnl *gnl, int fd);

/**
 * Flush the buffer to field `line` of `gnl` until the newline character `'\n'`
 * is found or reached `BUFFER_SIZE`.
 *
 * @return An error code is returned.
 * @see e_gnl_error
 */
static int		gnl_flush(t_gnl *gnl);

/**
 * Searches for the newline character `\n` and returns its position.
 *
 * @return Returns the position of the newline character or
 * `buffer.nbytes` if the newline character is not found.
 */
static ssize_t	gnl_nlchr(struct s_buffer *buffer);

/*
 * Copies the content of `line.data` into the `dst`, and then appends `size`
 * bytes of `buffer.data` starting from `buffer.index`.
 */
static void		gnl_copy(t_gnl *gnl, char *dst, ssize_t size);

char	*get_next_line(int _fd)
{
	static t_gnl	var_gnl;
	int				var_code;

	var_code = GNL_NONE;
	if (_fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	var_gnl.line.data = NULL;
	var_gnl.line.size = 0;
	while (var_code == GNL_NONE)
		var_code = gnl_gets(&var_gnl, _fd);
	if (var_code == GNL_ERR_MALLOC || var_code == GNL_ERR_READ)
	{
		free(var_gnl.line.data);
		var_gnl.line.data = NULL;
		var_gnl.line.size = 0;
		var_gnl.buffer.nbytes = 0;
	}
	return (var_gnl.line.data);
}

int	gnl_gets(t_gnl *_gnl, int _fd)
{
	int	var_code;

	var_code = gnl_flush(_gnl);
	if (var_code != GNL_NONE)
		return (var_code);
	_gnl->buffer.index = 0;
	_gnl->buffer.nbytes = read(_fd, _gnl->buffer.data, BUFFER_SIZE);
	if (_gnl->buffer.nbytes == 0)
		return (GNL_EOF);
	if (_gnl->buffer.nbytes < 0)
		return (GNL_ERR_READ);
	return (GNL_NONE);
}

int	gnl_flush(t_gnl *_gnl)
{
	char	*str_line;
	ssize_t	var_size;

	if (_gnl->buffer.index >= _gnl->buffer.nbytes)
		return (GNL_NONE);
	var_size = gnl_nlchr(&(_gnl->buffer)) - _gnl->buffer.index;
	str_line = (char *)malloc(sizeof(char) * (_gnl->line.size + var_size + 1));
	if (str_line == NULL)
		return (GNL_ERR_MALLOC);
	gnl_copy(_gnl, str_line, var_size);
	_gnl->buffer.index += var_size;
	if (_gnl->line.size > 0 && _gnl->line.data[_gnl->line.size - 1] == '\n')
		return (GNL_NEWLINE);
	return (GNL_NONE);
}

void	gnl_copy(t_gnl *_gnl, char *_dst, ssize_t _size)
{
	ssize_t	idx_line;

	idx_line = -1;
	while (++idx_line < _gnl->line.size + _size)
	{
		if (idx_line < _gnl->line.size)
			_dst[idx_line] = _gnl->line.data[idx_line];
		else
			_dst[idx_line] = _gnl->buffer.data[idx_line
				- _gnl->line.size + _gnl->buffer.index];
	}
	_dst[idx_line] = '\0';
	free(_gnl->line.data);
	_gnl->line.data = _dst;
	_gnl->line.size += _size;
}

ssize_t	gnl_nlchr(struct s_buffer *_buffer)
{
	ssize_t	idx_buffer;

	idx_buffer = _buffer->index;
	while (idx_buffer < _buffer->nbytes)
	{
		if (_buffer->data[idx_buffer] == '\n')
			return (idx_buffer + 1);
		++idx_buffer;
	}
	return (_buffer->nbytes);
}
