/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chugon <chugon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:00:50 by chugon            #+#    #+#             */
/*   Updated: 2024/11/06 08:25:09 by chugon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *_str, const char *_substr, size_t _count)
{
	size_t	idx_str;
	size_t	var_len;

	if (*_substr == '\0')
		return ((char *)_str);
	var_len = ft_strlen(_substr);
	idx_str = 0;
	while (_str[idx_str] != '\0' && idx_str + var_len <= _count)
	{
		if (ft_strncmp(_str + idx_str, _substr, var_len) == 0)
			return ((char *)_str + idx_str);
		++idx_str;
	}
	return (NULL);
}
