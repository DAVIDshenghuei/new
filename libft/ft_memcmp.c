/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chugon <chugon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 09:04:02 by chugon            #+#    #+#             */
/*   Updated: 2024/11/09 13:22:13 by chugon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *_lhs, const void *_rhs, size_t _count)
{
	size_t			idx_cmp;
	int				var_result;
	unsigned char	*ptr_lhs;
	unsigned char	*ptr_rhs;

	var_result = 0;
	idx_cmp = 0;
	ptr_lhs = (unsigned char *)_lhs;
	ptr_rhs = (unsigned char *)_rhs;
	while (idx_cmp < _count)
	{
		var_result = (int)ptr_lhs[idx_cmp] - (int)ptr_rhs[idx_cmp];
		if (var_result != 0)
			break ;
		++idx_cmp;
	}
	return (var_result);
}
