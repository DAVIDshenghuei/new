/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chugon <chugon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 09:04:08 by chugon            #+#    #+#             */
/*   Updated: 2024/11/05 10:43:07 by chugon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *_dst, const void *_src, size_t _count)
{
	size_t			idx_dst;
	unsigned char	*ptr_dst;

	ptr_dst = (unsigned char *)_dst;
	idx_dst = 0;
	while (idx_dst < _count)
	{
		ptr_dst[idx_dst] = ((unsigned char *)_src)[idx_dst];
		++idx_dst;
	}
	return (_dst);
}
