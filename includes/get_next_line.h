/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chugon <chugon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 12:08:57 by chugon            #+#    #+#             */
/*   Updated: 2025/03/03 14:18:29 by chugon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 256
# endif

/**
 * @enum e_gnl_status
 * @brief Return code of gnl_gets() and gnl_flush() functions.
 * @var GNL_NONE No error.
 * @var GNL_ERR_MALLOC Memory allocation failed.
 * @var GNL_ERR_READ Error during reading
 * @var GNL_NEWLINE Newline character found
 * @var GNL_EOF End of File reached
 * @var GNL_BUFF_EMPTY Buffer is empty
 */
enum e_gnl_status
{
	GNL_NONE = 0,
	GNL_NEWLINE,
	GNL_BUFF_EMPTY,
	GNL_EOF,
	GNL_ERR_MALLOC,
	GNL_ERR_READ,
	GNL_UNDEFINED
};

struct s_buffer
{
	char	data[BUFFER_SIZE];
	ssize_t	nbytes;
	ssize_t	index;
};

struct s_string
{
	char	*data;
	ssize_t	size;
};

typedef struct s_gnl_data
{
	struct s_buffer	buffer;
	struct s_string	line;
}	t_gnl;

/**
 * @brief Returns the line from file descriptor specified by `fd`
 * @param fd
 */
char	*get_next_line(int fd);

#endif
