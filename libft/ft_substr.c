/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chugon <chugon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 09:04:31 by chugon            #+#    #+#             */
/*   Updated: 2024/11/06 09:54:17 by chugon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *_str, unsigned int _start, size_t _len)
{
	char	*str_retval;
	size_t	idx_retval;
	size_t	var_size;

	var_size = ft_strlen(_str);
	if (_start > var_size)
		var_size = 0;
	else
		var_size -= _start;
	if (_len < var_size)
		var_size = _len;
	str_retval = (char *)malloc(sizeof(char) * (var_size + 1));
	if (str_retval == NULL)
		return (NULL);
	idx_retval = 0;
	str_retval[0] = '\0';
	while (idx_retval < var_size)
	{
		str_retval[idx_retval] = _str[_start + idx_retval];
		++idx_retval;
	}
	str_retval[idx_retval] = '\0';
	return (str_retval);
}
