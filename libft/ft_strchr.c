/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chugon <chugon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 09:02:40 by chugon            #+#    #+#             */
/*   Updated: 2024/11/05 13:32:06 by chugon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *_str, int _c)
{
	while (*_str != '\0')
	{
		if (*_str == (char)_c)
			return ((char *)_str);
		++_str;
	}
	if (_c == '\0')
		return ((char *)_str);
	return (NULL);
}
