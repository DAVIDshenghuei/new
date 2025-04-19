/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chugon <chugon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 09:04:16 by chugon            #+#    #+#             */
/*   Updated: 2024/11/05 10:42:37 by chugon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *_dst, const void *_src, size_t _count)
{
	size_t			idx_count;
	unsigned char	*ptr_dst;
	unsigned char	*ptr_src;

	if (_dst == _src)
		return (_dst);
	ptr_dst = (unsigned char *)_dst;
	ptr_src = (unsigned char *)_src;
	idx_count = 0;
	while (idx_count < _count)
	{
		if (_dst < _src)
			ptr_dst[idx_count] = ptr_src[idx_count];
		else
			ptr_dst[_count - 1 - idx_count] = ptr_src[_count - 1 - idx_count];
		++idx_count;
	}
	return (_dst);
}
