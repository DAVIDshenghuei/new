/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chugon <chugon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 02:03:56 by chugon            #+#    #+#             */
/*   Updated: 2024/08/06 02:10:15 by chugon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *ptr, int c, size_t count)
{
	size_t			i;
	unsigned char	*ret;

	i = 0;
	ret = (unsigned char *)ptr;
	while (i < count)
	{
		if (ret[i] == (unsigned char)c)
			return ((void *)&ret[i]);
		++i;
	}
	return (NULL);
}
