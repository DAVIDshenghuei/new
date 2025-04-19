/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chugon <chugon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 18:02:03 by chugon            #+#    #+#             */
/*   Updated: 2024/11/09 11:11:25 by chugon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t _count, size_t _size)
{
	size_t	var_size;
	void	*ptr_ret;

	if (_count != 0 && _size > SIZE_MAX / _count)
		return (NULL);
	var_size = _count * _size;
	if (var_size == 0)
		var_size = 1;
	ptr_ret = malloc(var_size);
	if (ptr_ret != NULL)
		ft_bzero(ptr_ret, var_size);
	return (ptr_ret);
}
