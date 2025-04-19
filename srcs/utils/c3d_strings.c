/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_strings.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chugon <chugon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 12:07:53 by chugon            #+#    #+#             */
/*   Updated: 2025/02/27 12:07:53 by chugon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	c3d_strslen(char **_array)
{
	size_t	v_len;

	if (_array == NULL)
		return ((size_t)0);
	v_len = 0;
	while (_array[v_len] != NULL)
		++v_len;
	return (v_len);
}

char	**c3d_strsclear(char **_array)
{
	size_t	i_array;

	i_array = 0;
	while (_array != NULL && _array[i_array] != NULL)
	{
		free(_array[i_array]);
		_array[i_array] = NULL;
		++i_array;
	}
	free(_array);
	return (NULL);
}

char	**c3d_strscat(char **_array, const char *_str)
{
	char	**s_retval;
	size_t	v_size;
	size_t	i_array;

	if (_str == NULL)
		return (_array);
	v_size = c3d_strslen(_array);
	s_retval = (char **)malloc(sizeof(char *) * (v_size + 2));
	if (s_retval == NULL)
		return (NULL);
	i_array = 0;
	while (i_array < v_size)
	{
		s_retval[i_array] = _array[i_array];
		++i_array;
	}
	s_retval[v_size] = (char *)_str;
	s_retval[v_size + 1] = NULL;
	free(_array);
	return (s_retval);
}

char	**c3d_strsmerge(char **_head, char **_tail)
{
	char	**s_retval;
	int		v_hsize;
	int		v_tsize;
	int		i_array;

	if (_head == NULL)
		return (_tail);
	else if (_tail == NULL)
		return (_head);
	v_hsize = (int)c3d_strslen(_head);
	v_tsize = (int)c3d_strslen(_tail);
	s_retval = (char **)malloc(sizeof(char *) * (v_hsize + v_tsize + 1));
	if (s_retval == NULL)
		return (NULL);
	i_array = -1;
	while (++i_array < v_hsize)
		s_retval[i_array] = _head[i_array];
	i_array = -1;
	while (++i_array < v_tsize)
		s_retval[v_hsize + i_array] = _tail[i_array];
	s_retval[v_hsize + v_tsize] = NULL;
	return (free(_head), free(_tail), s_retval);
}
