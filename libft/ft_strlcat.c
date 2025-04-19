/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chugon <chugon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:12:12 by chugon            #+#    #+#             */
/*   Updated: 2024/11/06 08:22:22 by chugon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *_dst, const char *_src, size_t _size)
{
	size_t	var_size_dst;
	size_t	var_size_src;
	size_t	idx_src;

	var_size_dst = ft_strlen(_dst);
	var_size_src = ft_strlen(_src);
	if (_size <= var_size_dst)
		return (var_size_src + _size);
	idx_src = 0;
	while ((_src[idx_src] != '\0') && ((var_size_dst + idx_src) < (_size - 1)))
	{
		_dst[var_size_dst + idx_src] = _src[idx_src];
		++idx_src;
	}
	_dst[var_size_dst + idx_src] = '\0';
	return (var_size_src + var_size_dst);
}
