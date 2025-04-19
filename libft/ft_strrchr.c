/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chugon <chugon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 10:25:40 by chugon            #+#    #+#             */
/*   Updated: 2024/11/12 08:42:46 by chugon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *_str, int _c)
{
	size_t	idx_str;

	idx_str = ft_strlen(_str);
	while (idx_str >= 0)
	{
		if (_str[idx_str] == (char)_c)
			return ((char *)_str + idx_str);
		if (idx_str == 0)
			break ;
		--idx_str;
	}
	return (NULL);
}
