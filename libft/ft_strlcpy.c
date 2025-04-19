/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chugon <chugon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:05:37 by chugon            #+#    #+#             */
/*   Updated: 2024/11/06 08:24:19 by chugon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *_dst, const char *_src, size_t _size)
{
	size_t	idx_dst;

	if (_size > 0)
	{
		idx_dst = 0;
		while ((idx_dst < _size - 1) && (_src[idx_dst] != '\0'))
		{
			_dst[idx_dst] = _src[idx_dst];
			++idx_dst;
		}
		_dst[idx_dst] = '\0';
	}
	return (ft_strlen(_src));
}
