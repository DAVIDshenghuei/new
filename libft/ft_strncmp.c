/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chugon <chugon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 10:19:33 by chugon            #+#    #+#             */
/*   Updated: 2024/11/05 13:02:18 by chugon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *_lhs, const char *_rhs, size_t _count)
{
	size_t			idx_str;
	unsigned char	*str_lhs;
	unsigned char	*str_rhs;

	idx_str = 0;
	str_lhs = (unsigned char *)_lhs;
	str_rhs = (unsigned char *)_rhs;
	while (idx_str < _count)
	{
		if (str_lhs[idx_str] == '\0' || str_lhs[idx_str] != str_rhs[idx_str])
			return ((int)str_lhs[idx_str] - (int)str_rhs[idx_str]);
		++idx_str;
	}
	return (0);
}
