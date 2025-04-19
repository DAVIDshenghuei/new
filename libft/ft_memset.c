/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chugon <chugon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 09:04:23 by chugon            #+#    #+#             */
/*   Updated: 2024/11/05 10:22:11 by chugon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *_dst, int _c, size_t _count)
{
	size_t			idx_dst;
	unsigned char	*ptr_dst;

	ptr_dst = (unsigned char *)_dst;
	idx_dst = 0;
	while (idx_dst < _count)
	{
		ptr_dst[idx_dst] = (unsigned char)_c;
		++idx_dst;
	}
	return (_dst);
}
